#include <avr/interrupt.h>

// Pin definitions
const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
const int LED_PIN = 13;

// Global volatile variables
volatile enum {
    WAITING_FOR_RISING,
    WAITING_FOR_FALLING,
    MEASUREMENT_COMPLETE
} echo_state = WAITING_FOR_RISING;

volatile uint16_t start_time_low = 0;
volatile uint16_t end_time_low = 0;
volatile bool measurement_ready = false;

// For simulation testing - simulates object distance
int simulated_distance_cm = 30;

void setup() {
    Serial.begin(115200);
    Serial.println(" === Non-blocking Ultrasonic System === ");

    // Configure pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    // Setup Timer1 with prescaler 8 (2MHz clock, 0.5us resolution)
    cli();
    TCCR1A = 0;
    TCCR1B = (1 << CS11); // Prescaler 8
    TCNT1 = 0;

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    // Enable pin change interrupt on ECHO_PIN
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT0);

    sei();

    Serial.println("System initialized. Send 'd <cm>' to set distance");
}

ISR(TIMER1_OVF_vect) {
    // Overflow counter if needed
}

ISR(PCINT0_vect) {
    uint8_t echo_val = (PINB & (1 << PB0)) ? HIGH : LOW;

    switch(echo_state) {
        case WAITING_FOR_RISING:
            if (echo_val == HIGH) {
                start_time_low = TCNT1;
                echo_state = WAITING_FOR_FALLING;
            }
            break;

        case WAITING_FOR_FALLING:
            if (echo_val == LOW) {
                end_time_low = TCNT1;
                echo_state = MEASUREMENT_COMPLETE;
                measurement_ready = true;
            }
            break;

        default:
            break;
    }
}

void send_trigger() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
}

void loop() {
    // Send trigger pulse every 100ms
    static unsigned long last_trigger = 0;
    if (millis() - last_trigger > 100) {
        send_trigger();
        last_trigger = millis();

        // Reset measurement state
        echo_state = WAITING_FOR_RISING;
    }

    // Blink LED to show system responsiveness
    static unsigned long last_blink = 0;
    if (millis() - last_blink > 100) { // 10Hz blink
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        last_blink = millis();
    }

    // Process completed measurements
    if (measurement_ready) {
        cli(); // Disable interrupts for atomic read
        uint16_t start = start_time_low;
        uint16_t end = end_time_low;
        sei();

        // Calculate pulse duration in timer ticks
        uint32_t duration_ticks;
        if (end >= start) {
            duration_ticks = end - start;
        } else {
            // Timer overflow occurred during pulse
            duration_ticks = (65535 - start) + end;
        }

        // Convert ticks to microseconds
        float duration_us = duration_ticks * 0.5;

        // Calculate distance (cm)
        float distance_cm = duration_us * 0.0343 / 2;

        // In simulation, compare with expected value
        float error = abs(distance_cm - simulated_distance_cm);

        Serial.print("Measured: ");
        Serial.print(distance_cm);
        Serial.print(" cm | Expected: ");
        Serial.print(simulated_distance_cm);
        Serial.print(" cm | Error: ");
        Serial.print(error);
        Serial.println(" cm");

        measurement_ready = false;
    }

    // Check for serial commands to change simulated distance
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        if (command.startsWith("d ")) {
            simulated_distance_cm = command.substring(2).toInt();
            Serial.print("Simulated distance set to: ");
            Serial.print(simulated_distance_cm);
            Serial.println(" cm");
        }
    }
}
