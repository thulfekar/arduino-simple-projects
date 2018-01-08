#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX pins
char command ;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop() {


  while (!Serial.available()) {
  }

  command = Serial.read();
  Serial.println(command);


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
    default :
      center();
  }


}
/* mySerial.print("#2P1250#3P1300#4P1700#5P1156#6P1700#7P1510#8P1800#9P1700#10P1813#11P1700#12P1700#14P1250#15P1300#16P1510#17P1250#18P1300T500\r\n");
  Serial.print("1");
  delay(500);
  mySerial.print("#1P1625#2P800#3P1200#4P1500#5P1156#6P1500#7P1510#8P2200#9P1800#10P1500#11P1700#12P1600#13P1600#14P800#15P1200#16P2000#17P1400#18P1500T500\r\n");
  Serial.print("2");

  delay(500);

  mySerial.print("#2P1375#3P1200#4P1500#5P1156#6P1500#7P1510#8P1719#9P1800#10P1500#11P1700#12P1600#14P1094#15P1200#16P2000#17P1400#18P1500T500\r\n");
  Serial.print("3");

  delay(500);

  mySerial.print("#2P1300#3P1200#4P2200#6P1800#8P1800#9P1600#10P1500#11P2200#12P1800#14P1200#15P1300#16P2000#17P800#18P1500T500\r\n");
  Serial.print("4");

  delay(500);

  mySerial.print("#2P1500#3P1600#4P2200#6P1800#7P1000#8P1600#9P1500#10P1800#11P2200#12P1800#14P1100#15P1200#16P1500#17P800#18P1200T500\r\n");
  Serial.print("5");

  delay(500);

  mySerial.print("#1P1625#2P1500#3P1600#4P1531#5P1063#6P1800#7P1000#8P1600#9P1500#10P1800#11P1719#12P1800#13P1600#14P1100#15P1200#16P1500#17P1438#18P1200T500\r\n");
  Serial.print("6");

  delay(500);

  mySerial.print("#7P1594#8P2063T500\r\n");
  Serial.print("7");

  delay(500);

  int x ;
  for (x = 1 ; x <= 18 ; x++ ){
  Serial.print(x);
  delay(500);
  mySerial.print("#");
  mySerial.print(x);
  mySerial.print("P1000T500\r\n");


  delay(2000);
  mySerial.print("#");
  mySerial.print(x);
  mySerial.print("P1500T500\r\n");
  }



  }

  void forward() {
  mySerial.print("#17P1264#18P1264#4P1864#6P1864T500\r\n");
  mySerial.print("#16P1264#5P1864T500\r\n");
  mySerial.print("#17P1864#18P1864#4P1264#6P1264#4P1864#6P1864T500\r\n");


  mySerial.print("#3P1294#18P1264#15P1264#2P1294#17P1264#14P1264T500\r\n");
  delay(2000);


  }
*/
void forward() {
  mySerial.print("#2P1064#3P1264#8P2064#9P1864#14P1064#15P1264T500\r\n");
  delay(500);
  mySerial.print("#1P1064#13P1564#7P1664T500\r\n");
  delay(500);
  mySerial.print("#2P2064#3P1864#8P1064#9P1264#14P2064#15P1864T500\r\n");
  delay(500);
  mySerial.print("#1P1300#13P1700#7P1500#17P1064#18P1264#4P2064#6P1864#11P2064#12P1864T500\r\n");
  delay(500);
  mySerial.print("#16P1364#5P2064#10P1604T500\r\n");
  delay(500);
  mySerial.print("#17P2064#18P1864#4P1064#6P1264#11P1064#12P1264T500\r\n");
  delay(500);
  mySerial.print("#16P1500#5P1700#10P1300#2P1064#3P1264#8P2064#9P1864#14P1064#15P1264T500\r\n");
  delay(500);


}

void back() {
  mySerial.print("#2P1064#3P1264#8P2064#9P1864#14P1064#15P1264T500\r\n");
  delay(500);
  mySerial.print("#1P1664#13P2064#7P1264T500\r\n");
  delay(500);
  mySerial.print("#2P2064#3P1864#8P1064#9P1264#14P2064#15P1864T500\r\n");
  delay(500);
  mySerial.print("#1P1300#13P1500#7P1500#17P1064#18P1264#4P2064#6P1864#11P2064#12P1864T500\r\n");
  delay(500);
  mySerial.print("#16P1664#5P1364#10P1064T500\r\n");
  delay(500);
  mySerial.print("#17P2064#18P1864#4P1064#6P1264#11P1064#12P1264T500\r\n");
  delay(500);
  mySerial.print("#16P1500#5P1500#10P1300#2P1064#3P1264#8P2064#9P1864#14P1064#15P1264T500\r\n");
  delay(500);


}

void right() {
  mySerial.print("#2P1264#3P1264#11P1864#12P1864T500\r\n");
  delay(500);
  mySerial.print("#1P1064#10P1064T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1864#11P1264#12P1264T500\r\n");
  delay(500);
  mySerial.print("#17P1264#18P1264#8P1864#9P1864T500\r\n");
  delay(500);
  mySerial.print("#16P1164#7P1164T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1864#8P1264#9P1264T500\r\n");
  delay(500);
  mySerial.print("#14P1264#15P1264#4P1864#6P1864T500\r\n");
  delay(500);
  mySerial.print("#13P1164#5P1164T500\r\n");
  delay(500);
  mySerial.print("#14P1864#15P1864#4P1264#6P1264T500\r\n");
  delay(500);
  center();

}

void left() {
  mySerial.print("#14P1264#15P1264#4P1864#6P1864T500\r\n");
  delay(500);
  mySerial.print("#13P2064#5P2064T500\r\n");
  delay(500);
  mySerial.print("#14P1864#15P1864#4P1264#6P1264T500\r\n");
  delay(500);
  mySerial.print("#17P1264#18P1264#8P1864#9P1864T500\r\n");
  delay(500);
  mySerial.print("#16P1964#7P1964T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1864#8P1264#9P1264T500\r\n");
  delay(500);
  mySerial.print("#2P1264#3P1264#11P1864#12P1864T500\r\n");
  delay(500);
  mySerial.print("#1P1964#10P1964T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1864#11P1264#12P1264T500\r\n");
  delay(500);
  center();

}
void sleep() {
  mySerial.print("#1P1500#2P1000#3P1500#4P2000#5P1500#6P1500#7P1500#8P2000#9P1500#10P1500#11P2000#12P1500#13P1500#14P1000#15P1500#16P1500#17P1000#18P1500T500\r\n");

}
void center() {
  mySerial.print("#1P1500#2P1500#3P1500#4P1500#5P1500#6P1500#7P1500#8P1500#9P1500#10P1500#11P1500#12P1500#13P1500#14P1500#15P1500#16P1500#17P1500#18P1500T500\r\n");
}

void forleg1() {
  mySerial.print("#2P1264#3P1264T500\r\n");
  delay(500);
  mySerial.print("#1P1264T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1864T500\r\n");
  delay(500);
  mySerial.print("#1P1664T500\r\n");
  delay(500);

}
void backleg1() {
  mySerial.print("#2P1264#3P1264T500\r\n");
  delay(500);
  mySerial.print("#1P1664T500\r\n");
  delay(500);
  mySerial.print("#2P1864#3P1864T500\r\n");
  delay(500);
  mySerial.print("#1P1264T500\r\n");
  delay(500);

}

void forleg2() {
  mySerial.print("#17P1264#18P1264T500\r\n");
  delay(500);
  mySerial.print("#16P1264T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1864T500\r\n");
  delay(500);
  mySerial.print("#16P1664T500\r\n");
  delay(500);

}
void backleg2() {
  mySerial.print("#17P1264#18P1264T500\r\n");
  delay(500);
  mySerial.print("#16P1664T500\r\n");
  delay(500);
  mySerial.print("#17P1864#18P1864T500\r\n");
  delay(500);
  mySerial.print("#16P1264T500\r\n");
  delay(500);

}
void forleg3() {
  mySerial.print("#14P1264#15P1264T500\r\n");
  delay(500);
  mySerial.print("#13P1264T500\r\n");
  delay(500);
  mySerial.print("#14P1864#15P1864T500\r\n");
  delay(500);
  mySerial.print("#13P1664T500\r\n");
  delay(500);

}
void backleg3() {
  mySerial.print("#14P1264#15P1264T500\r\n");
  delay(500);
  mySerial.print("#13P1664T500\r\n");
  delay(500);
  mySerial.print("#14P1864#15P1864T500\r\n");
  delay(500);
  mySerial.print("#13P1264T500\r\n");
  delay(500);

}
void forleg4() {
  mySerial.print("#4P1864#6P1864T500\r\n");
  delay(500);
  mySerial.print("#5P1664T500\r\n");
  delay(500);
  mySerial.print("#4P1264#6P1264T500\r\n");
  delay(500);
  mySerial.print("#5P1264T500\r\n");
  delay(500);

}
void backleg4() {
  mySerial.print("#4P1864#6P1864T500\r\n");
  delay(500);
  mySerial.print("#5P1264T500\r\n");
  delay(500);
  mySerial.print("#4P1264#6P1264T500\r\n");
  delay(500);
  mySerial.print("#5P1664T500\r\n");
  delay(500);

}

void forleg5() {
  mySerial.print("#8P1864#9P1864T500\r\n");
  delay(500);
  mySerial.print("#7P1664T500\r\n");
  delay(500);
  mySerial.print("#8P1264#9P1264T500\r\n");
  delay(500);
  mySerial.print("#7P1264T500\r\n");
  delay(500);

}
void backleg5() {
  mySerial.print("#8P1864#9P1864T500\r\n");
  delay(500);
  mySerial.print("#7P1264T500\r\n");
  delay(500);
  mySerial.print("#8P1264#9P1264T500\r\n");
  delay(500);
  mySerial.print("#7P1664T500\r\n");
  delay(500);

}
void forleg6() {
  mySerial.print("#11P1864#12P1864T500\r\n");
  delay(500);
  mySerial.print("#10P1664T500\r\n");
  delay(500);
  mySerial.print("#11P1264#12P1264T500\r\n");
  delay(500);
  mySerial.print("#10P1264T500\r\n");
  delay(500);

}
void backleg6() {
  mySerial.print("#11P1864#12P1864T500\r\n");
  delay(500);
  mySerial.print("#10P1264T500\r\n");
  delay(500);
  mySerial.print("#11P1264#12P1264T500\r\n");
  delay(500);
  mySerial.print("#10P1664T500\r\n");
  delay(500);

}



//1264
//1894
