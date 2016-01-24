#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M3 and M4
Adafruit_DCMotor *Left = AFMS.getMotor(3);
Adafruit_DCMotor *Right = AFMS.getMotor(4);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600); // set up Serial library at 9600  ( can send info back to computer)
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  Left->setSpeed(255);
  Left->run(FORWARD);
  // turn on motor
  Left->run(RELEASE);
  
  Right->setSpeed(255);
  Right->run(FORWARD);
  // turn on motor
  Right->run(RELEASE);
}



void loop() {
 
   uint8_t i;
  Serial.print("tick");
   Right->run(BACKWARD);
   Left->run(BACKWARD);
   Left->setSpeed(200);  //set speed to 200 cant be above 250
   Right->setSpeed(200);  //set speed to 200 cant be above 250
   delay(10000);// 1 second = 1000
   
 
 
  Right->run(FORWARD);
  Left->run(BACKWARD);
  for (i=200; i<255; i++) {  //(i)speed starts out at 200 in  (i = 200) 
    Left->setSpeed(i);           // sets (i)spead to not go over 255 in  (i<255)    
    Right->setSpeed(i);              // sets (i)spead to increse by 1 every delay  (i++) 
    delay(100);                          //(i+5)(i)spead goes up by 5 
  }                                          // aka i=200/ delay(100)/ +5/ i=205 /delay(100)/ +5/ i=210
  
                                                  
  Serial.print("tock");
  
   Right->run(BACKWARD);
   Left->run(BACKWARD);
  for (i=255; i!=0; i--) {  //(i)speed starts out at 255 in  (i = 255) 
    Left->setSpeed(i);          // sets (i)spead to stop at 0 (i!=0) 
    Right->setSpeed(i);            // sets (i)spead to decrease by 1 every delay  (i--) 
      delay(100);                      //(i-5)(i)spead goes down by 5 every delay
  }                                        // aka i=255/ delay(100)/ -5/ i=250 /delay(100)/ -5/ i=250
  
 

  Serial.print("tech");
  Left->run(RELEASE);
  delay(1000);
}

