
#include <SPI.h> //Call SPI library so you can communicate with the nRF24L01+

#include <nRF24L01.h> //nRF2401 libarary found at https://github.com/tmrh20/RF24/

#include <RF24.h> //nRF2401 libarary found at https://github.com/tmrh20/RF24/

const int pinCE = 9; //This pin is used to set the nRF24 to standby (0) or active mode (1)

const int pinCSN = 10; //This pin is used to tell the nRF24 whether the SPI communication is a command or message to send out


RF24 radio(pinCE, pinCSN); // Create your nRF24 object or wireless SPI connection

const uint64_t wAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL, 0xB3B4B5B6A3LL };

const uint64_t PTXpipe = 0x7878787878LL ;   // Pulls the address from the above array for this node's pipe

byte counter = 1; //used to count the packets sent

bool done = false; //used to know when to stop sending packets
long timer ;

void setup()  

{

  Serial.begin(115200);   //start serial to communicate process
  radio.begin();            //Start the nRF24 module

  radio.setPALevel(RF24_PA_LOW);  // "short range setting" - increase if you want more range AND have a good power supply
  radio.setChannel(108);          // the higher channels tend to be more "open"

  radio.openReadingPipe(0,PTXpipe);  //open reading or receive pipe

  radio.startListening(); //go into transmit mode

}

void loop()  

{

float x = 9008.6 ;
    radio.stopListening(); //go into transmit mode
    


 

 

  

     radio.openWritingPipe(PTXpipe);        //open writing or transmit pipe

     radio.write( &x , sizeof(x) );
     
  
    
}
