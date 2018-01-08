
#define red1 43
#define red2 35
#define red3 23
#define red4 39
#define red5 27
#define red6 31
#define red7 47
#define red8 51
#define green1 45
#define green2 37
#define green3 25
#define green4 41
#define green5 29
#define green6 33
#define green7 49
#define green8 53
#define in1 5
#define in2 4
#define in3 3
#define in4 2
#define in5 6
#define in6 7
#define in7 8
#define in8 9
#define on 150
#define off 0
int a ;
void setup() {
  // put your setup code here, to run once:
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(red5, OUTPUT);
  pinMode(red6, OUTPUT);
  pinMode(red7, OUTPUT);
  pinMode(red8, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(green4, OUTPUT);
  pinMode(green5, OUTPUT);
  pinMode(green6, OUTPUT);
  pinMode(green7, OUTPUT);
  pinMode(green8, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT);
  pinMode(in8, INPUT);
  digitalWrite(A0,HIGH);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    char x = Serial.read();
    if (x == 'x')digitalWrite(A0 , LOW);
    else if (x == 'z' ) digitalWrite(A0, HIGH);

  a = digitalRead(in1);
  if (a > 0 ) {
    analogWrite(red1 , off ) ;
    analogWrite(green1 , on);
    Serial.println("a");
    delay(50);
  }
  else {
    analogWrite(red1 , on ) ;
    analogWrite(green1 , off);
    Serial.println("b");
    delay(50);
  }


  a = digitalRead(in2);
  if (a > 0 ) {
    analogWrite(red2 , off ) ;
    analogWrite(green2 , on);
    Serial.println("c");
    delay(50);
  }
  else {
    analogWrite(red2 , on ) ;
    analogWrite(green2 , off);
    Serial.println("d");
    delay(50);
  }


  a = digitalRead(in3);
  if (a > 0 ) {
    analogWrite(red3 , off ) ;
    analogWrite(green3 , on);
    Serial.println("e");
    delay(50);
  }
  else {
    analogWrite(red3 , on ) ;
    analogWrite(green3 , off);
    Serial.println("f");
    delay(50);
  }
    a = digitalRead(in4);
  if (a > 0 ) {
    analogWrite(red4 , off ) ;
    analogWrite(green4 , on);
    Serial.println("g");
    delay(50);
  }
  else {
    analogWrite(red4 , on ) ;
    analogWrite(green4 , off);
    Serial.println("h");
    delay(50);
  }

  a = digitalRead(in5);
  if (a > 0 ) {
    analogWrite(red5 , off ) ;
    analogWrite(green5 , on);
    Serial.println("i");
    delay(50);
  }
  else {
    analogWrite(red5 , on ) ;
    analogWrite(green5 , off);
    Serial.println("j");
    delay(50);
  }

  a = digitalRead(in6);
  if (a > 0 ) {
    analogWrite(red6 , off ) ;
    analogWrite(green6 , on);
    Serial.println("k");
    delay(50);
  }
  else {
    analogWrite(red6 , on ) ;
    analogWrite(green6 , off);
    Serial.println("l");
    delay(50);
  }

  a = digitalRead(in7);
  if (a > 0 ) {
    analogWrite(red7 , off ) ;
    analogWrite(green7 , on);
    Serial.println("m");
    delay(50);
  }
  else {
    analogWrite(red7 , on ) ;
    analogWrite(green7 , off);
    Serial.println("n");
        delay(50);

  }

  a = digitalRead(in8);
  if (a > 0 ) {
    analogWrite(red8 , off ) ;
    analogWrite(green8 , on);
    Serial.println("o");
    delay(50);
  }
  else {
    analogWrite(red8 , on ) ;
    analogWrite(green8 , off);
    Serial.println("p");
        delay(50);

  }


}
