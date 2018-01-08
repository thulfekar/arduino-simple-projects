#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor pump(4);

Servo serv1 ;
Servo serv2 ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps

serv1.attach(9);
serv2.attach(10);

  m1.setSpeed(200);
  m1.run(RELEASE);
  m2.setSpeed(200);
  m2.run(RELEASE);
  pump.setSpeed(200);
  pump.run(RELEASE);
  serv1.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:
for (int i = 0 ; i < 3 ; i ++) {
m1.run(FORWARD);
m2.run(BACKWARD);

delay(250);
m1.run(RELEASE);
m2.run(RELEASE);
delay(500);
for (int j = 80 ;j <= 140 ; j++ ){
  serv1.write(j);
  delay(20);
}
for (int j = 140 ;j >= 80 ; j-- ){
  serv1.write(j);
  delay(20);
}
for (int j = 80 ;j <= 140 ; j++ ){
  serv1.write(j);
  delay(20);
}
for (int j = 140 ;j >= 80 ; j-- ){
  serv1.write(j);
  delay(20);
}

delay(2000);
}
pump.run(FORWARD);
delay(500);
pump.run(RELEASE);

}
