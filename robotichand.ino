#include <Servo.h>
Servo myservo;
int Xval;
int servopin;
int positionval;
void setup() {
  
}

void loop() {
  Xval = analogRead(A0);
  servopin = A1;
  myservo.attach(servopin);
  int Mappedvalue = map(Xval,0,1023,0,180);
  myservo.write(Mappedvalue);
}