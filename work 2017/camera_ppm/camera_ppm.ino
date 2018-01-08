#include <Servo.h>
#include <PPMrcIn.h>
#include <Statistic.h>

Channel channel1;




int a, b, g, h, j, k, t ;

void setup() {

  Serial.begin(19200);
  delay(1000);
  Serial.println("Ready:");
  pinMode (A0, INPUT);
  pinMode (4, INPUT);
  pinMode (3, INPUT);



  channel1.init(1, A0);


}

void loop() {
  t++ ;

  if (t == 100) {
    channel1.readSignal();
    a = channel1.getSignal();
    delayMicroseconds(4750);
  }
 
  if (t >= 600) {
    t = 0 ;
    Serial.print("  a = ");
    Serial.println(a);

  }

if (a >= 1800 ){
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
}else if (a <= 1100 ){
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
}else{
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
    pinMode(3,INPUT);
    pinMode(4,INPUT);
    

}

}

