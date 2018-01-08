#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(32, 30, 28, 26, 24, 22);
const byte ROWS = 4;
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5 }; 
byte colPins[COLS] = {6, 7, 8, 9 }; 
int i ;
char hhh[4] ;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
    lcd.setCursor(0,0);
  lcd.print("Security System");
pinMode(A0, OUTPUT);
pinMode(A1, OUTPUT);
pinMode(A2, OUTPUT);
digitalWrite(A1, LOW);
digitalWrite(A2, LOW);
digitalWrite(A0, HIGH);

 lcd.setCursor(0,1);
    lcd.print("Enter pass");
    lcd.print(" ");
}

void loop() {


  
 cancel:

 char key = keypad.getKey();
  if (key) {

    if (key == '*') {
      lcd.setCursor(12,1);
      lcd.print("    ");
      i = 0 ;
      goto cancel;
    }

    if (key == '#' ) {
      if ((hhh[0] == '9') && ( hhh[1] == '8' ) && (hhh[2] == '7' ))
      {
        digitalWrite (A0 , LOW);
         lcd.setCursor(0,1);
    lcd.print("Door is Open");
    lcd.print("    ");
    analogWrite(A1, 150 );
        delay(3000);
        digitalWrite(A0 , HIGH);
        digitalWrite(A1, LOW);
 lcd.setCursor(0,1);
    lcd.print("Enter pass");
    lcd.print("        ");
   
    goto cancel;
      }
      i = 0 ;
       lcd.setCursor(0,1);
    lcd.print("Wrong Password");
    lcd.print("    ");
    analogWrite(A2,150);
    delay(2000);
    digitalWrite(A2, LOW);
     lcd.setCursor(0,1);
   lcd.print("Enter pass");
    lcd.print("        ");
      goto cancel;
    }

    if ( i > 2)    i = 0 ;
    hhh[i] = key ;
    i ++ ;
    Serial.println(hhh);
    lcd.setCursor(12,1);
    lcd.print(hhh);
}
}
