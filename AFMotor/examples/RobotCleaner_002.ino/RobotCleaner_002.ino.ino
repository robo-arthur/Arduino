// Robot cleaner sample code.
// copyright PICALABO, 2015

#include <AFMotor.h>

AF_DCMotor motorFAN(4);
AF_DCMotor motorR(3);
AF_DCMotor motorL(2);
#define OFF 1
#define ON  0

// Variables will change:
int sw_get = 0;                  // リミットスイッチ状態格納用変数
int mode = 1;                    // モード用変数
long beforetime = 0;             // 時間計測用変数

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Robot Cleaner!");
  pinMode(13, INPUT_PULLUP);
  motorFAN.run(FORWARD);
  motorFAN.setSpeed(255); 
}

// Main loop 
void loop() {
  sw_get = digitalRead(13);
  
  switch (mode) {
    case 1:/* 直進モード */
      motorR.run(FORWARD);
      motorR.setSpeed(200); 
      motorL.run(FORWARD);
      motorL.setSpeed(200);
      if (sw_get == ON){
        beforetime = millis();   // beforetimeの値を置き換える。
        mode = 2;
      }
      break;

    case 2:/* 後退モード */
      motorR.run(BACKWARD);
      motorR.setSpeed(200); 
      motorL.run(BACKWARD);
      motorL.setSpeed(200);
      if (millis() - beforetime > 1000) {
        beforetime = millis();   // beforetimeの値を置き換える。
        mode = 3;
      }
      break;

     case 3:/* 旋回モード */
      motorR.run(FORWARD);
      motorR.setSpeed(200);
      motorL.run(BACKWARD);
      motorL.setSpeed(200);
      if (millis() - beforetime > 500) {
        mode = 1;
      }
      break;

    default: 
      break;
  }

}
