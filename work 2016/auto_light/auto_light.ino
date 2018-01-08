

void setup() {
  // put your setup code here, to run once:
pinMode(5 , INPUT);
pinMode(6 , OUTPUT);
digitalWrite(6 , LOW );
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(5) > 0 ) 
digitalWrite(6 , HIGH );
else
digitalWrite(6 , LOW );

delay(1000);

}
