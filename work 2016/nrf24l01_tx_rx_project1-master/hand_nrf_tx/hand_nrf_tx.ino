/* JoyStick module transceiver code
By Nazmus
http://www.Easyprogramming.net
http://nazm.us
 - SEE the comments after "//" on each line below
 - CONNECTIONS: nRF24L01 Modules See:
 http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED

   Default Button Pins:
   Up - pin 2
   Right - pin 3
   Down - pin 4
   Left - pin 5
   -
   Analog Joystick module
   GND to Arduino GND
   VCC to Arduino +5V
   X Pot to Arduino A0
   Y Pot to Arduino A1

/*-----( Import needed libraries )-----*/
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h>
int x, y , z ;
#define DEVICE (0x53) // Device address as specified in data sheet 

byte _buff[6];

char POWER_CTL = 0x2D;  //Power Control Register
char DATA_FORMAT = 0x31;
char DATAX0 = 0x32; //X-Axis Data 0
char DATAX1 = 0x33; //X-Axis Data 1
char DATAY0 = 0x34; //Y-Axis Data 0
char DATAY1 = 0x35; //Y-Axis Data 1
char DATAZ0 = 0x36; //Z-Axis Data 0
char DATAZ1 = 0x37; //Z-Axis Data 1

/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   9
#define CSN_PIN 10

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E2LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[9];  // 6 element array holding Joystick reading and 4 buttons
int JOYSTICK_X;
int JOYSTICK_Y;
int f1 ;
int f2 ;
int f3 ;
int f4 ;
int f5 ;
void setup()   /****** SETUP: RUNS ONCE ******/
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  //Put the ADXL345 into +/- 4G range by writing the value 0x01 to the DATA_FORMAT register.
  writeTo(DATA_FORMAT, 0x01);
  //Put the ADXL345 into Measurement Mode by writing 0x08 to the POWER_CTL register.
  writeTo(POWER_CTL, 0x08);
  //declare pinMode for all buttons and initial state
}


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{

  f5 = map(analogRead(A2), 120, 190, 1, 180);
  f2 = map(analogRead(A3), 120, 190, 1, 180);
  f1 = map(analogRead(A4), 120, 190, 1, 180);
  f4 = map(analogRead(A5), 120, 190, 1, 180);
  f3 = map(analogRead(A6), 120, 200, 1, 180);
JOYSTICK_X = map(analogRead(A0),0,1024,1,1000);
JOYSTICK_Y = map(analogRead(A1),0,1024,1,1000);

  readAccel(); // read the x/y/z tilt
  joystick[0] = JOYSTICK_X;
  joystick[1] = JOYSTICK_Y;
  joystick[2] = f1;
  joystick[3] = f2;
  joystick[4] = f3;
  joystick[5] = f4;
  joystick[6] = f5;
  joystick[7] = x ;
  joystick[8] = y ;
  radio.write( joystick, sizeof(joystick) );

  // Debugging code below
  Serial.print("X = ");

  Serial.print(analogRead(A0));
  Serial.print(" Y = ");

  Serial.print(analogRead(A1));
  Serial.print(" Y = ");
  Serial.print(" Up = ");
  Serial.print(analogRead(A2));
  Serial.print(" Right = ");
  Serial.print(analogRead(A3));
  Serial.print(" Down = ");
  Serial.print(analogRead(A4));
  Serial.print(" Left = ");
  Serial.print(analogRead(A5));
  Serial.print(" other = ");
  Serial.println(analogRead(A6));

  // Debugging code above
}//--(end main loop )---

void readAccel() {
  uint8_t howManyBytesToRead = 6;
  readFrom( DATAX0, howManyBytesToRead, _buff); //read the acceleration data from the ADXL345

  // each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
  // thus we are converting both bytes in to one int
  x = (((int)_buff[1]) << 8) | _buff[0];
  y = (((int)_buff[3]) << 8) | _buff[2];
  z = (((int)_buff[5]) << 8) | _buff[4];
  Serial.print("x: ");
  Serial.print( x );
  Serial.print(" y: ");
  Serial.print( y );
  Serial.print(" z: ");
  Serial.println( z );
}

void writeTo(byte address, byte val) {
  Wire.beginTransmission(DEVICE); // start transmission to device
  Wire.write(address);             // send register address
  Wire.write(val);                 // send value to write
  Wire.endTransmission();         // end transmission
}

// Reads num bytes starting from address register on device in to _buff array
void readFrom(byte address, int num, byte _buff[]) {
  Wire.beginTransmission(DEVICE); // start transmission to device
  Wire.write(address);             // sends address to read from
  Wire.endTransmission();         // end transmission

  Wire.beginTransmission(DEVICE); // start transmission to device
  Wire.requestFrom(DEVICE, num);    // request 6 bytes from device

  int i = 0;
  while (Wire.available())        // device may send less than requested (abnormal)
  {
    _buff[i] = Wire.read();    // receive a byte
    i++;
  }
  Wire.endTransmission();         // end transmission
}
