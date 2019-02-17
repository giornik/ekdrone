#define MOTOR_PIN 3
#define DELAY 8000
#include<Servo.h>

Servo esc;
int minSpeed = 1000;
int maxSpeed = 2000;
int Speed;


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN,LOW); // make sure there is no Voltage ouput to the pin
  esc.attach(MOTOR_PIN);
  esc.writeMicroseconds(maxSpeed);
  delay(5000);
  delay(DELAY);
  esc.writeMicroseconds(minSpeed);
  delay(DELAY);
  esc.writeMicroseconds(maxSpeed);
  delay(DELAY);
  esc.writeMicroseconds(minSpeed);
  delay(DELAY);

  esc.writeMicroseconds(1100);
  delay(1000);
  esc.writeMicroseconds(1500);
  delay(1000);  
  esc.writeMicroseconds(1100);
  delay(1000);
  esc.writeMicroseconds(minSpeed);
  delay(1000);

  /*
  for (Speed = minSpeed; Speed <1500; Speed++){
        esc.writeMicroseconds(Speed);
        delay(10);
     }
  for (Speed = 1500; Speed >minSpeed; Speed--){
    esc.writeMicroseconds(Speed);
    delay(10);
  }*/
  
  
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
