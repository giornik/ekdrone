#define MOTOR_PIN 3
#define DELAY 8000
#include<Servo.h>

Servo esc;
int minSpeed = 1000;
int maxSpeed = 2000;
int Speed;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN,LOW); // make sure there is no Voltage ouput to the pin
  esc.attach(MOTOR_PIN);
  esc.writeMicroseconds(minSpeed);
  delay(5000);
  delay(DELAY);
  esc.writeMicroseconds(maxSpeed);
  delay(DELAY);
  esc.writeMicroseconds(minSpeed);
  delay(DELAY);
  


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
int sp =1150;
void loop() {
  Serial.println(sp);
  esc.writeMicroseconds(sp);
  delay(1000);

  sp+=50;
  if(sp>1500) sp=1150;
  
  esc.writeMicroseconds(minSpeed);
  delay(10000);

}
