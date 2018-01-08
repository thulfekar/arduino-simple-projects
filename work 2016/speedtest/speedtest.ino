int c,i ;
void setup() {
  // put your setup code here, to run once:
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
analogWrite( 6 , 0 );
analogWrite( 7 , 50 );

delay(1000);

analogWrite( 6 , 0 );
analogWrite( 7 , 75 );

delay(1000);

analogWrite( 6 , 0 );
analogWrite( 7 , 100 );

delay(1000);

analogWrite( 6 , 0 );
analogWrite( 7 , 150 );

delay(1000);
analogWrite( 6 , 0 );
analogWrite( 7 , 200 );

delay(1000);
analogWrite( 6 , 0 );
analogWrite( 7 , 250 );

delay(1000);

analogWrite( 6 , 50 );
analogWrite( 7 , 0 );

delay(1000);

analogWrite( 6 , 100 );
analogWrite( 7 , 0 );

delay(1000);


analogWrite( 6 , 150 );
analogWrite( 7 , 0 );

delay(1000);

analogWrite( 6 , 200 );
analogWrite( 7 , 0 );

delay(1000);

analogWrite( 6 , 250 );
analogWrite( 7 , 0 );

delay(1000);


analogWrite( 6 , 200 );
analogWrite( 7 , 0 );


analogWrite( 6 , 150 );
analogWrite( 7 , 0 );

delay(1000);
delay(1000);



}
