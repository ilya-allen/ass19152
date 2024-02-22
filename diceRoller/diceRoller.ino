#include <Adafruit_LiquidCrystal.h>

// Sorry this was quite confusing the library for this code I will get it done after band camp

// Dice ROller Experiment Start
const byte POTPIN = A1;
const byte BTNPIN = 1;
const byte NOISEPIN = A0;
int diceType = 0;

Adafruit_LiquidCrystal screen(0);

void setup() {
  // put your setup code here, to run once:
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT);
  Serial.begin(9600);

  randomSeed(analogRead(NOISEPIN));

  if(!screen.begin(16, 2)) {
    Serial.println("couldnt start screen")
    while(1)
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(BTNPIN) == HIGH) {
    diceType = analogRead(POTPIN);
    diceType = map(potVal, 0, 1023, 1, 6); 

    
    rollDice(diceType);
  }



}

void rollDice(numberOfSides) {
  int diceNum = 0;
  switch (numberOfSides) {
    case (1):
      screen.print('The num is: ')
      diceNum = random(1, 4);
      break;
    case (2):
      screen.print('The num is: ')
      diceNum = random(1, 6);
      break;
    case (3):
      screen.print('The num is: ')
      diceNum = random(1, 8);
      break;
    case (4):
      screen.print('The num is: ')
      diceNum = random(1, 12);
      break;
    case (5):
      screen.print('The num is: ')
      diceNum = random(1, 18);
      break;
    case (6):
      screen.print('The num is: ')
      diceNum = random(1, 20);
      break;
    default:
      Serial.println('Problem with mapping')
      break;

    return diceNum;
  }
}