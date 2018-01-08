#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int dur , dis ;
void setup() {
  lcd.begin(16, 2);
  lcd.print("  WATER LEVEL  ");
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(5);
  digitalWrite(9, LOW);
  
  dur = pulseIn(8, HIGH);
  dis = dur / 29 / 2 ;
    lcd.setCursor(0, 1);
  lcd .print ("         ");
  lcd.setCursor(0, 1);
  lcd .print (dis);

  
  if(dis >= 10 )
  digitalWrite(10 , HIGH);
  
  if(dis >= 20 )
  digitalWrite(11 , HIGH);
  
  if(dis >= 30 )
  digitalWrite(12 , HIGH);
  
  if(dis >= 40 )
  digitalWrite(13 , HIGH);
  
    delay(200);
    
    
   digitalWrite(10 , LOW);
    digitalWrite(11 , LOW);
     digitalWrite(12 , LOW);
      digitalWrite(13 , LOW);
}

