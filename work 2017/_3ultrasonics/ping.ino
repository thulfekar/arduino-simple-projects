void getdis() {

  digitalWrite(14, LOW);
  delayMicroseconds(2);
  digitalWrite(14, HIGH);
  delayMicroseconds(5);
  digitalWrite(14, LOW);
  x = pulseIn(15, HIGH);

  delay(3);

  digitalWrite(16, LOW);
  delayMicroseconds(2);
  digitalWrite(16, HIGH);
  delayMicroseconds(5);
  digitalWrite(16, LOW);
  y = pulseIn(17, HIGH);

  delay(3);

  digitalWrite(18, LOW);
  delayMicroseconds(2);
  digitalWrite(18, HIGH);
  delayMicroseconds(5);
  digitalWrite(18, LOW);
  z = pulseIn(19, HIGH);

  delay(3);
  x = x / 29 / 2 ;
  y = y / 29 / 2 ;
  z = z / 29 / 2 ;
  if ((x < 0 ) || (x > 40 )) x = 100 ; 
  if ((y < 0 ) || (y > 40 )) y = 100 ; 
  if ((z < 0 ) || (z > 40 )) z = 100 ; 
   
}

void releasee() {
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
  delay(100);
}

