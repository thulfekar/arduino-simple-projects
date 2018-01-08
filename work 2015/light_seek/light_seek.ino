#include <Servo.h>
Servo servoPan;
Servo servoTilt;
int pan = 90;
int tilt = 90 ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  servoPan.attach(11);
  servoTilt.attach(10);

  servoPan.write(pan);
  servoTilt.write(tilt);

  delay(3000);

}

void loop() {

  int sensorUpperRight = analogRead(A0);
  int sensorUpperLeft = analogRead(A1);
  int sensorLowerRight = analogRead(A2);
  int sensorLowerLeft = analogRead(A3);
  int sensorCenter = analogRead(A4);

  int midLeft = (sensorUpperLeft + sensorLowerLeft) * 0.5;
  int midRight = (sensorUpperRight + sensorLowerRight) * 0.5;
  int midUpper = (sensorUpperLeft + sensorUpperRight) * 0.5;
  int midBottom = (sensorLowerLeft + sensorLowerRight) * 0.5;

  if (midLeft > sensorCenter ) {
    pan = pan - 5;
    if ( pan <= 10) pan = 10 ;
  }
 if (midRight > sensorCenter ) {
    pan = pan + 5;
    if ( pan >= 170) pan = 170 ;
  }
 if (midUpper > sensorCenter ) {
    tilt = tilt + 5;
    if ( tilt >= 150) tilt = 150 ;
  }
   if (midBottom > sensorCenter ) {
    tilt = tilt - 5;
    if ( tilt <= 60) tilt = 60 ;
  }


servoPan.write(pan);
 servoTilt.write(tilt);



Serial.println("------------------------------");
Serial.println("Upper Right: " + String(sensorUpperRight));
Serial.println("Upper Left: " + String(sensorUpperLeft));
Serial.println("Lower Right: " + String(sensorLowerRight));
Serial.println("Lower Left: " + String(sensorLowerLeft));
Serial.println("Center: " + String(sensorCenter));
delay(50);
}
