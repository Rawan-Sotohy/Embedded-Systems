const int redLED = A5;
const int yellowLED = A4;
const int greenLED = A3 ; 
const int button = 5;
enum TrafficState {RED, YELLOW, GREEN};

bool req = false;
unsigned long prevMillis = 0;
unsigned long crntMillis = 0;
TrafficState crntState = GREEN;
long crntInterval;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  crntMillis = millis();
  
  if(digitalRead(button) == LOW) req = true;

  switch(crntState){
    case GREEN:
      digitalWrite(greenLED,HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
      crntInterval=8000;

      if(crntMillis - prevMillis >= crntInterval){
        prevMillis = crntMillis;
        crntState = YELLOW;
      }

      break;

    case YELLOW:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
      crntInterval=2000;

      if(crntMillis - prevMillis >= crntInterval){
        prevMillis = crntMillis;
        crntState = RED;
      }

      break;

    case RED:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
      if(req==true) crntInterval=9000;
      else crntInterval=5000;

      if(crntMillis - prevMillis >= crntInterval){
        prevMillis = crntMillis;
        crntState = GREEN;
        req=false;
      }
      
      break;
  }
}
