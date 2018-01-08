

#include <XBee.h>



XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
// create reusable response objects for responses we expect to handle
Rx16Response rx16 = Rx16Response();
Rx64Response rx64 = Rx64Response();


uint8_t option = 0;
uint8_t data = 0;


void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(7,  OUTPUT);
  // start serial
  Serial.begin(9600);
  xbee.setSerial(Serial);


}

// continuously reads packets, looking for RX16 or RX64
void loop() {

  xbee.readPacket();

  if (xbee.getResponse().isAvailable()) {
    // got something

    if (xbee.getResponse().getApiId() == RX_16_RESPONSE || xbee.getResponse().getApiId() == RX_64_RESPONSE) {
      // got a rx packet

      if (xbee.getResponse().getApiId() == RX_16_RESPONSE) {
        xbee.getResponse().getRx16Response(rx16);
        option = rx16.getOption();
        data = rx16.getData(0);
      } else {
        xbee.getResponse().getRx64Response(rx64);
        option = rx64.getOption();
        data = rx64.getData(0);
      }

      // TODO check option, rssi bytes
      switch (data)
    {
      case 'A' :

        digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          delay(10);

          break;
        case 'D' :

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          delay(10);

          break;

        case 'S' :

          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          delay(10);

          break;
        case 'W' :

          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          delay(10);
          break;

        default :
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, LOW);
      }

      // set dataLed PWM to value of the first byte in the data

    } else {
      // not something we were expecting

    }
  } else if (xbee.getResponse().isError()) {
    //nss.print("Error reading packet.  Error code: ");
    //nss.println(xbee.getResponse().getErrorCode());
    // or flash error led
  }
}
