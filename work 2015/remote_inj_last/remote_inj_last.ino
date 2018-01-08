#include <VirtualWire.h>
char command ;
long timer ;
long x, y ;
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);


  Serial.begin(9600);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000);  // Bits per sec
  pinMode(13, OUTPUT);

  stopit();
  vw_rx_start();       // Start the receiver PLL running
  timer = millis();
}
void(* resetFunc) (void) = 0;
void loop()
{


  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    blinkk();
    x = buf[1] - '0' ;
    y = buf[0] - '0' ;
    if ((x > 16) && (y > 16))
    { digitalWrite(7, LOW);
      delay(2000);
      digitalWrite(7, HIGH);
      resetFunc();
    }
    else {
      y = y * 1500 ;
      x = x * 36000 ;
    }

  }

  if ((millis() - timer ) > x )
  {
    digitalWrite(5, LOW);
    delay(y);
    digitalWrite(5, HIGH);
    timer = millis() ;
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

