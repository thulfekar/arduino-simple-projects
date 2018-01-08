#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h> //Call SPI library so you can communicate with the nRF24L01+
#include <nRF24L01.h> //nRF2401 libarary found at https://github.com/tmrh20/RF24/
#include <RF24.h> //nRF2401 libarary found at https://github.com/tmrh20/RF24/
LiquidCrystal_I2C lcd(0x27,16,2);
const int pinCE = 9; //This pin is used to set the nRF24 to standby (0) or active mode (1)
const int pinCSN = 10; //This pin is used to tell the nRF24 whether the SPI communication is a command or message to send out
RF24 radio(pinCE, pinCSN); // Declare object from nRF24 library (Create your wireless SPI)

const uint64_t rAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL, 0xB3B4B5B6A3LL };


void setup()   
{
   lcd.init();
    lcd.backlight();
  lcd.setCursor(0,0);
   lcd.print("Hello, world!");
  Serial.begin(115200);  //start serial to communication
  Serial.print("The number they are trying to guess is: "); 
  Serial.println();
  radio.begin();  //Start the nRF24 module

  radio.setPALevel(RF24_PA_LOW);  // "short range setting" - increase if you want more range AND have a good power supply
  radio.setChannel(108);          // the higher channels tend to be more "open"

  // Open up to six pipes for PRX to receive data
  radio.openReadingPipe(0,rAddress[0]);
  radio.openReadingPipe(1,rAddress[1]);
  radio.openReadingPipe(2,rAddress[2]);
  radio.openReadingPipe(3,rAddress[3]);
  
  radio.startListening();                 // Start listening for messages
}

void loop()  
{   
    byte pipeNum = 0; //variable to hold which reading pipe sent data
    float gotByte = 0; //used to store payload from transmit module
    
    while(radio.available(&pipeNum)){ //Check if received data
     radio.read( &gotByte , sizeof(gotByte)); //read one byte of data and store it in gotByte variable
     Serial.print("Received from transmitter: "); 
     Serial.println(pipeNum + 1); //print which pipe or transmitter this is from
     Serial.print("They guess number: ");
     Serial.println(gotByte); //print payload or the number the transmitter guessed
    
    }

   delay(200);    
}

