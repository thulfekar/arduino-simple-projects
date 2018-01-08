#include <Servo.h>
#include <PPMrcIn.h>
#include <Statistic.h>

Channel channel1;
Channel channel2;



int a, b, g, h, j, k, t ;

void setup() {

  Serial.begin(19200);
  delay(1000);
  Serial.println("Ready:");
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);


  channel1.init(1, A0);
  channel2.init(1, A1);


}

void loop() {
  t++ ;

  if (t == 100) {
    channel1.readSignal();
    a = channel1.getSignal();
    delayMicroseconds(4750);
  }
  if (t == 50) {
    channel2.readSignal();
    b = channel2.getSignal();
    delayMicroseconds(4750);
  }

  if (t >= 800) {
    t = 0 ;
    Serial.print("  g = ");
    Serial.print(a);
    Serial.print("  h = ");
    Serial.println(b);
  }


  g = map ( b , 1100 , 1900 , 0, 100 );
  h = map ( a , 950 , 1900 , 0, 100 );

  if ( g < 0 ) g = 0 ;
  if ( h < 0 ) h = 0 ;
  if ( g > 100 ) g = 100 ;
  if ( h > 100 ) h = 100 ;

  if (( a < 1 ) && ( b < 1 ) ) {
    analogWrite(6, 0);
    analogWrite(5, 0);
    analogWrite(10, 0);
    analogWrite(9, 0);
    return;
  }

  if  ( h > 60 ) {
    k =  map ( h , 60 , 100 , 100 , 255 );

    analogWrite(6, k);
    analogWrite(5, 0);
    analogWrite(10, 0);
    analogWrite(9, k);
    return;
  }
  else if ( h < 40 ) {
    k =  map ( h , 40 , 0 , 100 , 255 );
    analogWrite(6, 0);
    analogWrite(5, k);
    analogWrite(10, k);
    analogWrite(9, 0);
    return;
  }


  if ( g < 40) {
    j = map (g , 40 , 0 , 100 , 255 );

    analogWrite(5, 0);
    analogWrite(6, j);
    analogWrite(9, 0);
    analogWrite(10, j);
    return;

  } else if (g > 60 ) {
    j = map (g , 60 , 100 , 100 , 255 );

    analogWrite(6, 0);
    analogWrite(5, j);
    analogWrite(10, 0);
    analogWrite(9, j );
    return;
  }



  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);

}

