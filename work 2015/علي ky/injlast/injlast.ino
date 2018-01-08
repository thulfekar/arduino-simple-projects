#include <VirtualWire.h>
char command , command1 , command2 ;
int com , com2 , zz , c ;
long timer ;
long x, y, z ;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  c = 0 ;
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
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
    z = x + y ;
    Serial.print(x);

    Serial.print("     ");

    Serial.print(y);

    Serial.print("     ");
    Serial.println(z) ;

    if (z >= 30 ) {
            digitalWrite(7, LOW);

      delay(2000);
      digitalWrite(7, HIGH);
      resetFunc();
    }
        y = y * 1500 ;
    x = x * 36000 ;
    
    while (z < 1 ) {

      while (!Serial.available()) {
        if ((millis() - timer ) > com )
        {
          digitalWrite(5, LOW);
          delay(com2);
          digitalWrite(5, HIGH);
          timer = millis() ;
        }
      }
      command = Serial.read();
      
if (command == '0' ) resetFunc();

      if ( c < 1 ) {
        command1 = command ;
        digitalWrite(2, HIGH);
        blinkk();

        c = 1 ;
      }
      else {
        command2 = command ;
        digitalWrite(3, HIGH);
        c = 0 ;
        blinkk();

      }
      com = command1 - '0' ;
      com2 = command2 - '0' ;
      zz = com + com2 ;
      Serial.print(com);

      Serial.print("     ");

      Serial.print(com2);

      Serial.print("     ");
      Serial.println(zz) ;
      com = com * 3600 ;
      com2 = com2 * 1500 ;
      if ((c < 1 ) && (zz < 1 )) resetFunc();
      if ((c < 1) && (zz >= 19 )) resetFunc();


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

