//shared with mr Hansen successfully 
const byte LEDPIN = 13 const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, OUTPUT);
  pinMode(PAWPIN2, OUTPUT);
  pinMode(PAWPIN3, OUTPUT);
  pinMode(PAWPIN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH)
  }
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, HIGH)
  }
  if (digitalRead(PAWPIN3) == HIGH) {
    playMusic();
  }
  if (digitalRead(PAWPIN4) == HIGH) {
    int score = playGame();
  }
}

void playMusic() {
  // Play an mp3 file
}

void playGame() {
  byte score = 99;

  return score
}
