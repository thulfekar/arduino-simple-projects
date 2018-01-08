void setup() {
  // put your setup code here, to run once:
pinMode(4,INPUT_PULLUP);


Serial.begin(9600);
Serial.println("booting");
}

void loop() {
  // put your main code here, to run repeatedly:
delay(3000);
pinMode(4,OUTPUT);
digitalWrite(4,LOW);
}
