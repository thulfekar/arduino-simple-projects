#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN   9
#define CSN_PIN 10


const uint64_t ch1 =  0x7878787878LL ;
const uint64_t ch2 =  0xB3B4B5B6F1LL ;
const uint64_t ch3 =  0xB3B4B5B6CDLL ;
const uint64_t ch4 =  0xB3B4B5B6A3LL ;
const uint64_t chc =  0xE8E8F0F0E5LL ;
float t , msg , count ;

RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1 , ch4);
  radio.startListening();
  pinMode(5, INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);

  pinMode(8 , OUTPUT);
  digitalWrite(8 , LOW );


}

void loop() {


  
  while (radio.available()) {

    radio.read( &msg, sizeof(msg) );
    if (msg > 50 ) {
      Serial.println(msg);
      t = millis();
      digitalWrite( 8 , HIGH );
lop:
      count = millis() - t ;
      if (digitalRead(5) < 1 ) {
        digitalWrite(8 , LOW );
        for(int lc = 0 ; lc <= 100 ; lc++ ){
        radio.stopListening(); //go into transmit mode
        radio.openWritingPipe(ch4);
        radio.write( &count, sizeof(count) );
        }
        pinMode(4,OUTPUT);
digitalWrite(4,LOW);
      }
      goto lop;

    }
    if (msg < 40 ) {
       t = millis();
lop1:
      count = millis() - t ;
      if (digitalRead(5) < 1 ) {
        for(int lc = 0 ; lc <= 100 ; lc++ ){
        radio.stopListening(); //go into transmit mode
        radio.openWritingPipe(ch4);
        radio.write( &count, sizeof(count) );
        }
       pinMode(4,OUTPUT);
digitalWrite(4,LOW); 
      }
      goto lop1;

    }

  }


}


