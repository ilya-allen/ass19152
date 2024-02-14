#include <Servo.h>

const MICPIN = 8;
const SERVOPIN = 10;
const LOUDLEVEL = 500;
const BUTTON = 7;
bool isLoud = false;
bool lock = false;

Servo boxServo;



void setup() {
  // put your setup code here, to run once:
  pinMode(MICPIN, INPUT);
  pinMode(BUTTON, INPUT);
  boxServo.attach(SERVOPIN);
}

void loop() {
  int micRead = analogRead(MICPIN);

  if (analogRead(BUTTON) == HIGH) {
    lock = true;
  }
  if (isLoud == false && lock == false) {
    if(micRead >= LOUDLEVEL) {
      isLoud = true;
      servo.write(90);
      delay(10000);
      servo.write(0);
      isLoud = false;
    }
  }
}
