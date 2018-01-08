#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX pins
char command ;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop() {


  while (!Serial.available()) 
  {  }

  command = Serial.read();


  switch (command) {
    case 'A' :
      forward();
      break;


    case 'B' :
      back();
      break;

    case 'C' :
      left();
      break;

    case 'D' :
      right();
      break;
      
       case 'X' :
      center();
      break;
      
    default :;
    
  }

command = 'f' ;
}
void forward() {
  mySerial.print("#2P1264#3P1464#8P1864#9P1664#14P1264#15P1464T500\r\n");
  delay(500);
  mySerial.print("#1P1064#13P1564#7P1664T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1664#8P1264#9P1364#14P1864#15P1664T500\r\n");
  delay(500);
  mySerial.print("#1P1300#13P1700#7P1500#17P1264#18P1464#4P1864#6P1664#11P1864#12P1664T500\r\n");
  delay(500);
  mySerial.print("#16P1364#5P2064#10P1604T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1664#4P1264#6P1464#11P1264#12P1464T500\r\n");
  delay(500);
  mySerial.print("#16P1500#5P1700#10P1300#2P1264#3P1464#8P1864#9P1664#14P1264#15P1464T500\r\n");
  delay(500);


}

void back() {
  mySerial.print("#2P1264#3P1464#8P1864#9P1664#14P1264#15P1464T500\r\n");
  delay(500);
  mySerial.print("#1P1664#13P2064#7P1264T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1664#8P1264#9P1364#14P1864#15P1664T500\r\n");
  delay(500);
  mySerial.print("#1P1300#13P1500#7P1500#17P1264#18P1464#4P2264#6P1664#11P1864#12P1664T500\r\n");
  delay(500);
  mySerial.print("#16P1664#5P1364#10P1064T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1664#4P1264#6P1464#11P1264#12P1464T500\r\n");
  delay(500);
  mySerial.print("#16P1500#5P1500#10P1300#2P1264#3P1464#8P1864#9P1664#14P1264#15P1464T500\r\n");
  delay(500);


}

void right() {
  mySerial.print("#2P1264#3P1464#11P1864#12P1664T500\r\n");
  delay(500);
  mySerial.print("#1P1164#10P1164T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1664#11P1264#12P1464T500\r\n");
  delay(500);
  mySerial.print("#17P1264#18P1464#8P1864#9P1664T500\r\n");
  delay(500);
  mySerial.print("#16P1164#7P1164T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1664#8P1264#9P1464T500\r\n");
  delay(500);
  mySerial.print("#14P1264#15P1464#4P1864#6P1664T500\r\n");
  delay(500);
  mySerial.print("#13P1164#5P1164T500\r\n");
  delay(500);
  mySerial.print("#14P1864#15P1664#4P1264#6P1464T500\r\n");
  delay(500);
  center();
  delay(1000);
  

}

void left() {
  mySerial.print("#14P1264#15P1464#4P1864#6P1664T500\r\n");
  delay(500);
  mySerial.print("#13P1964#5P1964T500\r\n");
  delay(500);
  mySerial.print("#14P1864#15P1664#4P1264#6P1464T500\r\n");
  delay(500);
  mySerial.print("#17P1264#18P1464#8P1864#9P1664T500\r\n");
  delay(500);
  mySerial.print("#16P1964#7P1964T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1664#8P1264#9P1464T500\r\n");
  delay(500);
  mySerial.print("#2P1264#3P1464#11P1864#12P1664T500\r\n");
  delay(500);
  mySerial.print("#1P1964#10P1964T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1664#11P1264#12P1464T500\r\n");
  delay(500);
  center();
  delay(1000);
  

}
void center() {
  mySerial.print("#1P1500#2P1500#3P1500#4P1500#5P1500#6P1500#7P1500#8P1500#9P1500#10P1500#11P1500#12P1500#13P1500#14P1500#15P1500#16P1500#17P1500#18P1500T500\r\n");
delay(1000);
}

