// You can copy & paste this code into Arduino and upload it

/*
PROJECT: SensoDuino IR Remote Control Station 0.1
PROGRAMMER: Hazim Bitar (techbitar.com)
DATE: NOV 25, 2013
FILE: sensoduino_ir_station.ino (based on sensoduino.ino)
LICENSE: Public domain
*/
#include <SoftwareSerial.h>


#include <IRremote.h>

#define THRESHOLD_VALUE  0  // Set critical level to detect. Ignore if potentiometer is used
#define REPEAT_TX   3 // How many times to transmit the IR remote code
#define REMOTE_CODE     0xFE22DD
// remote code to transmit for volume down for my TV. Replace with your device IR code
#define REMOTE_BIT   32
#define LED        13      // LED used to blink when volume too high
SoftwareSerial serialb (8 , 9 );
IRsend irsend; // instantiate IR object

#define START_CMD_CHAR '>'
#define END_CMD_CHAR '\n'
#define DIV_CMD_CHAR ','

#define DEBUG 1 // Set to 0 if you don't want serial output of sensor data

String inText;
float value0, value1, value2; // vars containing sensor values.

void setup() {

  // This is the Sensor Help List for sensor numbers
  serialb.begin(9600); // 9600 is the default speed of the HC-05 and most Bluetooth serial modules
  Serial.begin(9600);
  Serial.println("\nSensoDuino 0.13 by TechBitar.com (2013).\n");
  Serial.println("Android Sensor Type No: ");
  Serial.println("1- ACCELEROMETER  (m/s^2 - X,Y,Z)");
  Serial.println("2- MAGNETIC_FIELD (uT - X,Y,Z)");
  Serial.println("3- ORIENTATION (yaw, pitch, roll)");
  Serial.println("4- GYROSCOPE (rad/s - X,Y,Z)");
  Serial.println("5- LIGHT (SI lux)");
  Serial.println("6- PRESSURE (hPa millibar)");
  Serial.println("7- DEVICE TEMPERATURE (C)");
  Serial.println("8- PROXIMITY (Centimeters or 1,0)");
  Serial.println("9- GRAVITY (m/s^2 - X,Y,Z)");
  Serial.println("10- LINEAR_ACCELERATION (m/s^2 - X,Y,Z)");
  Serial.println("11- ROTATION_VECTOR (X,Y,Z)" );
  Serial.println("12- RELATIVE_HUMIDITY (%)");
  Serial.println("13- AMBIENT_TEMPERATURE (C)");
  Serial.println("14- MAGNETIC_FIELD_UNCALIBRATED (uT - X,Y,Z)");
  Serial.println("15- GAME_ROTATION_VECTOR (X,Y,Z)");
  Serial.println("16- GYROSCOPE_UNCALIBRATED (rad/s - X,Y,Z)");
  Serial.println("17- SIGNIFICANT_MOTION (1,0)");
  Serial.println("95 - TIME (H,M,S)");
  Serial.println("96 - DATE (Y,M,D)");
  Serial.println("97 - AUDIO (Vol.)");
  Serial.println("98 - GPS1 (lat., long., alt.)");
  Serial.println("99 - GPS2 (bearing, speed, date/time)");
  Serial.println("\n\nNOTE: IGNORE VALUES OF 99.99\n\n");
  Serial.flush();

  pinMode(LED, OUTPUT);
}

void loop()
{
  Serial.flush();
  int inCommand = 0;
  int sensorType = 0;
  unsigned long logCount = 0L;

  char getChar = ' ';  //read serialb
  // wait for incoming data
  if (serialb.available() < 1) {
    return; // if serialb empty, return to loop().
  }

  // parse incoming command start flag
  getChar = serialb.read();
  if (getChar != START_CMD_CHAR) return; // if no command start flag, return to loop().

  // parse incoming pin# and value
  sensorType = serialb.parseInt(); // read sensor typr
  logCount = serialb.parseInt();  // read total logged sensor readings
  value0 = serialb.parseFloat();  // 1st sensor value
  value1 = serialb.parseFloat();  // 2rd sensor value if exists
  value2 = serialb.parseFloat();  // 3rd sensor value if exists

  // Show sensor and values of sensors for debugging.
  if (DEBUG) {
    Serial.print("Sensor type: ");
    Serial.println(sensorType);
    Serial.print("Sensor log#: ");
    Serial.println(logCount);
    Serial.print("Val[0]: ");
    Serial.println(value0);
    Serial.print("Val[1]: ");
    Serial.println(value1);
    Serial.print("Val[2]: ");
    Serial.println(value2);
    Serial.println("-----------------------");
    delay(10);
  }
  // Change the sensor number to match the senor you which to read. See Sensor Help List above.
  if (sensorType != 97) return;  // If I am not reading Audio Sensor values, go back and keep reading.

  // Read the potentiometer value (0-1023)or assign VolValue
  // to constant THRESHOLD_VALUE if you don't want to use the potentiometer.
  int volValue = analogRead(A5);
  Serial.println(analogRead(A5));
  // Since my audio sensor on my Arduino returns values from 0 to 32K I will map it to Analog min/max
  float volLimit = volValue * (32000 / 1023.0); // 32K is about max returned by SensoDuino Audio sensor
  int soundLevel = value0; // Read the sound sensor from SensoDuino (Bluetooth)
  if (soundLevel > volLimit) // Compare to noise level threshold set by potentiometer.
  {
    digitalWrite(LED, HIGH); // while transmitting IR turn LED on
    delay(200);
    for (int txCount = 0; txCount < REPEAT_TX; txCount++) { // Transmit the IR remote code
      irsend.sendNEC(REMOTE_CODE , REMOTE_BIT); // See commented list below and replace to match your IR system
      delay(200);

      // Uncomment the function that matches your remote control protocol as shown by IRrecvDump
      // irsend.sendNEC(REMOTE_CODE, REMOTE_BIT);
      // irsend.sendSony(REMOTE_CODE, REMOTE_BIT);
      // irsend.sendRC5(REMOTE_CODE, REMOTE_BIT);
      // irsend.sendRC6(REMOTE_CODE, REMOTE_BIT);
    }
  }
  digitalWrite(LED, LOW); // when done transmitting IR, turn LED off

}
