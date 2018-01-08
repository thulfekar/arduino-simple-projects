#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

int a, b, x ;
float C ;
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire oneWire(2);
DallasTemperature sensors(&oneWire);

void setup()
{
  sensors.begin();
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  lcd.begin();
  a = analogRead(A0);
  b = analogRead(A0);
  x = map(b , 0 , 1024 , 20 , 125 );
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("   WATER BATH  ");
}

void loop()
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  C = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 0);
  lcd.print("   WATER BATH  ");
  lcd.setCursor(0, 1);
  lcd.print("Water Temp= ");
  lcd.print(C);

  b = analogRead(A0);
  if ( ( b - a > 10 ) || ( a - b > 10 ) ) {
    a = b ;
    float timer = millis();
    while ((millis() - timer ) < 5000 ) {
      if ( ( b - a > 10 ) || ( a - b > 10 ) ) {
        timer = millis();
        a = b ;
      }
      b = analogRead(A0);
      x = map(b , 0 , 1024 , 20 , 125 );
      lcd.setCursor(0, 0);
      lcd.print("  Setting Mode  ");
      lcd.setCursor(0, 1);
      lcd.print("REQ. TEMP = ");
      lcd.setCursor(12, 1);
      lcd.print("     ");
      lcd.setCursor(12, 1);
      lcd.print(x);
       }
  }

  if (C < (x - 1) ) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  else if (C > (x + 1)) {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }

}
