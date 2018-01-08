char com ;
void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while ( !Serial.available()) {}
com =  Serial.read() ;
switch (com)
{
  case 'A' :

digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
delay(10);

break;
  case 'D' :

digitalWrite(5,HIGH);
digitalWrite(4,LOW);
digitalWrite(7,HIGH);
digitalWrite(6,LOW);
delay(10);

break;

  case 'S' :

digitalWrite(5,HIGH);
digitalWrite(4,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
delay(10);

break;
  case 'W' :

digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(7,HIGH);
digitalWrite(6,LOW);
delay(10);
break;

default :
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
}

}
