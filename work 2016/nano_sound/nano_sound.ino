int x ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A7,INPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
x = analogRead(A7);
Serial.println (x);
if (x <= 50 ) {
 digitalWrite(12,HIGH) ;
 digitalWrite(11,HIGH) ;
 digitalWrite(10,HIGH) ;
digitalWrite(9,HIGH) ;
digitalWrite(8,LOW) ;
digitalWrite(7,LOW) ;
digitalWrite(6,LOW) ;
digitalWrite(5,LOW) ;
delay(6000);
}
 digitalWrite(12,LOW) ;
 digitalWrite(11,LOW) ;
 digitalWrite(10,LOW) ;
digitalWrite(9,LOW) ;
digitalWrite(8,HIGH) ;
digitalWrite(7,HIGH) ;
digitalWrite(6,HIGH) ;
digitalWrite(5,HIGH) ;

}
