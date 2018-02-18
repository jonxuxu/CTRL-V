#include <Servo.h>

const int trig = 9;
const int echo = 10;
Servo servo1;
Servo servo2;
int pos = 0;

long duration;
int distance;
int cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo1.attach(3);
  servo2.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x <= 180; x ++){
    cm = ping();
    Serial.print(cm); // Distance in cm
    Serial.print(',');
    Serial.println(2*x); // Base position in degrees
    servo1.write(x);
    servo2.write(x);
    delay(15);
  }
  for (int x = 180; x >= 0; x --){
    cm = ping();
    Serial.print(cm); // Distance in cm
    Serial.print(',');
    Serial.println(2*x); // Base position in degrees
    servo1.write(x);
    servo2.write(x);
    delay(15);
  }

  Serial.println("End");
  
  while (true) {
    
  }
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 /2;
}

int ping() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = microsecondsToCentimeters(duration);

  return distance;
}

