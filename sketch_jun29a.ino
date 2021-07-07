

#include <Joystick.h> //library

#define JoyX A0;
#define JoyY A1;
#define RotX A2;
#define RotY A3;
#define joyButton1 8
#define joyButton2 7
#define joyButton3 4
#define joyButton4 2// joystick


const bool initAutoSendState = true;

Joystick_ Joystick;
int RxAxis = 0;
int RyAxis = 0;
int XAxis = 0;
int YAxis = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);
  Serial.begin(9600);
  Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  RxAxis = analogRead(JoyX);
  RxAxis = map(RxAxis, 0, 1023, 255, 0);
  // Serial.println(RxAxis);
  Joystick.setRxAxis(RxAxis);
   
  RyAxis = analogRead(JoyY);
  RyAxis = map(RyAxis, 0, 1023,255,0);
  //Serial.println(RyAxis);
  Joystick.setRyAxis(RyAxis);

  XAxis = analogRead(RotX);
  XAxis = map(XAxis, 0, 1023, 0, 255);
  Serial.println(XAxis);
  Joystick.setXAxis(XAxis);
   
  YAxis = analogRead(RotY);
  YAxis = map(YAxis, 0, 1023, 0, 255);
   //Serial.println(RxAxis);
  Joystick.setYAxis(YAxis);

  if(digitalRead(2) == LOW){
    Joystick.pressButton(0);
  }
  else{
    Joystick.releaseButton(0);
  }

  if(digitalRead(4) == LOW){
    Joystick.pressButton(1);
  }
  else{
    Joystick.releaseButton(1);
  }

  if(digitalRead(7) == LOW){
    Joystick.pressButton(2);
  }
  else{
    Joystick.releaseButton(2);
  }

  if(digitalRead(8) == LOW){
    Joystick.pressButton(3);
  }
  else{
    Joystick.releaseButton(3);
  }

  delay(10);
}
