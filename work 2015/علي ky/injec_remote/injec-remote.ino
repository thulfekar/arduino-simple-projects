#include <Keypad.h>
#include <LiquidCrystal.h>
#include <VirtualWire.h>
char *controller;
char keypress , key1 , keypress2 ;
int c , j;
LiquidCrystal lcd(19, 18, 17, 16, 15, 14);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns


char Keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
  lcd.setCursor(0, 0);
  lcd.print("Enter CC =      ");
  lcd.setCursor(0, 1);
  lcd.print("Enter Time =    ");
  j = 0 ;
}

void loop() {
  if (j < 1 ) {
    lcd.setCursor(11, 0);


    lcd.cursor();
  }
  if (j > 0 ) {
    lcd.setCursor(13, 1);


    lcd.cursor();
  }

  key1 = keypad.getKey();

  if (key1 == '*') {
    j = 0 ;
    Serial.println(key1);
    keypress = ' ' ;
    lcd.setCursor(11, 0);
    lcd.print ("    ");
    lcd.setCursor(13, 1);
    lcd.print ("    ");
  }


  if (key1 >= '0' ) {
    if (j < 1 ) {
      keypress = key1 ;
      lcd.setCursor(11, 0);
      lcd.print ("    ");
      lcd.setCursor(11, 0);
      lcd.print (keypress);
      j = 1 ;
    }
    else {
      j = 0 ;
      keypress2 = key1 ;
      lcd.setCursor(13, 1);
      lcd.print ("    ");
      lcd.setCursor(13, 1);
      lcd.print (keypress2);
    }
  }
  if (key1 == '#') {
    Serial.println(key1);

    if (keypress == '0' ) {

      controller = "0"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '1' ) {

      controller = "1"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '2' ) {

      controller = "2"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '3' ) {

      controller = "3"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '4' ) {

      controller = "4"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '5' ) {

      controller = "5"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '6' ) {

      controller = "6"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '7' ) {


      controller = "7"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '8' ) {


      controller = "8"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == '9' ) {


      controller = "9"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == 'A' ) {

      controller = "A"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }


    if (keypress == 'B' ) {


      controller = "B"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == 'C' ) {


      controller = "C"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }

    if (keypress == 'D' ) {


      controller = "D"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      digitalWrite(13, 1);
      delay(300);
    }
  }


}

