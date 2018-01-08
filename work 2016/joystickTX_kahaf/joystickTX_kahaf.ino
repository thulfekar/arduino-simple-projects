#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL; 

RF24 radio(CE_PIN, CSN_PIN); 
int joystick[9]; 


void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
pinMode (A0 , INPUT);
pinMode (A1 , INPUT);
for (int g = 2 ; g <= 8 ; g++ ){
  pinMode(g , INPUT );
  digitalWrite(g , LOW);
}
 
 }

void loop()  
{
  joystick[0] = analogRead(A0);
  joystick[1] = analogRead(A1);
  joystick[2] = digitalRead(2);
  joystick[3] = digitalRead(3);
  joystick[4] = digitalRead(4);
  joystick[5] = digitalRead(5);
  joystick[6] = digitalRead(6);
  joystick[7] = digitalRead(7);
  joystick[8] = digitalRead(8);  


  radio.write( joystick, sizeof(joystick) );

  
  
  Serial.print("X = ");
  Serial.print(analogRead(A0));
  Serial.print(" Y = ");
  Serial.print(analogRead(A1));
  Serial.print(" Up = ");
  Serial.print(digitalRead(2));
  Serial.print(" Right = ");
  Serial.print(digitalRead(3));
  Serial.print(" Down = ");
  Serial.print(digitalRead(4));
  Serial.print(" Left = ");
  Serial.print(digitalRead(5));
  Serial.print(" start = ");
  Serial.print(digitalRead(6));
  Serial.print(" select = ");
  Serial.print(digitalRead(7));
   Serial.print(" push = ");
  Serial.println(digitalRead(8));

}
