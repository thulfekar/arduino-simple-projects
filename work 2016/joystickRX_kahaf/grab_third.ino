void grab3() {
        pwm.setPWM(0, 0, 190); // max right
        pwm.setPWM(1, 0, 350); // lean back
        pwm.setPWM(2, 0, 195);// straight arm
        pwm.setPWM(3, 0, 355);
        pwm.setPWM(4, 0, 225); // grabber wide open
        delay(1000);
        
        for(int v = 350 ; v <= 550 ; v += 1 ){
        pwm.setPWM(1, 0, v); // lean forward
        delay(10);
      }
      delay(250);
        pwm.setPWM(4, 0, 300); // grabber closed
        delay(250);
        pwm.setPWM(1, 0, 350); // lean back
        delay(1000);
        pwm.setPWM(0, 0, 455); // max right
        
        pwm.setPWM(2, 0, 290);// straight arm
        pwm.setPWM(3, 0, 355);
        delay(1000);
        
         for(int v = 350 ; v <= 550 ; v += 1 ){
        pwm.setPWM(1, 0, v); // lean forward
        delay(10);
      }
      delay(750);
        pwm.setPWM(4, 0, 225); // grabber wide open
        delay(1000);
pwm.setPWM(1, 0, 350); // lean back
delay(2000);
}

