/* assesment code */


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


// Constant Variables (Non-Changeable)
const String FILENAME = "tempAndPressure.txt";


// Setup for the csv file so that it is named and ready to receive information
void setup() {
 


  Wire.begin();
  sdCard.begin(); //Open connection to OpenLog (no pun intended)
  valSensor.begin();
  sdCard.append("tempAndPressureValues.txt");


  sdCard.println("This is Il'ya's File");
  sdCard.syncFile();
}




// This is the main loop containing code  that will take in values realtime and send updates to the
// csv file every 100ms using the divisible operator.
// Functionality implication
void loop() {
  pressureValue = valSensor.getPressure_hPa();
  tempValue = valSensor.getTemperature_degC();
 
  sdCard.print("yo");


  newLine(pressureValue, tempValue);




}


// This function will be called every time the  milliseconds is a multiple of 100 and instead of constantly
// sending multiple print lines we can save coding space by calling a function with input into the parameters
void newLine(int pressure, int temp) {
  String lineIntro[] = {"The amount of seconds since the board has turned on is: ", "The pressure value is: ", "The temperature value is: "};
  int lineValues[] = {millis(), pressure, temp};
 
  for (int i = 0; i <= 3; ++i) {
    sdCard.println(lineIntro[i] + lineValues[i]);
  }
  sdCard.syncFile();
  return linesCreated += 3;
}

