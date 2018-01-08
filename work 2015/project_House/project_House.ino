#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

 char reply[16] = "  RECIEVED !!  " ;

char ttt ;
char code[16] ; 
int c = 0 ;




void setup() {
  // put your setup code here, to run once:


Serial.begin(9600);
 Mirf.cePin = 9;             //ce pin on Mega 2560, REMOVE THIS LINE IF YOU ARE USING AN UNO
  Mirf.csnPin = 10;            //csn pin on Mega 2560, REMOVE THIS LINE IF YOU ARE 
   Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"House");
  Mirf.payload = sizeof(code);
  Mirf.config();


}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(!Mirf.isSending() && Mirf.dataReady()){
    
 Mirf.getData((byte *) &code);
  
   Serial.println(code);
 delay(10);  
  Mirf.setTADDR((byte *)"Remote");

  Mirf.send((byte *) &reply);
 Serial.println("Reply sent.");
 
 delay(50);
 
  }

}
