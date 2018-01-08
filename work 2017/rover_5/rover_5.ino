#include <Servo.h>
#include <PPMrcIn.h>
#include <Statistic.h>
#define R1 4
#define R2 5
#define L1 7
#define L2 6
Servo tilt;
Servo turn;
Servo grip;
Servo slash;
Servo saw;

Channel channel1;
Channel channel2;
Channel channel3;
Channel channel4;
Channel channel5;
Channel channel6;
int Distance = 0;
int a, b, c, d, e, f ;
int t = 0 ;
int ti = 90 ;
int tu = 90 ;
int gr = 90 ;
int sl = 90 ;
int sw = 0 ;
int sla = 180;
int aa = 1000 ;
int cc = 1000 ;
int dd = 1000 ;
int ee = 1000 ;
int ff = 1000 ;
void setup() {


  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  tilt.attach(8);
  turn.attach(9);
  grip.attach(10);
  slash.attach(11);
  saw.attach(12);

  Serial.begin(9600);
  delay(1000);
  Serial.println("Ready:");

  tilt.write(90);
  turn.write(160);
  grip.write(80);
  slash.write(170);
  saw.write(40);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
  pinMode (A4, INPUT);
  pinMode (A5, INPUT);

  channel1.init(1, A0);
  channel2.init(1, A1);
  channel3.init(1, A2);
  channel4.init(1, A3);
  channel5.init(1, A4);
  channel6.init(1, A5);

}

void loop() {
  t++ ;

  if (t == 100) {
    channel1.readSignal();
    a = channel1.getSignal();
    delayMicroseconds(4750);
  }
  if (t == 200) {
    channel2.readSignal();
    b = channel2.getSignal();
    delayMicroseconds(4750);
  }
  if (t == 300) {
    channel3.readSignal();
    c = channel3.getSignal();
    delayMicroseconds(4750);
  }
  if (t == 400) {
    channel4.readSignal();
    d = channel4.getSignal();
    delayMicroseconds(4750);
  }
  if (t == 500) {
    channel5.readSignal();
    e = channel5.getSignal();
    delayMicroseconds(4750);
  }
  if (t == 600) {
    channel6.readSignal();
    f = channel6.getSignal();
  }
  if (t >= 1010) {
    t = 0 ;

    Serial.print("  a = ");
    Serial.print(a);

    Serial.print("  b = ");
    Serial.print(b);

    Serial.print("  c = ");
    Serial.print(c);

    Serial.print("  d = ");
    Serial.print(d);

    Serial.print("  e = ");
    Serial.print(e);

    Serial.print("  f = ");
    Serial.println(f);

  }

  if ((a < 100 ) || (b < 100 ) || (c < 100 ) || (d < 100 ) || (e < 100 ) || (f < 100 ) ) return;


  if (b <= 1200 ) {
    if (e >= 1700 ) forward();
    else if (e <= 1200 ) back();
    else if (f >= 1700 )left();
    else if (f <= 1200 )right();
    else stopit();
  }

  if (b >= 1700 ) {
    if (e >= 1700 ) saw.write(135);
    else if (e <= 1200 ) saw.write(40);
    if (f <= 1200 ) {
      sla = sla - 2 ;
      if (sla <= 50 ) sla = 50 ; 
      slash.write(sla);
      f = 1250 ;
    }
    else if (f >= 1300) {
      sla = 170 ;
      slash.write(170);
    }
  }


  if ((c - cc ) > 20  || (cc - c ) > 20 ) {
    ti = map (c , 1000 , 1900 , 160 , 60 );
    tilt.write(ti);
    Serial.println(ti);
    cc = c ;
  }

    if ((d - dd ) > 20  || (dd - d ) > 20 ) {
    tu = map (d , 1000 , 1900 , 160 , 60 );
    turn.write(tu);
    Serial.println(tu);
    dd = d ;
  }
/*
  if (d >= 1700 ) {
    tu = tu + 10 ;
    if (tu >= 170) tu = 170;
    //  tu = map (c , 1000 , 1900 , 10 , 170 );
    turn.write(tu);
    Serial.println(tu);
    dd = d ;
    d = 1500;
  }

  if (d <= 1200 ) {
    tu = tu - 10 ;
    if (tu <= 10) tu = 10;
    //  tu = map (c , 1000 , 1900 , 10 , 170 );
    turn.write(tu);
    Serial.println(tu);
    dd = d ;
    d = 1500 ;
  }

*/




  if ((a - aa ) > 20  || (aa - a ) > 20 ) {
    gr = map(a , 900 , 2000 , 30 , 110 );
    grip.write(gr);
    aa = a ;
  }

}

