 
*/
int Keys = 0;
int Set = 2;
int Left = 6;
int Right = 5;
int Up = 4;
int Down = 3;
int incomingByte = 0;   // for incoming serial data
int MAX485 = 7;
void setup(){
pinMode(Set, INPUT_PULLUP);
pinMode(Right, INPUT_PULLUP);
pinMode(Left, INPUT_PULLUP);
pinMode(Up, INPUT_PULLUP);
pinMode(Down, INPUT_PULLUP);
pinMode(MAX485, OUTPUT);
Serial.begin(9600);
}
void loop() {

Keys = digitalRead(Set);
  if (Keys == LOW) {
    t_Set();
    delay(150);
  }
Keys = digitalRead(Right);
  if (Keys == LOW) {
    t_Right();
    delay(150);
  }
Keys = digitalRead(Left);
  if (Keys == LOW) {
    t_Left();
    delay(150);
  } 
Keys = digitalRead(Up);
  if (Keys == LOW) {
    t_Up();
    delay(150);
  }
Keys = digitalRead(Down);
  if (Keys == LOW) {
    t_Down();
    delay(150);
  }
// send data only when you receive data:
if (Serial.available() > 0) {
   // read the incoming byte:
   incomingByte = Serial.read();
   // send what you read
   digitalWrite(MAX485, HIGH);
   delay(6);
   Serial.write(incomingByte);
   delay(6);  
   digitalWrite(MAX485, LOW);
  
   }

}
void t_Set() {
   byte dataVal[7] ={0xFF, 0x01, 0x00, 0x03, 0x00, 0x5F, 0x63};   //This is the most basic instruction. Camera 1, four zeros and a check sum of one
     for(int i=0; i<7; i++){
     digitalWrite(MAX485, HIGH);
     delay(6);      
     Serial.write(dataVal[i]);
     delay(6);
     digitalWrite(MAX485, LOW);    
   }
}
void t_Right() {
   byte dataVal[7] ={0xFF, 0x01, 0x00, 0x02, 0x20, 0x00, 0x23};   //This is the most basic instruction. Camera 1, four zeros and a check sum of one
     for(int i=0; i<7; i++){
     digitalWrite(MAX485, HIGH);
     delay(6);      
     Serial.write(dataVal[i]);
     delay(6);
     digitalWrite(MAX485, LOW);    
   }
}
void t_Left() {
   byte dataVal[7] ={0xFF, 0x01, 0x00, 0x04, 0x20, 0x00, 0x25};   //This is the most basic instruction. Camera 1, four zeros and a check sum of one
     for(int i=0; i<7; i++){
     digitalWrite(MAX485, HIGH);
     delay(6);      
     Serial.write(dataVal[i]);
     delay(6);
     digitalWrite(MAX485, LOW);    
   }
}
void t_Up() {
   byte dataVal[7] ={0xFF, 0x01, 0x00, 0x08, 0x00, 0x20, 0x29};   //This is the most basic instruction. Camera 1, four zeros and a check sum of one
     for(int i=0; i<7; i++){
     digitalWrite(MAX485, HIGH);
     delay(6);      
     Serial.write(dataVal[i]);
     delay(6);
     digitalWrite(MAX485, LOW);    
   }
}
void t_Down() {
   byte dataVal[7] ={0xFF, 0x01, 0x00, 0x10, 0x00, 0x20, 0x31};   //This is the most basic instruction. Camera 1, four zeros and a check sum of one
     for(int i=0; i<7; i++){
     digitalWrite(MAX485, HIGH);
     delay(6);      
     Serial.write(dataVal[i]);
     delay(6);
     digitalWrite(MAX485, LOW);    
   }
}
//Code ends here
