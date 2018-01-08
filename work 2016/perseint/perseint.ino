#include <Servo.h>
Servo servo1 ;
Servo servo2 ;
Servo servo3 ;
Servo servo4 ;
Servo servo5 ;
Servo servo6 ;
int s[7] ;
char inc ;
int a, b, c, d, i, x, y ;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo5.attach(7);
  servo6.attach(8);
  Serial.begin(115200);
  delay(1000);
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(120);
  servo5.write(120);
  servo6.write(75);
  delay(1000);
  pinMode( A0 , INPUT);
  s[1] = 90 ;
  s[2] = 90;
  s[3] = 90;
  s[4] = 120;
  s[5] = 120;
  s[6] = 75;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial.available()) {
       
      }

  inc = Serial.read();



  if (inc == '#') {

    x = Serial.parseInt();
   
  }

  if (inc == 'P') {
    y = Serial.parseInt();
  }

  s[(x+1)] = map (y, 500, 2500 , 10 , 170 ) ;

  
  if  (inc == 'T' ) {
    a = map(s[6] , 10 , 170 , 20 , 77);
    b = map(s[4] , 10 , 170 , 70 , 140);
    servo1.write(s[1]);
    servo2.write(s[2]);
    servo3.write(s[3]);
    servo4.write(b);
    servo5.write(s[5]);
    servo6.write(a);
    Serial.print("  servo1 = ");
    Serial.print(a);
    Serial.print("  servo2 = ");
    Serial.print(s[2]);
    Serial.print("  servo3 = ");
    Serial.print(s[3]);
    Serial.print("  servo4 = ");
    Serial.print(s[4]);
    Serial.print("  servo5 = ");
    Serial.print(s[5]);
    Serial.print("  servo6 = ");
    Serial.println(s[6]);
  }
}
