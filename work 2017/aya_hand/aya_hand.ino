#include <Servo.h>
Servo servo1 ,servo2 , servo3 , servo4 , servo5;

int a,b,c,d,e ;
int aa,bb,cc,dd,ee ;

void setup() {
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
servo1.attach(5);
servo2.attach(6);
servo3.attach(7);
servo4.attach(8);
servo5.attach(9);

}

void loop() {
a = analogRead(A0);
b = analogRead(A1);
c = analogRead(A2);
d = analogRead(A3);
e = analogRead(A4);
delay(100);
aa = map(a ,90,190 , 0 , 180 );
bb = map(b ,70,175 , 0 , 180 );
cc = map(c ,100,200 , 0 , 180 );
dd = map(d ,60,170 , 0 , 180 );
ee = map(e ,110,210 , 180 , 0 );

if (aa < 0 ) aa = 0 ;
if (bb < 0 ) bb = 0 ;
if (cc < 0 ) cc = 0 ;
if (dd < 0 ) dd = 0 ;
if (ee < 0 ) ee = 0 ;

if (aa > 180 ) aa = 180 ;
if (bb > 180 ) bb = 180 ;
if (cc > 180 ) cc = 180 ;
if (dd > 180 ) dd = 180 ;
if (ee > 180 ) ee = 180 ;

servo1.write(aa);
servo2.write(bb);
servo3.write(cc);
servo4.write(dd);
servo5.write(ee);
}
