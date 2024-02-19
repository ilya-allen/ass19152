// Dice ROller Experiment Start
const byte POTPIN = A1
const byte BTNPIN = 1;
int diceChoice = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT)

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(BTNPIN);

  //returns val between 1 and 6 for the dice choice
  diceChoice = map(diceType, 0, 1023, 1, 6);

}
