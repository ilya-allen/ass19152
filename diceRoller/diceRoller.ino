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
      diceNum = random(1, 4);
      screen.print('The num is:' + diceNum)
      break;
    case (2):
      diceNum = random(1, 6);
      screen.print('The num is:' + diceNum)
      break;
    case (3):
      diceNum = random(1, 8);
      screen.print('The num is:' + diceNum)
      break;
    case (4):
      diceNum = random(1, 12);
      screen.print('The num is:' + diceNum)
      break;
    case (5):
      diceNum = random(1, 18);
      screen.print('The num is:' + diceNum)
      break;
    case (6):
      diceNum = random(1, 20);
      screen.print('The num is:' + diceNum)
      break;
    default:
      Serial.println('Problem with mapping')
      break;

    return diceNum;
  }
}
