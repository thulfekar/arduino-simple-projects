
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit");
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}


void getdata() {
  radio.read( joystick, sizeof(joystick) );
  // the four button variables from joystick array
  upbut = joystick[2];
  rightbut = joystick[3];
  downbut = joystick[4];
  lefttbut = joystick[5];
  startbut = joystick[6];
  selectbut = joystick[7];
  pushbut = joystick[8];
  if (( upbut < 1 ) && ( downbut < 1 ) && ( rightbut < 1 ) && ( lefttbut < 1 ))
    return;
  if (( upbut >= 2 ) || ( downbut >= 2 ) || ( rightbut >= 2 ) || ( lefttbut >= 2 ))
    return;
  Serial.print("X = ");
  Serial.print(joystick[0]);
  Serial.print(" Y = ");
  Serial.print(joystick[1]);
  Serial.print(" Up = ");
  Serial.print(joystick[2]);
  Serial.print(" Right = ");
  Serial.print(joystick[3]);
  Serial.print(" Down = ");
  Serial.print(joystick[4]);
  Serial.print(" Left = ");
  Serial.print(joystick[5]);
  Serial.print(" start = ");
  Serial.print(joystick[6]);
  Serial.print(" select = ");
  Serial.print(joystick[7]);
  Serial.print(" push = ");
  Serial.println(joystick[8]);
/*
   Serial.print("c = ");
  Serial.print(c);
  Serial.print(" d = ");
  Serial.print(d);
  Serial.print(" e = ");
  Serial.print(e);
  Serial.print(" a = ");
  Serial.print(a);
  Serial.print(" b = ");
  Serial.println(b);
 */
}

