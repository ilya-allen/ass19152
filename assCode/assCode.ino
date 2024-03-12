/* assesment code */
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>
OpenLog sdCard; //Create instance

int linesCreated = 0;
const String FILENAME = "joke.txt";

void setup() {
  Wire.begin();
  sdCard.begin();

  sdCard.append("tempAndPressure.txt");

}

void loop() {
  // put your main code here, to run repeatedly:

}

void newLine(pressureVal, tempVal) {
  sdCard.println("It has been " + (millis() / 1000) " seconds since the board has turned on");
  sdCard.println("The pressure value is: " + pressureVal);
  sdCard.println("The temperature value is: " + tempVal);
  sdCard.syncFile();
  return linesCreated += 3;
}
