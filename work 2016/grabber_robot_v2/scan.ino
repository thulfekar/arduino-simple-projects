
void scan() {
scanagain:
  scaner.write(25);
  delay(500);
  for (i = 25 ; i <= 155 ; i = i + 2 ) {
    scaner.write(i);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig, LOW);
    dis = pulseIn(echo, HIGH);
    dis = dis / 29 / 2 ;
    if (dis < 0 ) dis = 100 ;
    if (dis > 30 ) dis = 100 ;
    Serial.print(dis);
    Serial.print ("       i = " );
    Serial.println(i);
    if ((dis > 8 ) && (dis < 30 )) {
      Serial.println("scanagain");
      turnobject();
      goto scanagain;
    }
    else if (dis <= 8 ) {
      grabit();
      delay(4000);
      gotoredzone();
    }
  }
  Serial.println("rescan");
}

