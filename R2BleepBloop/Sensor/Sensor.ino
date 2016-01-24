#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M3 and M4
Adafruit_DCMotor *Head = AFMS.getMotor(3);
Adafruit_DCMotor *Left = AFMS.getMotor(1);
Adafruit_DCMotor *Right = AFMS.getMotor(4);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);


void setup() {
  
  pinMode (2,OUTPUT);//attach pin 2 to vcc
  pinMode (5,OUTPUT);//attach pin 5 to GND
  // initialize serial communication:
  
  Serial.begin(9600); // set up Serial library at 9600  ( can send info back to computer)
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
   Right->setSpeed(255);
  Right->run(FORWARD);
  // turn on motor
  Right->run(RELEASE);
  
  Head->setSpeed(255);
  Head->run(FORWARD);
  // turn on motor
  Head->run(RELEASE);
}



void loop() {
  

  
  
  
digitalWrite(2, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(3, OUTPUT);// attach pin 3 to Trig
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(5);
  digitalWrite(3, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (4, INPUT);//attach pin 4 to Echo
  duration = pulseIn(4, HIGH);

  // convert the time into a distance
 inches = duration / 74 / 2;
  
 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.println();
 
  



  if (inches < 15){
     Serial.print("decide   ");
   Left->setSpeed(0);  //set speed to 200 cant be above 250
   Right->setSpeed(0);  //set speed to 200 cant be above 250  
   Head->setSpeed(100);  //set speed to 200 cant be above 250
   
   Head ->run(FORWARD);//move 1/3 part 1
   delay(1000);// 1 second = 1000
   Head->setSpeed(0); 
   delay(1000);// 1 second = 1000
   
  
   Head ->run(FORWARD);//move 1/3 part 2
   delay(1000);// 1 second = 1000
   Head->setSpeed(0); 
   delay(1000);// 1 second = 1000

   
   Head ->run(FORWARD);//move 1/3 part 3
   delay(1000);// 1 second = 1000
   Head->setSpeed(0); 
   delay(1000);// 1 second = 1000
   
   Right->run(FORWARD);
   Left->run(BACKWARD);
   Left->setSpeed(200);  //set speed to 200 cant be above 250
   Right->setSpeed(200);  //set speed to 200 cant be above 250
   delay(1000);// 1 second = 1000
  }
  else {
     Serial.print("foward ");
   Right->run(FORWARD);
   Left->run(FORWARD);
   Left->setSpeed(200);  //set speed to 200 cant be above 250
   Right->setSpeed(200);  //set speed to 200 cant be above 250
   delay(1000);// 1 second = 1000
  }
  delay(1000);
  
}

