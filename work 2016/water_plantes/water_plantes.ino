
#include <LiquidCrystal.h>
LiquidCrystal lcd(33, 31, 23, 25, 27, 29);

int x, y, z, j , c , i , w ;
int tim , k , t ;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  analogWrite(2, 255);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  analogWrite(5, 255);
  pinMode(A0 , INPUT);
  pinMode(A1 , INPUT);
  pinMode(A2 , INPUT);
  z = 0;
  j = 0 ;
  c = 1 ;
  lcd.setCursor(0, 0);
  lcd.print(" TIME     WATER ");
  lcd.print(" -- min   - min ");

}


void loop() {

  x = map(analogRead(A1) , 10 , 1020 , 3 , 90);
  y = map(analogRead(A2) , 10 , 900 , 1 , 5);
  z = analogRead(A0);

  lcd.setCursor(1, 1);
  lcd.print("   ");
  lcd.setCursor(1, 1);
  lcd.print( x );
  lcd.setCursor(4, 1);
  lcd.print("Min");
  lcd.setCursor(11, 1);
  lcd.print("   ");
  lcd.setCursor(11, 1);
  lcd.print( y );
  lcd.setCursor(12, 1);
  lcd.print("Min");

  w = millis();
  w = w / 1000 ;
  Serial.println(w);

  if ( z > 100)
  {
    j = 1 ;
  }
  delay(25);

  if (j < 1) goto jump;

Loop:

  t = (millis() / 1000 ) - w ;
  Serial.println(t);


  if ( t <= (x * 60)  )
  {
    if (t <=  (y * 60) )
    {

      digitalWrite(c + 1, LOW);
      lcd.setCursor(0, 1);
      lcd.print("VALVE=");
      lcd.setCursor(6, 1);
      lcd.print(c);
      lcd.setCursor(9, 1);
      lcd.print ("   ");
      lcd.setCursor(9, 1);
      lcd.print ((y * 60) - t );
      lcd.setCursor(12, 1);
      lcd.print("SEC.");


    }
    else {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("CUT OFF=" );
      lcd.setCursor(9, 1);
      lcd.print("  ");
      lcd.setCursor(9, 1);
      lcd.print( x - (t / 60)  );
      lcd.setCursor(11, 1);
      lcd.print(":");
      lcd.setCursor(12, 1);
      lcd.print("    ");
      lcd.setCursor(12, 1);
      lcd.print( (60 - t % 60) );




    }
  }
  else {
    c = c + 1 ;
    if (c >= 5 ) c = 1 ;
    w = millis() / 1000 ;

  }

  if (j > 0 ) goto Loop;

jump:;

}
