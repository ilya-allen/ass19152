/* Il'ya Allen Assesment Code */

/* paperwork 30th august */
/* birthday today */

// Non-Core Libraries used for external functions
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

// Creates instances like variables so they can be used with the external libraries
OpenLog sdCard;
LPS25HB valSensor;

// Changing variables (Changeable variables)
int linesCreated = 0;
int pressureValue = 0;
int tempValue = 0;

// Constant (non changing variable) that names the file
const String FILENAME = "tempAndPressure.txt";


// VOID Setup is ran before the loop and everything inside are usually setup commands
void setup() {

  // All Begin statements are used to turn on and make sure that all commands using the external libraries are functioning. Includes a cardChecker call to test for invalidity with the sd Card.
  Wire.begin();
  sdCard.begin();
  valSensor.begin();
  cardChecker();
  
  // Change the name of the file from default "LOG" to the custom name
  sdCard.append(FILENAME);

  // To Save the file and give it a beginning text for those reading
  sdCard.println("Time,Pressure,Temperature");
  sdCard.syncFile();
}

// In VOID Loop, everything inside the brackets gets infinitely looped over for as long as the program is on
void loop() {
  // The value variables are constantly updating to get the value of either the pressure or temperature
  pressureValue = valSensor.getPressure_hPa();
  tempValue = valSensor.getTemperature_degC();
  int secondsPassed = millis() / 100;

  // Calls the format function which can be chosen for either debbuging or csv format.
  format(false, pressureValue, tempValue, secondsPassed);
}

// This function is to be called in the void loop. If the format function is called with true at the front it will run the debug version which calls the new line function which can be used to help the user find anything wrong with the outputs or the code.
// If the function is called with false, it will run the main csv format used for expierenced users needing their data in csv format.
void format(boolean info, int pressure, int temp, int time) {
  if(info == true) {
    newLine(pressure, temp);
  } else {
    sdCard.println(String(time) + "," + String(pressure) + "," + String(temp));
  }
}

// This function is used to check invalid input and whether or not the SD card is inside the slot. If the SD card is not in the slot it will send a serial statement telling the user that no lines will be written as there is no card.
// This is a part of the invalid input testing case. If the SD Card is there then a serial print line statement will be sent to confirm the sd card is in.
void cardChecker() {
  // This will take a hexidecimal number from the board and each different number explains a different status of the SD Card in the board
  byte cardStatus = sdCard.getStatus();

  // This Hexadecimal means that SD Card is missing and no data will be written as there is no SD Card inside
  if (cardStatus == 0xFF) {
    Serial.println("SD CARD readings unavailable to respond. Most likely no SD Card inserted");
  }
  // This status means that the SD Card is available and ready to read. If it is not this status then it is another problem related to the SD Card meaning it is unable to initialise.
  if (cardStatus & 1<<0) {
    Serial.println("SD Card is reading and present.");
  } else {
    Serial.println("SD initialisation failure. Check SD Card!");
  }
}

// The New Line function creates informatipon lines for the sd card and its value readings
void newLine(int pressure, int temp) {
  // First Array is for the user interface reading and the second array is the values for users to read
  String lineIntro[] = {"The amount of seconds since the board has turned on is: ", "The pressure value is: ", "The temperature value is: "};
  int lineValues[] = {millis() / 100, pressure, temp};

  // The for loop is used to reduce the copy and past code and instead creates three lines of information with only one line of code inside the loop
  for (int i = 0; i <= 3; ++i) {
    sdCard.println(lineIntro[i] + lineValues[i]);
  }

  // Saves file and gives coders information about how many lines of information was created
  sdCard.syncFile();
  sdCard.println("lines created are:" + String(linesCreated += 3));
}
