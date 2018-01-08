#include <NewPing.h>
NewPing frontping ( A2 , A3 , 40 );
NewPing rightping ( A0 , A1 , 40 );

int fdis , rdis ;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  motorstop();
}

void loop() {
  // put your main code here, to run repeatedly:
  fdis = frontping.ping_cm() ;
  rdis = rightping.ping_cm() ;
  Serial.print (fdis);
  Serial.print ("        ");
  Serial.println(rdis);


  if ( (fdis < 1) && (rdis > 0 ))
  {
    motorF();
    delay(100);
    if (rdis > 15) motorR();
    if (rdis < 10) motorL();
  }
   if ( (fdis >= 15) && (rdis > 0 ))
  {
    motorF();
    delay(100);
    if (rdis > 15) motorR();
    if (rdis < 10) motorL();
  }

  if ( (fdis < 1) && (rdis < 1 ))
  {
    motorTR();
    delay(200);
    motorstop();
  }
  if ( (fdis > 0) && (fdis < 15 ))
  {
    motorTL();
    delay(800);
    motorstop();
  }


  motorstop();
}

void motorF()
{
  analogWrite(5, 200);
  analogWrite(6, 0);
  analogWrite(9, 200);
  analogWrite(10, 0);
}

void motorstop()
{
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
}
void motorR()
{
  analogWrite(5, 200);
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
  delay(50);
}
void motorL()
{
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 200);
  analogWrite(10, 0);
  delay(50);
}
void motorTL()
{
  analogWrite(5, 0);
  analogWrite(6, 200);
  analogWrite(9, 200);
  analogWrite(10, 0);
}
void motorTR()
{
  analogWrite(5, 200);
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 200);
}

