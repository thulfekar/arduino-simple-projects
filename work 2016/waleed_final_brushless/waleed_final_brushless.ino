#define dir1 21
#define dir2 22
#define dir3 23
#define dir4 24
#define dir5 25
#define dir6 26
#define dir7 27
#define dir8 28


#define ext1 31
#define ext2 32
#define ext3 33
#define ext4 34
#define ext5 35
#define ext6 36
#define ext7 37
#define ext8 38

#define sp1 2
#define sp2 3
#define sp3 4
#define sp4 5
#define sp5 6
#define sp6 7
#define sp7 8
#define sp8 9

int x, y, f1 , f2 , f3 , f4 , f5 , f6, l, d1 ;


void setup() {
  // put your setup code here, to run once:
  digitalWrite(53, LOW);
  digitalWrite(51, LOW);
  Serial.begin(9600);
  l = 100 ;
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  pinMode(sp1, OUTPUT);
  pinMode(sp2, OUTPUT);
  pinMode(sp3, OUTPUT);
  pinMode(sp4, OUTPUT);
  pinMode(sp5, OUTPUT);
  pinMode(sp6, OUTPUT);
  pinMode(sp7, OUTPUT);
  pinMode(sp8, OUTPUT);

  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(dir5, OUTPUT);
  pinMode(dir6, OUTPUT);
  pinMode(dir7, OUTPUT);
  pinMode(dir8, OUTPUT);

  pinMode(ext1, OUTPUT);
  pinMode(ext2, OUTPUT);
  pinMode(ext3, OUTPUT);
  pinMode(ext4, OUTPUT);
  pinMode(ext5, OUTPUT);
  pinMode(ext6, OUTPUT);
  pinMode(ext7, OUTPUT);
  pinMode(ext8, OUTPUT);

  digitalWrite(sp1, LOW);
  digitalWrite(sp2, LOW);
  digitalWrite(sp3, LOW);
  digitalWrite(sp4, LOW);
  digitalWrite(sp5, LOW);
  digitalWrite(sp6, LOW);
  digitalWrite(sp7, LOW);
  digitalWrite(sp8, LOW);

  digitalWrite(ext1, HIGH);
  digitalWrite(ext2, HIGH);
  digitalWrite(ext3, HIGH);
  digitalWrite(ext4, HIGH);
  digitalWrite(ext5, HIGH);
  digitalWrite(ext6, HIGH);
  digitalWrite(ext7, HIGH);
  digitalWrite(ext8, HIGH);

  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  digitalWrite(dir3, HIGH);
  digitalWrite(dir4, HIGH);
  digitalWrite(dir5, HIGH);
  digitalWrite(dir6, HIGH);
  digitalWrite(dir7, HIGH);
  digitalWrite(dir8, HIGH);

}


void limit () {

  analogWrite(sp3 , 150 ); // motor 3 - speed 150 (0 - 255)
  analogWrite(sp6 , 150 ); // motor 6 - speed 150 (0 - 255)
  digitalWrite(ext3, LOW);
  digitalWrite(ext6, LOW);
  digitalWrite(dir2 , LOW) ; // motor direction LEFT
  digitalWrite(dir7 , LOW) ;
  analogWrite(sp2 , 150 ); // motor 2 - speed 150 (0 - 255)
  analogWrite(sp7 , 150 ); // motor 7 - speed 150 (0 - 255)
  digitalWrite(ext2, LOW);
  digitalWrite(ext7, LOW);
  delay(5000); // time to reach max right
  analogWrite(sp2 , 0 );
  analogWrite(sp3 , 0 );
  analogWrite(sp6 , 0 );
  analogWrite(sp7 , 0 );
  digitalWrite(ext3, HIGH);
  digitalWrite(ext6, HIGH);
  digitalWrite(ext2, HIGH);
  digitalWrite(ext7, HIGH);
  digitalWrite(dir2 , HIGH) ; // motor direction LEFT
  digitalWrite(dir7 , HIGH) ;
}



void loop() {
  // put your main code here, to run repeatedly:
main:
  x = map(analogRead(A0), 0, 1024, 1, 180);
  y = map(analogRead(A1), 0, 1024, 1, 180);
  f1 = digitalRead(A3);
  f2 = digitalRead(A2);
  f3 = digitalRead(A4);
  f4 = digitalRead(A5);
  f5 = digitalRead(A6);
  f6 = digitalRead(A7);




  Serial.print("X = ");
  Serial.print(x);
  Serial.print(" Y = ");
  Serial.print(y);  Serial.print(" f1 = ");
  Serial.print(f1);  Serial.print(" f2 = ");
  Serial.print(f2);  Serial.print(" f3 = ");
  Serial.print(f3);  Serial.print(" f4 = ");
  Serial.print(f4);  Serial.print(" f5 = ");
  Serial.print(f5);  Serial.print(" f6 = ");
  Serial.println(f6);


  delay(100);




  if (f1 < 1 ) // traditional mode
  {

    limit();

    digitalWrite(dir6 , LOW) ;
    digitalWrite(dir3, LOW) ;
    digitalWrite(dir2 , HIGH) ; // motor direction LEFT
    digitalWrite(dir7 , HIGH) ;
    analogWrite(sp2 , 150 ); // motor 2 - speed 150 (0 - 255)
    analogWrite(sp3 , 150 ); // motor 3 - speed 150 (0 - 255)
    analogWrite(sp6 , 150 ); // motor 6 - speed 150 (0 - 255)
    analogWrite(sp7 , 150 ); // motor 7 - speed 150 (0 - 255)
    digitalWrite(ext2, LOW);
    digitalWrite(ext3, LOW);
    digitalWrite(ext6, LOW);
    digitalWrite(ext7, LOW);
    delay(2000); // time to reach Middle
    analogWrite(sp2 , 0 );
    analogWrite(sp3 , 0 );
    analogWrite(sp6 , 0 );
    analogWrite(sp7 , 0 );
    digitalWrite(ext2, HIGH);
    digitalWrite(ext3, HIGH);
    digitalWrite(ext6, HIGH);
    digitalWrite(ext7, HIGH);

    digitalWrite(dir2 , HIGH) ; // motor direction RIGHT
    digitalWrite(dir3 , HIGH) ;
    digitalWrite(dir6 , HIGH) ;
    digitalWrite(dir7, HIGH) ;

    goto trad;

  }

  if (l < 1)
  {
trad:

    digitalWrite(53, HIGH);
    x = map(analogRead(A0), 0, 1024, 1, 180);
    y = map(analogRead(A1), 0, 1024, 1, 180);
    f1 = digitalRead(A3);
    f2 = digitalRead(A2);
    f3 = digitalRead(A4);
    f4 = digitalRead(A5);
    f5 = digitalRead(A6);
    f6 = digitalRead(A7);


    if (y > 100) {
      analogWrite(sp3 , 150);
      analogWrite(sp2 , 150);
      digitalWrite(ext3, LOW);
      digitalWrite(ext2, LOW);
      delay(25);
      analogWrite(sp3 , 0);
      analogWrite(sp2 , 0);
      digitalWrite(ext3, HIGH);
      digitalWrite(ext2, HIGH);

    }
    if (y < 80) {
      digitalWrite(dir2, LOW);
      digitalWrite(dir3, LOW); //left
      analogWrite(sp3 , 150);
      analogWrite(sp2 , 150);
      digitalWrite(ext3, LOW);
      digitalWrite(ext2, LOW);
      delay(25);
      analogWrite(sp3 , 0);
      analogWrite(sp2 , 0);
      digitalWrite(dir2, HIGH);
      digitalWrite(dir3, HIGH); //left
      digitalWrite(ext3, HIGH);
      digitalWrite(ext2, HIGH);

    }
    if (x > 100 ) {
      d1 = map (x , 100, 180 , 50 , 255 );
      analogWrite(sp5 , d1 );
      analogWrite(sp8 , d1 );
      digitalWrite(ext5, LOW);
      digitalWrite(ext8, LOW);

    }

    if (x < 80 ) {

      d1 = map (x , 0 , 80 , 0 , 205 );

      digitalWrite(dir5 , LOW);
      digitalWrite(dir8 , LOW);
      analogWrite(sp5 , (255 - d1) );
      analogWrite(sp8 , (255 - d1) );
      digitalWrite(ext5, LOW);
      digitalWrite(ext8, LOW);

    }
    if ((x > 80 ) && ( x < 100 ) )
    {
      digitalWrite(dir5 , HIGH);
      digitalWrite(dir8 , HIGH);
      analogWrite(sp5 , 0 );
      analogWrite(sp8 , 0 );
      digitalWrite(ext5, HIGH);
      digitalWrite(ext8, HIGH);
    }

    if (f3 < 1 )
      goto main;

    goto trad;



  }

  if (f2 < 1 )
  {

    limit();
    analogWrite(sp2 , 150 ); // motor 2 - speed 150 (0 - 255)
    analogWrite(sp7 , 150 ); // motor 7 - speed 150 (0 - 255)
    digitalWrite(dir3 , LOW);
    digitalWrite(dir6 , LOW);
    analogWrite(sp3 , 150 ); // motor 3 - speed 150 (0 - 255)
    analogWrite(sp6 , 150 ); // motor 6 - speed 150 (0 - 255)
    digitalWrite(ext2, LOW);
    digitalWrite(ext7, LOW);
    digitalWrite(ext3, LOW);
    digitalWrite(ext6, LOW);
    delay(5000);
    analogWrite(sp2 , 0 );
    analogWrite(sp3 , 0 );
    analogWrite(sp6 , 0 );
    analogWrite(sp7 , 0 );
    digitalWrite(ext2, HIGH);
    digitalWrite(ext3, HIGH);
    digitalWrite(ext7, HIGH);
    digitalWrite(ext6, HIGH);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir6, HIGH);
    digitalWrite(dir2, HIGH);
    digitalWrite(dir7, HIGH);



    goto center;


  }



  if (l < 1 )
  {
center:

    x = map(analogRead(A0), 0, 1024, 1, 180);
    y = map(analogRead(A1), 0, 1024, 1, 180);
    f1 = digitalRead(A3);
    f2 = digitalRead(A2);
    f3 = digitalRead(A4);
    f4 = digitalRead(A5);
    f5 = digitalRead(A6);
    f6 = digitalRead(A7);
    if (y > 100 ) {
      d1 = map (x , 100, 180 , 50 , 255 );
      analogWrite(sp1 , d1 );
      analogWrite(sp8 , d1 );
      digitalWrite(ext1, LOW);
      digitalWrite(ext8, LOW);

    }

    if (y < 80 ) {

      d1 = map (x , 0 , 80 , 0 , 205 );

      digitalWrite(dir1 , LOW);
      digitalWrite(dir8 , LOW);
      analogWrite(sp1 , (255 - d1) );
      analogWrite(sp8 , (255 - d1) );
      digitalWrite(ext1, LOW);
      digitalWrite(ext8, LOW);

    }
    if ((y > 80 ) && ( y < 100 ) )
    {
      digitalWrite(dir1 , HIGH);
      digitalWrite(dir8 , HIGH);
      analogWrite(sp1 , 0 );
      analogWrite(sp8 , 0 );
      digitalWrite(ext1, HIGH);
      digitalWrite(ext8, HIGH);

    }


    if (f3 < 1 )
      goto main;

    goto center;

  }




  if (f4 < 1 )
  {

    limit();
    analogWrite(sp2 , 150 ); // motor 2 - speed 150 (0 - 255)
    analogWrite(sp7 , 150 ); // motor 7 - speed 150 (0 - 255)
    digitalWrite(dir3 , LOW);
    digitalWrite(dir6 , LOW);
    analogWrite(sp3 , 150 ); // motor 3 - speed 150 (0 - 255)
    analogWrite(sp6 , 150 ); // motor 6 - speed 150 (0 - 255)
    digitalWrite(ext2, LOW);
    digitalWrite(ext7, LOW);
    digitalWrite(ext3, LOW);
    digitalWrite(ext6, LOW);
    delay(10000);
    analogWrite(sp2 , 0 );
    analogWrite(sp3 , 0 );
    analogWrite(sp6 , 0 );
    analogWrite(sp7 , 0 );
    digitalWrite(dir3, HIGH);
    digitalWrite(dir6, HIGH);
    digitalWrite(dir2, HIGH);
    digitalWrite(dir7, HIGH);
    digitalWrite(ext2, HIGH);
    digitalWrite(ext7, HIGH);
    digitalWrite(ext3, HIGH);
    digitalWrite(ext6, HIGH);



    goto side;


  }

  if (l < 1 )
  {
side:

    x = map(analogRead(A0), 0, 1024, 1, 180);
    y = map(analogRead(A1), 0, 1024, 1, 180);
    f1 = digitalRead(A3);
    f2 = digitalRead(A2);
    f3 = digitalRead(A4);
    f4 = digitalRead(A5);
    f5 = digitalRead(A6);
    f6 = digitalRead(A7);

    if (x > 100 ) {
      d1 = map (x , 100, 180 , 50 , 255 );
      analogWrite(sp1 , d1 );
      analogWrite(sp5 , d1 );
      digitalWrite(ext1, LOW);
      digitalWrite(ext5, LOW);

    }

    if (x < 80 ) {

      d1 = map (x , 0 , 80 , 0 , 205 );

      digitalWrite(dir1 , LOW);
      digitalWrite(dir5 , LOW);
      analogWrite(sp1 , (255 - d1) );
      analogWrite(sp5 , (255 - d1) );
      digitalWrite(ext1, LOW);
      digitalWrite(ext5, LOW);

    }
    if ((x > 80 ) && ( x < 100 ) )
    {
      digitalWrite(dir1 , HIGH);
      digitalWrite(dir5 , HIGH);
      analogWrite(sp1 , 0 );
      analogWrite(sp5 , 0 );
      digitalWrite(ext1, HIGH);
      digitalWrite(ext5, HIGH);

    }


    if (f3 < 1 )
      goto main;

    goto side;

  }



}



