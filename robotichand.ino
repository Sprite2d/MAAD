#include <Servo.h>
Servo myservo;
Servo myservo2;
int Xval;
int Yval;
int servopin2;
int servopin;
int positionval;
void setup() {
  
}

void loop() {
  Xval = analogRead(A0);
  Yval = analogRead(A2);
  servopin = A1;
  servopin2 = A3;
  myservo.attach(servopin);
  myservo2.attach(servopin2);
  int Mappedvalue = map(Xval,0,1023,0,180);
  int Mappedvaluey = map(Yval,0,1024,0,180);
  myservo.write(Mappedvalue);
  myservo2.write(Mappedvaluey);
  
}