#include <VirtualWire.h>
#include <Stepper.h>
Stepper myStepper(200, 4, 5, 6, 7);
char command ;
void setup()
{
  pinMode(8, OUTPUT);
  digitalWrite(8 , HIGH);

  Serial.begin(9600);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000);  // Bits per sec
  pinMode(13, OUTPUT);
  myStepper.setSpeed(60);

  vw_rx_start();       // Start the receiver PLL running
}
void(* resetFunc) (void) = 0;
void loop()
{

  stopit();
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    if (buf[0] == 'A') {

      blinkk();
      myStepper.step(2000);
      stopit() ; delay(100);

    }
    if (buf[0] == 'B') {
      blinkk();
      myStepper.step(-2000);
      stopit() ; delay(100);

    }
    if (buf[0] == 'C') {
      blinkk();
      myStepper.step(4000);
      stopit() ; delay(100);

    }
    if (buf[0] == 'D') {
      blinkk();
      myStepper.step(-4000);
      stopit() ; delay(100);

    }
    if (buf[0] == '0') {
      blinkk();
      stopit() ; delay(100);

      while (!Serial.available()) {}

      command = Serial.read();
      switch ( command ) {
        case '1' :
          blinkk();
          for (int i = 0 ; i <= 180 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(20000);
          }

          break;

        case '2' :
          blinkk();
          for (int i = 0 ; i <= 360 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(10000);
          }

          break;

        case '3' :

          blinkk();
          for (int i = 0 ; i <= 440 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(6666);
          }

          break;

        case '4' :
          blinkk();
          for (int i = 0 ; i <= 720 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(5000);
          }


          break;

        case '5' :
          blinkk();
          for (int i = 0 ; i <= 900 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(4000);
          }


          break;

        case '6' :

          blinkk();
          for (int i = 0 ; i <= 1080 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(3333);
          }


          break;

        case '7' :
          blinkk();
          for (int i = 0 ; i <= 1260 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(2857);
          }

          break;

        case '8' :
          blinkk();

          for (int i = 0 ; i <= 1440 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(2500);
          }


          break;

        case '9' :
          blinkk();
          for (int i = 0 ; i <= 1620 ; i++ )
          {
            myStepper.step(10);
            stopit() ; delay(2222);
          }



          break;

        case '0' :
          resetFunc();
          break;


      }
    }

    if (buf[0] == '1') {

      blinkk();
      for (int i = 0 ; i <= 180 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(20000);
      }
    }
    if (buf[0] == '2') {
      blinkk();
      for (int i = 0 ; i <= 360 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(10000);
      }
    }

    if (buf[0] == '3') {
      blinkk();
      for (int i = 0 ; i <= 440 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(6666);
      }
    }

    if (buf[0] == '4') {
      blinkk();
      for (int i = 0 ; i <= 720 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(5000);
      }
    }

    if (buf[0] == '5') {
      blinkk();
      for (int i = 0 ; i <= 900 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(4000);
      }
    }


    if (buf[0] == '6') {

      blinkk();
      for (int i = 0 ; i <= 1080 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(3333);
      }
    }


    if (buf[0] == '7') {

      blinkk();
      for (int i = 0 ; i <= 1260 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(2857);
      }
    }

    if (buf[0] == '8') {
      blinkk();

      for (int i = 0 ; i <= 1440 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(2500);
      }
    }


    if (buf[0] == '9') {
      blinkk();
      for (int i = 0 ; i <= 1620 ; i++ )
      {
        myStepper.step(10);
        stopit() ; delay(2222);
      }
    }


  }
}

void blinkk() {
  digitalWrite(13, 1);
  delay(100);
  digitalWrite(13, 0);
}

void stopit() {
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}


