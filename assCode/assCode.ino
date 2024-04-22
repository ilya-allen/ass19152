/* assesment code */

// Non-Core Libraries used for external functions
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

// Creates instances like variables so they can be used with the external libraries
OpenLog sdCard; 
LPS25HB pressureSensor;

// Changing variables (Changeable variables)
int linesCreated = 0;
int pressureValue = 0;
int tempValue = 0;

// Constant Variables (Non-Changeable)
const String FILENAME = "testFile.txt";

// Setup for the csv file so that it is named and ready to receive information
void setup() {
  Wire.begin();
  sdCard.begin();
  sdCard.append(FILENAME);
//TEACHER COMMENTS I might suggest some checks on if the sdCard and pressure sensor have been turned on correctly go here
  sdCard.println('new test file');
}


// This is the main loop containing code  that will take in values realtime and send updates to the
// Functionality implication
void loop() {
  pressureValue = pressureSensor.getPressure_hPa();
  tempValue = pressureSensor.getTemperature_degC();
  
  // The csv file is updated with a new line every 100ms using the divisible operator through the if statement.
  // if(millis() % 100 == 0) {
  
  // TESTING 
  newLine(pressureValue, tempValue);
  sdCard.println('testing');
  // }


}

//TEACHER COMMENTS check what the csv file should look like with the example on classroom - you might keep this one for error checking and have another that 
//is more suitable for writing to the file
// This function will be called every time the  milliseconds is a multiple of 100 and instead of constantly 
// sending multiple print lines we can save coding space by calling a function with input into the parameters
void newLine(int pressure, int temp) {
  String lineIntro[] = {"The amount of seconds since the board has turned on is: ", "The pressure value is: ", "The temperature value is: "};
  int lineValues[] = {millis(), pressure, temp};
  
  for (int i = 0; i <= 3; ++i) {
    sdCard.println(lineIntro[i] + lineValues[i]);
  }
  sdCard.syncFile();
  //TEACHER COMMENTS you have a void method so it returns nothing
  //return linesCreated += 3;
}
