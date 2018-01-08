#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3);
String aa , bb , cc , dd ;
char g ;
int a,b,c,d;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  g = bt.read();
  if (g == 's' ) {

here:
    g = bt.read();

    if (g == 'p') goto there;

    a = analogRead(A0);
    b = analogRead(A1);
    c = analogRead(A2);
    d = analogRead(A3);



    if (a < 1000 ) {
      aa = '0' + String(a) ;
    }
    if (a < 100 ) {
      aa = '0' + aa ;
    }
    if (a < 10 ) {
      aa = '0' + aa ;
    }
    else   aa = String (a);



    if (b < 1000 ) {
      bb = '0' + String(b) ;
    }
    if (b < 100 ) {
      bb = '0' + bb ;
    }
    if (b < 10 ) {
      bb = '0' + bb ;
    }
    else   bb = String (b);



    if (c < 1000 ) {
      cc = '0' + String(c) ;
    }
    if (c < 100 ) {
      cc = '0' + cc ;
    }
    if (c < 10 ) {
      cc = '0' + cc ;
    }
    else   cc = String (c);




    if (d < 1000 ) {
      dd = '0' + String(d) ;
    }
    if (d < 100 ) {
      dd = '0' + dd ;
    }
    if (d < 10 ) {
      dd = '0' + dd ;
    }
    else   dd = String (d);


    bt.print("a");
    bt.println(aa);
    delay(100);
    bt.print("b");
    bt.println(bb);
    delay(100);
    bt.print("c");
    bt.println(cc);
    delay(100);
    bt.print("d");
    bt.println(dd);
    delay(100);
    bt.println("x");
    delay(100);



    Serial.print("a");
    Serial.println(aa);
    delay(100);
    Serial.print("b");
    Serial.println(bb);
    delay(100);
    Serial.print("c");
    Serial.println(cc);
    delay(100);
    Serial.print("d");
    Serial.println(dd);
    delay(100);
    Serial.println("x");
    delay(100);
    goto here;
there :;

  }



}
