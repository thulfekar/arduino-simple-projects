char command ;
#include <LiquidCrystal.h>
LiquidCrystal lcd(19, 18, 17, 16, 15, 14);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin (9600);
  lcd.setCursor(3, 0 );
  lcd.print(" WELCOME  ");

}

void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial.available()) { }

  command = Serial.read();
  Serial.println(command);

  switch (command) {
    case 'A' :
    lcd.setCursor(1, 1 );
  lcd.print("               ");
 lcd.setCursor(3, 1 );
  lcd.print(" MUSTAFA  ");


      break;

    case 'B' :
    lcd.setCursor(1, 1 );
  lcd.print("                ");
 lcd.setCursor(3, 1 );
  lcd.print(" MUTHAFAR  ");

      break;

    case 'C' :
    lcd.setCursor(1, 1 );
  lcd.print("                ");
 lcd.setCursor(3, 1 );
  lcd.print(" YAZIN  ");

      break;

    case 'D' :

    lcd.setCursor(1, 1 );
  lcd.print("             ");
 lcd.setCursor(1, 1 );
  lcd.print("MUSTAFA RAHEEM");
      break;
    case 'X' :

    lcd.setCursor(1, 1 );
  lcd.print("             ");
 lcd.setCursor(1, 1 );
  lcd.print("THULFEKAR");
      break;

    default:
    ;
  }

}
