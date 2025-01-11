#include <Servo.h>
#define JOYSTICK_BUTTON_PIN 8
Servo servo;
Servo servo2;
Servo servoclaw;
Servo servoclaw2;
int Xval;
int Yval;
int servopin2;
int servopin;
int servoclawpin;
int servoclawpin2;
int positionval = 90;
int positionval2 = 90;
bool isclawopen = false;
unsigned long Debounce = 0;
const unsigned long Delay = 50;
void setup() {
  pinMode(JOYSTICK_BUTTON_PIN,INPUT_PULLUP);
}

void loop() {
  Xval = analogRead(A0);
  Yval = analogRead(A2);
  servopin = A1;
  servopin2 = A3;
  servoclawpin = A4;
  servoclawpin2 = A5;
  servo.attach(servopin);
  servo2.attach(servopin2);
  servoclaw.attach(servoclawpin);
  servoclaw2.attach(servoclawpin2);
  int value = map(Xval,0,1023,0,180);
  int valuey = map(Yval,0,1024,0,180);
  servo.write(value);
  servo2.write(valuey);
  int buttonstate = digitalRead(JOYSTICK_BUTTON_PIN);
  if (buttonstate == LOW && (millis()-Debounce)>Delay){
    Debounce = millis();
    if (isclawopen==true){
      servoclaw.write(100);
      servoclaw2.write(100);
    }
      if (isclawopen==false){
      servoclaw.write(45);
      servoclaw2.write(135);
    }
    isclawopen = !isclawopen;
    delay(50);
  }

}