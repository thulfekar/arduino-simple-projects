#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin();
  lcd.backlight();
  lcd.print(" H2 LPG CH4 CO ");
  lcd.setCursor(0, 1);
   lcd.print("Detected:");
   pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = analogRead(A0);
int b = map(a , 0 , 1024 , 0 , 100 );
b = b - 10 ;
if ( b < 0 ) b =0 ;
  lcd.setCursor(11, 1);
  lcd.print(b);
  lcd.print(" %");
}
