#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define CE_PIN   9
#define CSN_PIN 10
#define num1   A0
#define num2   A1
#define num3   A2
#define num4   A3

const uint64_t ch1 =  0x7878787878LL ;
const uint64_t ch2 =  0xB3B4B5B6F1LL ;
const uint64_t ch3 =  0xB3B4B5B6CDLL ;
const uint64_t ch4 =  0xB3B4B5B6A3LL ;
const uint64_t chc =  0xE8E8F0F0E5LL ;
int trans , x , y , z ;
float t , msg , count ;
float msg1 = 10 ;
float msg2 = 100 ;
RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  randomSeed(analogRead(0));
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  radio.begin();
  radio.stopListening(); //go into transmit mode
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(num1 , OUTPUT);
  pinMode(num2 , OUTPUT);
  pinMode(num3 , OUTPUT);
  pinMode(num4 , OUTPUT);
  for(int lc = 0 ; lc <= 10 ; lc ++ ) {
    lcd.setCursor(0, 0);
    lcd.print(" SPORT  COUNTER ");
    lcd.setCursor(0, 1);
    lcd.print(" TIME = ");
    delay(100);
  }
}

void loop() {

  int type = digitalRead(5);
  int no[9] = { 1, 2, 3, 4, 1, 2, 3, 4  };
  int c = 0 ;


looping:
  radio.stopListening(); //go into transmit mode

  if (digitalRead(6) < 1 ) {
    c = c + 1 ;
    int g = (int)random(0 - 9);
    if ((no[g] < 9 ) && ( no[g] > 0 )) {
      Serial.println(no[g]);
      trans = no[g] ;
      no[g] = 100 ;
      lcd.setCursor(0, 0);
      lcd.print("  SET: ");
      lcd.print(c);

      switch (trans) {
      case 1 :
        if (type < 1 ) {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch1);
            radio.write( &msg1, sizeof(msg1) );
            digitalWrite(num1 , HIGH );
          }
          digitalWrite(num1 , LOW );
        }
        else {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch1);
            radio.write( &msg2, sizeof(msg2) );
          }
        }
        radio.openReadingPipe(1 , ch1);
        radio.startListening();
        t = millis() ;
        while (!radio.available()) {
          count = millis() - t ;
          lcd.setCursor(0, 1);
          lcd.print(" TIME = ");
          lcd.setCursor(9, 1);
          lcd.print(count);
        }
        radio.read( &msg, sizeof(msg) );
        lcd.setCursor(9, 1);
        lcd.print(msg);

        break;



      case 2 :
        if (type < 1 ) {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch2);
            radio.write( &msg1, sizeof(msg1) );
            digitalWrite(num2 , HIGH );
          }
          digitalWrite(num2 , LOW );
        }
        else {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch2);
            radio.write( &msg2, sizeof(msg2) );
          }
        }
        radio.openReadingPipe(1 , ch2);
        radio.startListening();
        t = millis() ;
        while (!radio.available()) {
          count = millis() - t ;
          lcd.setCursor(0, 1);
          lcd.print(" TIME = ");
          lcd.setCursor(9, 1);
          lcd.print(count);
        }
        radio.read( &msg, sizeof(msg) );
        lcd.setCursor(9, 1);
        lcd.print(msg);

        break;


      case 3 :
        if (type < 1 ) {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch3);
            radio.write( &msg1, sizeof(msg1) );
            digitalWrite(num3 , HIGH );
          }
          digitalWrite(num3 , LOW );
        }
        else {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch3);
            radio.write( &msg2, sizeof(msg2) );
          }
        }
        radio.openReadingPipe(1 , ch3);
        radio.startListening();
        t = millis() ;
        while (!radio.available()) {
          count = millis() - t ;
          lcd.setCursor(0, 1);
          lcd.print(" TIME = ");
          lcd.setCursor(9, 1);
          lcd.print(count);
        }
        radio.read( &msg, sizeof(msg) );
        lcd.setCursor(9, 1);
        lcd.print(msg);

        break;







      case 4 :
        if (type < 1 ) {
          t =  millis();
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch4);
            radio.write( &msg1, sizeof(msg1) );
            digitalWrite(num4 , HIGH );
          }
          digitalWrite(num4 , LOW );
        }
        else {
          t =  millis() ;
          while ((millis() - t) < 100 ) {
            radio.openWritingPipe(ch4);
            radio.write( &msg2, sizeof(msg2) );
          }
        }
        radio.openReadingPipe(1 , ch4);
        radio.startListening();
        t = millis() ;
        while (!radio.available()) {
          count = millis() - t ;
          lcd.setCursor(0, 1);
          lcd.print(" TIME = ");
          lcd.setCursor(9, 1);
          lcd.print(count);
        }
        radio.read( &msg, sizeof(msg) );
        lcd.setCursor(9, 1);
        lcd.print(msg);

        break;


      }



    }

  }

  goto looping;


}


