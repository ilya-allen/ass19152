/* assesment code */

// Non-Core Libraries used for external functions
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

// Creates instances like variables so they can be used with the external libraries
OpenLog sdCard; 
LPS25HB pressureSensor;

// Integer variables (Changeable variables)
int linesCreated = 0;
int pressureValue = 0;
int tempValue = 0;

// Constant Variables (Non-Changeable)
const String FILENAME = "tempAndPressure.txt";

// Setup for the csv file so that it is named and ready to receive information
void setup() {
  Wire.begin();
  sdCard.begin();
  

  sdCard.append(FILENAME);

}


// This is the main loop containing code  that will take in values realtime and send updates to the
// csv file every 100ms using the divisible operator.
void loop() {
  pressureValue = pressureSensor.getPressure_hPa();
  tempValue = pressureSensor.getTemperature_degC();
  

  if(millis() % 100 == 0) {
    newLine(pressureValue, tempValue)
  }


}

// This function will be called every time the  milliseconds is a multiple of 100 and instead of constantly 
// sending multiple print lines we can save coding space by calling a function with input into the parameters
void newLine(pressureVal, tempVal) {
  sdCard.println("It has been " + (millis() / 10S00) " seconds since the board has turned on");
  sdCard.println("The pressure value is: " + pressureVal);
  sdCard.println("The temperature value is: " + tempVal);
  sdCard.syncFile();
  return linesCreated += 3;`
}
