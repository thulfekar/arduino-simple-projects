#include <Servo.h>
#define S0 12
#define S1 13
#define S2 4
#define S3 7
#define sensorOut 8
#define R1 5
#define R2 6
#define L1 10
#define L2 9
#define trig 14
#define echo 15
int frequency = 0;
int c = 0 ;
int red = 0;
int green = 0;
int blue = 0;
int dis , i;
Servo grab;
Servo tilt;
Servo scaner ;

void setup() {


  grab.attach(3);  // 100 open -- 125 -- 170 full closed
  tilt.attach(11); // 55 -- 100 up --- 20 down
  scaner.attach(2); // left 175 - 5 right
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  grab.write(120);
  tilt.write(100);
  scaner.write(90);
  Serial.begin(9600);
 
}


void loop()
{


seeking :

  scan();
  for (int f = 0 ; f <= 3 ; f++ ) {
    forward();
    delay(50);
    stopit();
    readcolor();
    if ((red > 100) || (blue > 100) || (green > 100) )
    {
      if (c < 1) {
        turnright();
        c = 1 ;
        goto seeking ;
      }
      if (c > 0 ) {
        turnleft();
        c = 0 ;
        goto seeking ;
      }
    }
    }

}
