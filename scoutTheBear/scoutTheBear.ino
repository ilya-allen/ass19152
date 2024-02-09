//shared with mr Hansen successfully
#include <Servo.h>

const byte LEDPIN = 13; 
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

Servo leftEar;
Servo rightEar;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, OUTPUT);
  pinMode(PAWPIN2, OUTPUT);
  pinMode(PAWPIN3, OUTPUT);
  pinMode(PAWPIN4, OUTPUT);
  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, LOW);
  }
  if (digitalRead(PAWPIN3) == HIGH) {
    flapEars();
  }
  if (digitalRead(PAWPIN4) == HIGH) {
    for(int i = 0; i < randomNum(); i++) {
      digitalWrite(LEDPIN, HIGH);
      delay(500);
      digitalWrite(LEDPIN, LOW);
      delay(500);
    }
  }
}

void flapEars() {
  for (int i = 0; i < 3; i++) { 
    rightEar.write(0)
    leftEar.write(90);
    delay(1000);
    rightEar.write(90);
    leftEar.write(0)
    delay(1000)
  }
  
}

void randomNum() {
  return random(2, 15)
}

