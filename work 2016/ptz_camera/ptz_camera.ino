#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(2400);


}
void loop() {
  // put your main code here, to run repeatedly:
delay(500);
t_Right();
delay(500);
t_Stop();
delay(500);
t_Left();
delay(500);
t_Stop();
}
void t_Right() {
  byte dataVal[7] = {0xFF, 0x01, 0x00, 0x02, 0x20, 0x00, 0x23};  //This is the most basic instruction. Camera 1, four zeros and a check sum of one

  for (int i = 0; i < 7; i++) {

    mySerial.write(dataVal[i]);

  }


}
void t_Left() {
  byte dataVal[7] = {0xFF, 0x01, 0x00, 0x04, 0x20, 0x00, 0x25};  //This is the most basic instruction. Camera 1, four zeros and a check sum of one

  for (int i = 0; i < 7; i++) {
    mySerial.write(dataVal[i]);
  }

}
void t_Up() {
  byte dataVal[7] = {0xFF, 0x01, 0x00, 0x08, 0x00, 0x20, 0x29};  //This is the most basic instruction. Camera 1, four zeros and a check sum of one
  for (int i = 0; i < 7; i++) {

    mySerial.write(dataVal[i]);

  }
}
void t_Down() {
  byte dataVal[7] = {0xFF, 0x01, 0x00, 0x10, 0x00, 0x20, 0x31};  //This is the most basic instruction. Camera 1, four zeros and a check sum of one
  for (int i = 0; i < 7; i++) {

    mySerial.write(dataVal[i]);

  }
}
void t_Stop() {
  byte dataVal[7] = {0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01};  //This is the most basic instruction. Camera 1, four zeros and a check sum of one
  for (int i = 0; i < 7; i++) {

    mySerial.write(dataVal[i]);

  }
}

