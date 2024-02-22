// Dice ROller Experiment Start
const byte POTPIN = A1;
const byte BTNPIN = 1;
int diceType = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(BTNPIN) == HIGH) {
    diceType = analogRead(POTPIN);
    diceType = map(potVal, 0, 1023, 1, 6); 
    rollDice(diceType)
  }



}

void rollDice(numberOfSides) {
  int diceNum = 0;
  switch (numberOfSides) {
    case (1):
      diceNum = random(1, 4);
      break;
    case (2):
      diceNum = random(1, 6);
      break;
    case (3):
      diceNum = random(1, 8);
      break;
    case (4):
      diceNum = random(1, 12);
      break;
    case (5):
      diceNum = random(1, 18);
      break;
    case (6):
      diceNum = random(1, 20);
      break;
    default:
      Serial.println('Problem with mapping')
      break;

    return diceNum;
  }
}