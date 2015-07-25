// Robot cleaner sample code.
// copyright PICALABO, 2015

#include <AFMotor.h>

AF_DCMotor motorR(3);
AF_DCMotor motorL(4);
#define OFF 1
#define ON  0

// Variables will change:
int sw_get = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Robot Cleaner!");
  pinMode(13, INPUT_PULLUP);
}

// Main loop 
void loop() {
  sw_get = digitalRead(13);
  if (sw_get == OFF){
    motorR.run(FORWARD);
    motorR.setSpeed(255); 
    motorL.run(FORWARD);
    motorL.setSpeed(255);
  } else {
    motorR.run(BACKWARD);
    motorR.setSpeed(255); 
    motorL.run(BACKWARD);
    motorL.setSpeed(255);
    delay(1000);
    /*
    motorR.run(FORWARD);
    motorR.setSpeed(255); 
    motorL.run(BACKWARD);
    motorL.setSpeed(255);
    delay(5000);
    */
  }

}
