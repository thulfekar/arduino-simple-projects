
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int x,  j , c , i , w ;
int  k , t ;
float z;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(8 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(A0 , INPUT);
  pinMode(6 , INPUT_PULLUP);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  z = 0;
  j = 0 ;
  c = 1 ;
  lcd.setCursor(0, 0);
  lcd.print(" APM  ");

}


void loop() {

  x = map( analogRead(A0), 0 , 1024 , 1 , 9 );
  float y = x * 3600000  ;
  lcd.setCursor(8, 0);
  lcd.print("   ");
  lcd.setCursor(8, 0);
  lcd.print( x );
  lcd.setCursor(10, 0);
  lcd.print("HOURS");
  float tim = millis();

here:

  if (millis() >= y ) {
    digitalWrite(8 , HIGH);
    digitalWrite(9 , HIGH);
    delay(3000);
    pinMode(6, OUTPUT);
    digitalWrite(6 , LOW);
  }

  z = (millis() - tim) ;
  t = z / 3600000 ;
  int s = z / 1000 ;
  int l = s / 60 ;
  lcd.setCursor(0, 1);
  lcd.print("CUT OFF=" );
  lcd.setCursor(9, 1);
  lcd.print( x - t - 1  );
  lcd.setCursor(10, 1);
  lcd.print(":");
  lcd.setCursor(11, 1);
  lcd.print("  ");
  lcd.setCursor(11, 1);
  lcd.print( (59 - l  % 60) );
  lcd.setCursor(13, 1);
  lcd.print(":");
  lcd.setCursor(14, 1);
  lcd.print("  ");
  lcd.setCursor(14, 1);
  lcd.print( (60 - s  % 60) );

  Serial.println (y) ;
  goto here;



}
