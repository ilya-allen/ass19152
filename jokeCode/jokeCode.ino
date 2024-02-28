<<<<<<< HEAD
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
OpenLog sdCard; //Create instance

const String FILENAME = "joke.txt";

=======
// Im sorry I wasnt sure how to define the library or where coding examples were however this has library added.
//HAN COMMENT we will click on tools menu and then manage libraries and search for the openlog library
>>>>>>> 70e36a3872106ad8b33d7d6ca62b7de8ea612356
void setup() {
  Wire.begin();
  sdCard.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements
  Serial.println("Run OpenLog Append File Test");
  sdCard.println("Run OpenLog Append File Test");

  sdCard.println("This is recorded to the default log file");
  
  // This makes sure any print line is appended and added to the certain file. We need to name our file for excellence
  sdCard.append(FILENAME);
  sdCard.println("Knock knock joke");
  sdCard.syncFile();

  Serial.println("Done!");
}


void loop() {
  // put your main code here, to run repeatedly:

  // The Print Line is not writing strings in the sd card but instead adding a line of data. In this instance we are simply adding strings
  // Print line adds our chosen data to the sd card
  sdCard.println("Knock Knock Joke");
  Serial.println('knock knock');

  sdCard.println("who's there?");
  Serial.println("who's there?");

  sdCard.println("Justins grade");
  Serial.println("justins grade");

  sdCard.println("South african whimpering");
  Serial.println("South african whimpering");

  // sync card is to save it
  sdCard.syncFile();

}
