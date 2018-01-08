// A simple web server that turn an LED on or off"

#include "etherShield.h"
#include "ETHER_28J60.h"
#include "avr/wdt.h"

int x = 0;

static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   // this just needs to be unique for your network,
static uint8_t ip[4] = {192, 168, 1, 15}; // IP address for the webserver
static uint16_t port = 80; // Use port 80 - the standard for HTTP
ETHER_28J60 e;
void setup()
{
  wdt_disable();

  e.setup(mac, ip, port);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  wdt_enable(WDTO_8S);
}

void loop()
{
  if (x > 0 ) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    delay(8000);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    x = 0 ;

  }
  char* params;
  if (params = e.serviceRequest())
  {

    e.print("<h1 style='font-color: #FF989F ; text-align:center; font-size:400%;'><a href='/?led=on'>POWER CONTROL</a></h1>");
 e.print("<footer style='font-color: #FF989F ; text-align:center; '>THULFEKAR ELECTRONICS & ROBOTICS</footer>");
    if (strcmp(params, "?led=on") == 0)
    {
      e.print("<a href='?led=off'><button style='color: #fff ;font-size:800% ;background-color: #C3EEE7;  box-shadow: inset 0 0 0 1px #27496d,0 5px 15px #193047; border: none; border-radius: 25px;' type='button'>RESTART</button></a>");

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
    }
    else if (strcmp(params, "?led=off") == 0)
    {
      e.print("<a href='?led=on'><button style='color: #fff ;font-size:800% ;background-color: #2DB4B4;  box-shadow: inset 0 0 0 1px #27496d,0 5px 15px #193047; border: none; border-radius: 25px;' type='button'>RESTARTING...</button></a>");
      x = 1 ;
    }
    else {
      e.print("<a href='?led=off'><button style='  color: #fff ;font-size:800% ;background-color: #C3EEE7;  box-shadow: inset 0 0 0 1px #27496d,0 5px 15px #193047; border: none; border-radius: 25px;' type='button'>RESTART</button></a>");
 
    }
    e.respond();
  }
  wdt_reset();
}




