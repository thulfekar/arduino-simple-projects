#include <AFMotor.h>

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);
int x, y, z ;
void setup() {
  pinMode(14, OUTPUT);
  pinMode(15, INPUT);

  pinMode(16, OUTPUT);
  pinMode(17, INPUT);

  pinMode(18, OUTPUT);
  pinMode(19, INPUT);

  m1.setSpeed(200); // change for speed -100 - 250
  m1.run(RELEASE);
  m2.setSpeed(200);
  m2.run(RELEASE);
  m3.setSpeed(200);
  m3.run(RELEASE);
  m4.setSpeed(200);
  m4.run(RELEASE);

}

void loop() {

  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  delay(10);
  getdis();

  if (x <= 20 ) //change for distance 
  {
    m3.run(RELEASE);
    m4.run(RELEASE);
    delay(400);
    m3.run(FORWARD);
    m4.run(FORWARD);

  }


  if (z <= 20 )
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
    delay(400);
    m1.run(FORWARD);
    m2.run(FORWARD);

  }

  if (y <= 20 )
  {
    releasee();
    delay(400);
    m1.run(BACKWARD);
    m2.run(BACKWARD);
    m3.run(BACKWARD);
    m4.run(BACKWARD);
    delay(400);
    releasee();
    m1.run(FORWARD);
    m2.run(FORWARD);
    m3.run(BACKWARD);
    m4.run(BACKWARD);
    delay(400);
    releasee();
    m1.run(FORWARD);
    m2.run(FORWARD);
    m3.run(FORWARD);
    m4.run(FORWARD);
    delay(400);
    releasee();
    m3.run(FORWARD);
    m4.run(FORWARD);
    m1.run(BACKWARD);
    m2.run(BACKWARD);
    delay(400);
    releasee();

  }






}
