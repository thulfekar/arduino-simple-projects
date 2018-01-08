#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(27, 26, 22, 23, 24, 25);
Servo servo1;
Servo servo2;
char pass[5];
char ddd[5];

int i = 0 ;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

int buzzer = 10 ;
int Camera = 30 ;
int flame1 = 54 ; //A0
int flame2 = 55 ; //A1
int flame3 = 56 ; //A2
int flame4 = 57 ; //A3
int gas = 58 ; //A4
int motion = 11 ;
int motion2 = 12 ;
int door2 = 13;
int flag = 0 ;

char Keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2, 1};//connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);


void setup() {
  ddd[0] = '1' ;
  ddd[1] = '2' ;
  ddd[2] = '3' ;
  ddd[3] = '4' ;
  servo2.attach(50);
  servo1.attach(9);
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("  Enter PIN   ");
  lcd.setCursor(0, 1);
  servo1.write(90);
  pinMode(buzzer, OUTPUT);
  pinMode(Camera, OUTPUT);
  pinMode(flame1, INPUT);
  pinMode(flame2, INPUT);
  pinMode(flame3, INPUT);
  pinMode(flame4, INPUT);
  pinMode(motion, INPUT);
  pinMode(gas, INPUT);
  pinMode(motion2, INPUT);
  pinMode(door2, INPUT);
  digitalWrite(buzzer , LOW);
  digitalWrite(Camera , HIGH);
}

void loop() {


  char key = keypad.getKey();
if (key != NO_KEY )
{
  switch (key)
  {
      delay(500);
    case '*' :
      i = 0 ;
      pass[0] = ' ';
      pass[1] = ' ';
      pass[2] = ' ';
      pass[3] = ' ';
      lcd.setCursor(0, 1);
      lcd.print("              ");
      break;

    case '#' :
      i = 0 ;
      if ( ( ddd[0] = pass[0]) && ( ddd[1] = pass[1] ) && ( ddd[2] = pass[2]) && ( ddd[3] = pass[3] ))
      {
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("Password Correct");
        for (int j = 0 ; j <= 5 ; j++)
          pass[j] = ' ' ;
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("              ");

        if (flag = 0)
          flag = 1 ;
        else flag = 0 ;

      }
      else {
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("Wrong Password");

        buzz();
        for (int j = 0 ; j <= 5 ; j++)
          pass[j] = ' ' ;
      }
      break ;

    default :
      {
        pass[i] = key ;
        i ++ ;
        Serial.print(pass);
        lcd.setCursor(0, 1);
        lcd.print("        ");
        lcd.setCursor(0, 1);
        lcd.print(pass);

        if (i > 3 ) i = 0 ;

      }
  }
}
else{

  if (analogRead(gas) <= 80 ) {
    digitalWrite(buzzer , HIGH);

    servo2.write(170);
    lcd.setCursor(0, 1);
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print("Gas Detected");
    buzz();
    lcd.setCursor(0, 1);
    lcd.print("               ");
    servo2.write(90);
  }



  if (analogRead(flame1) <= 80 ) {
    digitalWrite(buzzer , HIGH);
    digitalWrite(Camera , LOW);
    servo1.write(170);
    lcd.setCursor(0, 1);
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print("Flame In Kitchen");
    buzz();
    lcd.setCursor(0, 1);
    lcd.print("               ");
    servo1.write(90);
  }

  if (analogRead(flame2) <= 80 ) {
    digitalWrite(buzzer , HIGH);
    digitalWrite(Camera , LOW);
    servo1.write(120);
    lcd.setCursor(0, 1);
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print("Flame In Bedroom");
    buzz();
    lcd.setCursor(0, 1);
    lcd.print("               ");
    servo1.write(90);
  }

  if (analogRead(flame3) <= 80 ) {
    digitalWrite(buzzer , HIGH);
    digitalWrite(Camera , LOW);
    servo1.write(90);
    lcd.setCursor(0, 1);
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print("Flame In Hall");
    lcd.setCursor(0, 1);
    lcd.print("               ");

  }

  if (analogRead(flame4) <= 80 ) {
    digitalWrite(buzzer , HIGH);
    digitalWrite(Camera , LOW);
    servo1.write(45);
    lcd.setCursor(0, 1);
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print("Flame In Room2");

    lcd.setCursor(0, 1);
    lcd.print("               ");
    servo1.write(90);
  }




  if ( flag > 0 ) {

    if (digitalRead(motion) > 0 ) {
      digitalWrite(Camera , LOW);
      servo1.write(20);
      lcd.setCursor(0, 1);
      lcd.print("             ");
      lcd.setCursor(0, 1);
      lcd.print("Door 1 Open");
      buzz();
      lcd.setCursor(0, 1);
      lcd.print("             ");
      servo1.write(90);
    }
    if (digitalRead(motion2) > 0 ) {
      servo1.write(180);
      digitalWrite(Camera , LOW);
      lcd.setCursor(0, 1);
      lcd.print("             ");
      lcd.setCursor(0, 1);
      lcd.print("Door 2 Open");

      buzz();
      lcd.setCursor(0, 1);
      lcd.print("             ");
      servo1.write(90);
    }

  }
}

}


void buzz()
{
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);

}
