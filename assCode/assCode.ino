/* assesment code */
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>
OpenLog sdCard; //Create instance
LPS25HB pressureSensor;

int linesCreated = 0;
int pressureValue = 0;
int tempValue = 0;
const String FILENAME = "tempAndPressure.txt";

void setup() {
  Wire.begin();
  sdCard.begin();
  

  sdCard.append(FILENAME);

}

void loop() {
  pressureValue = pressureSensor.getPressure_hPa();
  tempValue = pressureSensor.getTemperature_degC();
  

  if(millis() % 100 == 0) {
    newLine(pressureValue, tempValue)
  }


}

void newLine(pressureVal, tempVal) {
  sdCard.println("It has been " + (millis() / 1000) " seconds since the board has turned on");
  sdCard.println("The pressure value is: " + pressureVal);
  sdCard.println("The temperature value is: " + tempVal);
  sdCard.syncFile();
  return linesCreated += 3;`
}
