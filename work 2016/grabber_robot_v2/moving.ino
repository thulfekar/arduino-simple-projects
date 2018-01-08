
void forward() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  delay(3);
}
void slomo() {
  forward();
  stopit();
  delay(1);
}
void back() {
  digitalWrite(R2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L1, HIGH);
  delay(5);
}

void stopit() {
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  delay(5);
}

void left() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  delay(10);
}

void right() {
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  delay(10);
}

void turnright() {
rightagain :
  stopit();
  back();
  delay(500);
  stopit();
  right();
  delay(400);
  stopit();
  delay(100);
  for (int f = 0 ; f <= 3 ; f++)
  {
    forward();
    delay(100);
    stopit();
    readcolor();
    if ((red > 100) || (blue > 100) || (green > 100) )
      goto rightagain;
  }
  delay(100);
  right();
  delay(400);
  stopit();
}

void turnleft() {
leftagain:
  back();
  delay(500);
  stopit();
  left();
  delay(400);
  stopit();
  delay(100);
  forward();
  delay(300);
  stopit();
  readcolor();
  if ((red > 100) || (blue > 100) || (green > 100) )
    goto leftagain;
  delay(100);
  left();
  delay(400);
  stopit();
}

void gotoobject() {

  for (int j = 0 ; j <= (dis * 3) ; j++)
    slomo();
  stopit();
  scan();

}


