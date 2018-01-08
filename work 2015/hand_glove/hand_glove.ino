#include <Servo.h>
Servo servo1 ;
Servo servo2 ;
Servo servo3 ;
Servo servo4 ;
Servo servo5 ;
int a1, a2, a3, a4, a5 ;

void setup() {
  // put your setup code here, to run once:

  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  servo5.attach(8);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  Serial.begin(9600);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(A1));
  Serial.print("     ");
  Serial.print(analogRead(A2));
  Serial.print("     ");
  Serial.print(analogRead(A3));
  Serial.print("     ");
  Serial.print(analogRead(A4));
  Serial.print("     ");
  Serial.println(analogRead(A5));
  Serial.print("     ");

  a1 = map (analogRead(A1) , 800 , 920 , 3 , 180 );
  a2 = map (analogRead(A2) , 800 , 920 , 3 , 180 );
  a3 = map (analogRead(A3) , 800 , 920 , 3 , 180 );
  a4 = map (analogRead(A4) , 800 , 920 , 3 , 180 );
  a5 = map (analogRead(A5) , 800 , 920 , 3 , 180 );


  servo1.write((180 - a1));
  servo2.write((180 - a2));
  servo3.write((180 - a3));
  servo4.write((180 - a4));
  servo5.write((180 - a5));

  delay(220);
}
