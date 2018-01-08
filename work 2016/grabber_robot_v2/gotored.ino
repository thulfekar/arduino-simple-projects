void gotoredzone() {

  turnright();
lookforblack:
  forward();
  delay(100);
  stopit();
    scaner.write(80);
   digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig, LOW);
    dis = pulseIn(echo, HIGH);
    dis = dis / 29 / 2 ;
    if (dis < 0 ) dis = 100 ;
    if (dis > 30 ) dis = 100 ;
    if (dis < 30 ) {
      right();
      delay(500);
      stopit();
      delay(100);
      forward();
      delay(500);
      stopit();
      delay(100);
      left();
      delay(500);
      stopit();
      }
  readcolor();
  if (( red < 120 ) && (green > 100 ) && (blue > 100)) {
    forward();
    delay(200);
    stopit();
    delay(2000);
    tilt.write(50);
    delay(1000);
    grab.write(115);
    delay(2000);
    back();
    delay(500);
    stopit();
    tilt.write(130);
    delay(1000);
    turnright();
    scan();
  }
  else if (( red < 100 ) && ( green < 100 ) && ( blue < 100 ) )
    goto lookforblack ;
  else {
    back();
    delay (200);
    stopit();
    right();
    delay(500);
    stopit();
    delay(500);
    goto lookforblack ;
  }
}
