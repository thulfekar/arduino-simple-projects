#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
int da1,da2,da3,da4,da5,da6,da7,da8,da9,da10,da11,da12,da13;
long data;
int l = 1 ;
char reply[16] ;
char code[16] ; 




#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 18, 17, 16, 15, 14);
int c = 0 ;
#include <Keypad.h>
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
  Mirf.setRADDR((byte *)"clie1");
  Mirf.payload = sizeof(data);
  Mirf.config();
  lcd.setCursor(0, 0);
lcd.print("       YOU:      ");
 lcd.setCursor(0,1);
 lcd.print("     FRIEND:    ");
          
}

void loop() {
  unsigned long time = millis();
  // put your main code here, to run repeatedly:
  data = 0;
  
char ttt = keypad.getKey();

if(ttt == '*'){
  c=0;
  for (int i = 0 ; i <= 16 ; i++){
 code[i] = ' ' ;}
 lcd.setCursor(0,0);
 lcd.print ("ME:             ");
 lcd.setCursor(0,1);
 lcd.print ("FR:             ");
}
if (ttt >= '0' ) {
  lcd.setCursor(0,0);
 lcd.print ("ME:             ");
 lcd.setCursor(3,0);
code[c] =  ttt;
lcd.print(code);
delay(10);

c++;
if (c >= 13 ){
  c = 0 ;
  for (int i = 0 ; i <= 16 ; i++){
 code[i] = ' ' ;}
  lcd.setCursor(0,0);
  lcd.print("     Error      ");
}
}

if (ttt == '#') {
  
  
    da1 = (code[0] - '0' ) ;
    da2 = (code[1] - '0' ) ;
    da3 = (code[2] - '0' ) ;
    da4 = (code[3] - '0' ) ;
    da5 = (code[4] - '0' ) ;
    da6 = (code[5] - '0' ) ;
    da7 = (code[6] - '0' ) ;
    da8 = (code[7] - '0' ) ;
    da9 = (code[8] - '0' ) ;
    da10 = (code[9] - '0' ) ;
    da11 = (code[10] - '0' ) ;
    da12 = (code[11] - '0' ) ;
    da13 = (code[12] - '0' ) ;
 

    
    data = (da1*1000000000000) +(da2*100000000000) +(da3*10000000000) +(da4*1000000000) +(da5*100000000) +(da6*10000000) +(da7*1000000) +(da8*100000) +(da9*10000) +(da10*1000) + (da11 *100) + (da12 *10 ) + da13 ;
  
   Mirf.setTADDR((byte *)"serv1");
 Serial.println (data);
  Mirf.send((byte *) &code);
 Serial.println(code);
  while(Mirf.isSending()){
  }
  delay(10);
  
  lcd.setCursor(0,0);
 lcd.print(" Sending Done  ");
 delay(700);
 lcd.setCursor(0,0);
 lcd.print ("ME:             ");
 c = 0 ;
  for (int i = 0 ; i <= 16 ; i++){
 code[i] = ' ' ;}

}
 if(Mirf.dataReady()){
   Mirf.getData((byte *) &reply);
   
 lcd.setCursor(0,1);
 lcd.print("FR:                ");
 lcd.setCursor(3,1);
 lcd.print(reply);
 }
 
 
   
  
 
 
  

 

  

}
  




