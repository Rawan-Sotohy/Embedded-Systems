const int g_led =2;
const int y_led =3;
const int r_led =4;
const int sensor =A0;
const int fan =9;

int sensorValue = 0;        // 0 1023 value read from the pot
int outputValue = 0;        // 0 255 value output to the PWM (analog out)

void setup() {
  pinMode (g_led,OUTPUT);
  pinMode (y_led,OUTPUT);
  pinMode (r_led,OUTPUT);
  pinMode (fan,OUTPUT);
  pinMode (sensor,INPUT);


  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(sensor);
  outputValue = (int)(sensorValue/1023.0*255);
  // map it to the range of the analog out:
  // change the analog out value:
  analogWrite(fan, outputValue);


  if(sensorValue>=512){
    digitalWrite(r_led,HIGH);
    digitalWrite(g_led,LOW);
    digitalWrite(y_led,LOW);
  }
  else if(sensorValue>=300&&sensorValue<512){
    digitalWrite(y_led,HIGH);
    digitalWrite(g_led,LOW);
    digitalWrite(r_led,LOW);
  }

  else if(sensorValue<300){
    digitalWrite(g_led,HIGH);
    digitalWrite(r_led,LOW);
    digitalWrite(y_led,LOW);
  }


  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
