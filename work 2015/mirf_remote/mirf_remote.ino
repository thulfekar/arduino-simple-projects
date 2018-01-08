#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <Keypad.h>
#include <LiquidCrystal.h>




char reply[16]  ;
char ttt ;
char code[16] ; 
int c = 0 ;





LiquidCrystal lcd(19, 18, 14, 15, 16, 17);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns


char Keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2, 1};//connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 
void setup() {

Serial.begin(9600);
 lcd.begin(16, 2);
 Mirf.cePin = 9;             //ce pin on Mega 2560, REMOVE THIS LINE IF YOU ARE USING AN UNO
  Mirf.csnPin = 10;            //csn pin on Mega 2560, REMOVE THIS LINE IF YOU ARE 
   Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"Remote");
  Mirf.payload = sizeof(code);
  Mirf.config();
  lcd.setCursor(0, 0);
lcd.print(" Enter Command  ");
 lcd.setCursor(0,1);
          
}

void loop() {
  unsigned long time = millis();
  // put your main code here, to run repeatedly:
  
  ttt = keypad.getKey();

if(ttt == '*'){
  c=0;
  for (int i = 0 ; i <= 16 ; i++){
 code[i] = ' ' ;}
 lcd.setCursor(0,1);
 lcd.print ("                ");
}
if (ttt >= '0' ) {
 lcd.setCursor(0,1);
code[c] =  ttt;
lcd.print(code);
c++;


if (c >= 16 ){
  c = 0 ;
  for (int i = 0 ; i <= 16 ; i++){
 code[i] = ' ' ;}
  lcd.setCursor(0,1);
  lcd.print("     Error      ");
}
}

if (ttt == '#') {
  
  
  
   Mirf.setTADDR((byte *)"House");
 
  Mirf.send((byte *) &code);
 
  while(Mirf.isSending()){
  }
  delay(10);
  
  lcd.setCursor(0,1);
 lcd.print(" Sending Done  ");
 
delay(10);

 c = 0 ;
  for (int i = 0 ; i <= 16 ; i++){
 code[i] = ' ' ;}
  





  while(!Mirf.dataReady()){

    if ( ( millis() - time ) > 1000 ) {
      lcd.setCursor(0,1);
      lcd.print(" OUT OF RANGE ! ");
      delay(700);
 lcd.setCursor(0,1);
 lcd.print("                   ");
 
 return;
    }
  }
  
    Mirf.getData((byte *) &reply);
    delay(700);
    lcd.setCursor(0,1);
    lcd.print("                   ");
     lcd.setCursor(0,6);
 lcd.print(reply);
       delay(700);
 lcd.setCursor(0,1);
 lcd.print("                   ");
  
}
 

  

}
  




