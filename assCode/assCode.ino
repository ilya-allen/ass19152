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


// Constant (non changing variable) that names the file
const String FILENAME = "tempAndPressure.txt";


// VOID Setup is ran before the loop and everything inside are usually setup commands
void setup() {

  // All Begin statements are used to turn on and make sure that all commands using the external libraries are functioning
  Wire.begin();
  sdCard.begin();
  valSensor.begin();

  // Change the name of the file from default "LOG" to the custom name
  sdCard.append(FILENAME);

  // To Save the file and give it a beginning text for those reading
  sdCard.println("This is Il'ya's File");
  sdCard.syncFile();
}




// In VOID Loop, everything inside the brackets gets infinitely looped over for as long as the program is on
void loop() {
  // The value variables are constantly updating to get the value of either the pressure or temperature
  pressureValue = valSensor.getPressure_hPa();
  tempValue = valSensor.getTemperature_degC();

  // Function Call for the newLine function
  newLine(pressureValue, tempValue);

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
  return linesCreated += 3;
}

