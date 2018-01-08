#include <AFMotor.h>
#include <Servo.h>
#define fr 14
#define br 15
#define ax 19
#define bx 18
#define cx 17
#define dx 16


AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);
Servo servo;
int a, b, c, d, e, f ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(10);
  pinMode(fr, INPUT);
  pinMode(br, INPUT);
  pinMode(ax, INPUT);
  pinMode(bx, INPUT);
  pinMode(cx, INPUT);
  pinMode(dx, INPUT);

  m1.setSpeed(200);
  m1.run(RELEASE);
  m2.setSpeed(200);
  m2.run(RELEASE);
  m3.setSpeed(200);
  m3.run(RELEASE);
  m4.setSpeed(200);
  m4.run(RELEASE);


  c = 0 ;
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("fr= ");
  Serial.print(digitalRead(fr));
  Serial.print("br= ");
  Serial.print(digitalRead(br));
  Serial.print("ax= ");
  Serial.print(digitalRead(ax));
  Serial.print("bx= ");
  Serial.print(digitalRead(bx));
  Serial.print("cx= ");
  Serial.print(digitalRead(cx));
  Serial.print("dx= ");
  Serial.println(digitalRead(dx));

  if ((digitalRead(ax) > 0 ) && (c < 1) ) {

    c++;
first:
    forw();
    delay(5);
    stopit();
    delay(4);

    if (digitalRead(fr) < 1 )goto first;
    stopit();
    delay(1500);
    right();
    delay(1100);
    stopit();
    delay(1000);
scnd:
    forw();
    delay(5);
    stopit();
    delay(4);

    if (digitalRead(fr) < 1 )goto scnd;
    stopit();
    delay(1500);
    right();
    delay(1100);
    stopit();
    delay(1000);
thrd:
    forw();
    delay(5);
    stopit();
    delay(4);

    if (digitalRead(fr) < 1 )goto thrd;
    stopit();
  }
  if ((digitalRead(ax) > 0 ) && (c > 0 ) && (c < 2 )) {
    c++;

    left();
    delay(1100);
    stopit();
    delay(1000);
frth:
    forw();
    delay(5);
    stopit();
    delay(4);

    if (digitalRead(fr) < 1 )goto frth;
    stopit();
    delay(1500);
    left();
    delay(1100);
    stopit();
    delay(1000);
fifth:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto fifth;
    stopit();
    delay(1500);
    right();
    delay(1100);
    stopit();
    delay(1000);
sixth:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto sixth;
    stopit();
    for (int i = 0 ; i < 70 ; i++) {
      forw();
      delay(5);
      stopit();
      delay(4);
    }
sixtht:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto sixtht;
    stopit();
    delay(1500);
    right();
    delay(1500);
    stopit();
    delay(1000);
    forw();
    delay(500);
    stopit();
  }
  if ((digitalRead(ax) > 0 ) && (c > 1 ) && (c < 3 )) {
    c++;
    left();
    delay(1100);
    stopit();
    delay(1000);
seventh:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto seventh;
    stopit();
  }
  if ((digitalRead(ax) > 0 ) && (c > 2 ) && (c < 4 )) {
    c++;
eght:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto eght;
    stopit();
  }

  if ((digitalRead(ax) > 0 ) && (c > 3 ) && (c < 5 )) {
    c++;
    left();
    delay(1500);
    stopit();
    delay(1000);
    forw();
    delay(500);
    stopit();
    delay(1000);
    right();
    delay(1500);
    stopit();
    delay(1000);
nin:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto nin;
    stopit();
    delay(1000);
    left();
    delay(1500);
    stopit();
    delay(1000);
ten:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto ten;
    stopit();
    delay(1000);
    left();
    delay(1500);
    stopit();
    delay(1000);
    for (int j = 0 ; j < 70 ; j++) {
      forw();
      delay(5);
      stopit();
      delay(4);
    }
  }
  if ((digitalRead(ax) > 0 ) && (c > 4 ) && (c < 6 )) {
    c++;
twelv:
    forw();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(fr) < 1 )goto twelv;
    stopit();

  }





  if ((digitalRead(dx) > 0 ) && (c > 5 ) && (c < 7 )) {
    c--;
bone:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bone;
    stopit();
  }

  if ((digitalRead(dx) > 0 ) && (c > 4 ) && (c < 6 )) {
    c--;
bonee:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bonee;
    stopit();
    delay(1000);
    right();
    delay(1300);
    stopit();
    delay(1000);
btwo:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto btwo;
    stopit();
    delay(1000);
    right();
    delay(1300);
    stopit();
    delay(1000);
bthr:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bthr;
    stopit();
    for (int y = 0 ; y < 70 ; y ++ ) {
      back();
      delay(5);
      stopit();
      delay(4);
    }
bfr:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bfr;
    stopit();
    delay(1000);
    left();
    delay(1300);
    stopit();
    delay(500);
    back();
    delay(400);
    stopit();
    delay(1000);
    right();
    delay(1300);
    stopit();
  }

  if ((digitalRead(dx) > 0 ) && (c > 3 ) && (c < 5 )) {
    c--;
    c--;
bsx:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bsx;
    stopit();
    delay(1000);
    right();
    delay(1300);
    stopit();

  }

  if ((digitalRead(dx) > 0 ) && (c > 1 ) && (c < 3 )) {
    c--;
    back();
    delay(400);
    stopit();
    delay(1000);
bfth:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bfth;
    stopit();
    delay(1000);
    left();
    delay(1300);
bfh:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bfh;
    for(int f = 0 ; f < 50 ; f++ ){
       back();
    delay(5);
    stopit();
    delay(4);
    }
    stopit();
    delay(1000);
    left();
    delay(1300);
    stopit();
    delay(1000);
bfhgg:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto bfhgg;
    stopit();
    delay(1000);

    right();
    delay(1300);
    stopit();
    delay(1000);

blas:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto blas;
    stopit();
    delay(1000);
    right();
    delay(1300);
    stopit();
    

  }
  if ((digitalRead(dx) > 0 ) && (c < 2 ) && ( c > 0 ) ) {
    c--;
blass:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto blass;
    stopit();
    delay(1000);
    left();
    delay(1300);
    stopit();
    delay(1000);
blast:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto blast;
    stopit();
     delay(1000);
    left();
    delay(1300);
    stopit();
    delay(1000);
blasft:
    back();
    delay(5);
    stopit();
    delay(4);
    if (digitalRead(br) < 1 )goto blasft;
    stopit();

  }



}



void stopit() {
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}
void forw() {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}
void back() {
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}
void left() {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}
void right() {
  m3.run(FORWARD);
  m4.run(FORWARD);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
}

