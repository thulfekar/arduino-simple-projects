#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define CE_PIN 9
#define CSN_PIN 10
int a = 200 ;
int b = 250 ;
int c = 375 ;
int d = 375 ;
int e = 375 ;
int upbut ;
int rightbut;
int downbut ;
int lefttbut ;
int startbut;
int selectbut;
int pushbut;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
// SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
int joystick[9];

void setup()   /****** SETUP: RUNS ONCE ******/
{

  Serial.begin(9600);


  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();;

  pwm.begin();

  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
  delay(3000);
}

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {

      getdata();


      if (pushbut < 1 ) {
here :
           pwm.setPWM(0, 0, 190); // max right
        pwm.setPWM(1, 0, 350); // lean back
        pwm.setPWM(2, 0, 195);// straight arm
        pwm.setPWM(3, 0, 355);
        pwm.setPWM(4, 0, 225); // grabber wide open
        delay(1000);
          getdata();
        if (( upbut < 1 ) || ( downbut < 1 ) || ( rightbut < 1 ) || ( lefttbut < 1 ) )
          break ;
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
          getdata();
        if (( upbut < 1 ) || ( downbut < 1 ) || ( rightbut < 1 ) || ( lefttbut < 1 ) )
          break ;
        delay(1000);
          getdata();
        if (( upbut < 1 ) || ( downbut < 1 ) || ( rightbut < 1 ) || ( lefttbut < 1 ) )
          break ;
         for(int v = 350 ; v <= 550 ; v += 1 ){
        pwm.setPWM(1, 0, v); // lean forward
        delay(10);
      }
        getdata();
        if (( upbut < 1 ) || ( downbut < 1 ) || ( rightbut < 1 ) || ( lefttbut < 1 ) )
          break ;
      delay(750);
        pwm.setPWM(4, 0, 225); // grabber wide open
        delay(1000);
pwm.setPWM(1, 0, 350); // lean back
delay(2000);
        getdata();
        if (( upbut < 1 ) || ( downbut < 1 ) || ( rightbut < 1 ) || ( lefttbut < 1 ) )
          break ;

        goto here;
      }
there:
      if (joystick[0] <= 100 ) {
        c += 3 ;
        if (c >= 600 ) c = 600 ;
        pwm.setPWM(0, 0, c);
        delay(10);
      }

      if (joystick[0] >= 550 ) {
        c -= 3 ;
        if (c <= 150 ) c = 150 ;
        pwm.setPWM(0, 0, c);
        delay(10);
      }


      if (joystick[1] <= 100 ) {
        d += 3 ;
        if (d >= 600 ) d = 600 ;
        pwm.setPWM(1, 0, d);
        delay(10);
      }

      if (joystick[1] >= 550 ) {
        d -= 3 ;
        if (d <= 150 ) d = 150 ;
        pwm.setPWM(1, 0, d);
        delay(10);
      }


      if (startbut < 1 ) {
        e += 5 ;
        if (e >= 600 ) e = 600 ;
        pwm.setPWM(3, 0, e);
        delay(10);

      }

      if (selectbut < 1 ) {
        e -= 5 ;
        if (e <= 150 ) e = 150 ;
        pwm.setPWM(3, 0, e);
        delay(10);

      }


      if (downbut < 1 ) {
        a += 5 ;
        if (a >= 400) a = 400 ;
        pwm.setPWM(2, 0, a);
        delay(10);

      }

      if (upbut < 1 ) {
        a -= 5 ;
        if (a <= 150 ) a = 150 ;
        pwm.setPWM(2, 0, a);
        delay(10);

      }

      if (lefttbut < 1 ) {
        b += 5 ;
        if (b >= 360 ) b = 360 ;
        pwm.setPWM(4, 0, b);
        delay(10);
      }

      if (rightbut < 1 ) {
        b -= 5 ;
        if (b <= 220 ) b = 220 ;
        pwm.setPWM(4, 0, b);
        delay(10);
      }


    }

  }
  else
  {
    Serial.println("No radio available");
  }

}
