#include <Servo.h>

const int trig = 9;
const int echo = 10;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int pos = 0;
int turn = 0;

long duration;
int distance;
int cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo3.attach(6);
  servo4.attach(7);
  servo3.write(80);
  servo4.write(100);
  delay(500);

  servo1.attach(3);
  servo2.attach(5);
  servo1.write(0);
  servo2.write(0);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 90; i >= 0; i -= 5){

    servo3.write(180-i);
    servo4.write(i);
    
    delay(500);
    
    if (turn%2 == 0){
      for (int x = 0; x <= 180; x += 5){
        cm = ping();
        Serial.print(cm); // Distance in cm
        Serial.print(',');
        Serial.print(2*x); // Base position in degrees
        Serial.print(',');
        Serial.println(i-10); // Side agle position in degrees
        servo1.write(x);
        servo2.write(x);
        delay(150);
      }
    }
    else {   
      for (int x = 180; x >= 0; x -= 5){
        cm = ping();
        Serial.print(cm); // Distance in cm
        Serial.print(',');
        Serial.print(2*x); // Base position in degrees
        Serial.print(',');
        Serial.println(i); // Side agle position in degrees
        servo1.write(x);
        servo2.write(x);
        delay(150);
      }
    }   
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

