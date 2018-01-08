/*
PROJECT: TV Volume Guard
AUTHOR: Hazim Bitar (techbitar)
DATE: FEB 9, 2013
CONTACT: techbitar at gmail dot com
LICENSE: My code is in the public domain.          
IRremote library: copyright by Ken Shirriff http://arcfn.com
*/

#include <IRremote.h>

#define NOISE_LEVEL      690  // level of noise to detect from 0 to 1023
#define REPEAT_TX         3 // how many times to transmit the IR remote code
#define REMOTE_CODE     0x4FBB847  // remote code to transmit. This is for my TV. Replace with yours. 
#define REMOTE_BIT   32

#define SOUND_SENSOR_PIN     A0 // sound sensor connected to this analog pin


IRsend irsend; // instantiate IR object

void setup()
{
  Serial.begin(9600);
  pinMode(A5,INPUT);
  
}

void loop()
{
  int pot = analogRead(A5) ;
  int soundLevel = analogRead(SOUND_SENSOR_PIN); // read the sound sensor
  Serial.print(soundLevel);
  Serial.print("          ");
  Serial.println(pot);

 
  int margin = map(pot ,0,1020, 0, 10 );
  soundLevel = soundLevel + margin ;
  
  if(soundLevel > NOISE_LEVEL) // compare to noise level threshold you decide
  {
    
    
    for (int txCount = 0; txCount < REPEAT_TX; txCount++) { // how many times to transmit the IR remote  code
      irsend.sendNEC(REMOTE_CODE , REMOTE_BIT); // Change to match your remote protocol
      delay(200);

      // Uncomment the function that matches your remote control protocol as shown by IRrecvDump
      // irsend.sendNEC(REMOTE_CODE, REMOTE_BIT);
      // irsend.sendSony(REMOTE_CODE, REMOTE_BIT);
      // irsend.sendRC5(REMOTE_CODE, REMOTE_BIT);
      // irsend.sendRC6(REMOTE_CODE, REMOTE_BIT);

    }
  }
  
}
//Enjoy, TechBitar at gmail dot com
