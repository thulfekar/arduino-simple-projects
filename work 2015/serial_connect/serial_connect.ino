#include <SoftwareSerial.h>
SoftwareSerial esp(2, 3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  esp.begin(38400);
   
}


void loop() {
  // put your main code here, to run repeatedly:
if (esp.available())

Serial.write(esp.read());

if (Serial.available())

esp.write(Serial.read());

}
