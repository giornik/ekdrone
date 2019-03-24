#define MOTOR_PIN1 3
#define MOTOR_PIN2 4
#define MOTOR_PIN3 5
#define MOTOR_PIN4 6
#define DELAY 8000
#include<Servo.h>

Servo esc[4];
int minSpeed = 1000;
int maxSpeed = 2000;
int Speed;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(MOTOR_PIN1, OUTPUT);
  digitalWrite(MOTOR_PIN1,LOW); // make sure there is no Voltage ouput to the pin
  esc[0].attach(MOTOR_PIN1);

  pinMode(MOTOR_PIN2, OUTPUT);
  digitalWrite(MOTOR_PIN2,LOW); // make sure there is no Voltage ouput to the pin
  esc[1].attach(MOTOR_PIN2);

  pinMode(MOTOR_PIN3, OUTPUT);
  digitalWrite(MOTOR_PIN3,LOW); // make sure there is no Voltage ouput to the pin
  esc[2].attach(MOTOR_PIN3);

  pinMode(MOTOR_PIN4, OUTPUT);
  digitalWrite(MOTOR_PIN4,LOW); // make sure there is no Voltage ouput to the pin
  esc[3].attach(MOTOR_PIN4);

  
  for (int i=0; i<4; i++){
    motorSpeed(esc[i],minSpeed); //esc.writeMicroseconds(minSpeed);
  }
  delay(5000);
  delay(DELAY);
  for (int i=0; i<4; i++){
    motorSpeed(esc[i],maxSpeed); 
  } 
  delay(DELAY);
  for (int i=0; i<4; i++){
    motorSpeed(esc[i],minSpeed); //esc.writeMicroseconds(minSpeed);
  }
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
  for (int i=0; i<4; i++){
    motorSpeed(esc[i],sp); 
  }
  delay(1000);

  sp+=50;
  if(sp>1500) sp=1150;
  
  delay(500);
 
}
void motorSpeed(Servo &esc, int sped) 
{
  if (minSpeed > sped){
    sped = minSpeed;
  }
  if (maxSpeed < sped){
      sped = maxSpeed;
  }
  esc.writeMicroseconds(sped);
}


