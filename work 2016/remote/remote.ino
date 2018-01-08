#include <SPI.h>
#include <Ethernet.h>
#include <PS3USB.h>
// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;
PS3USB PS3(&Usb); 

const int din0 = 34;
const int din1 = 35;
const int din2 = 36;
const int din3 = 37;
const int din4 = 38;
const int din5 = 39;
const int din6 = 40;
const int din7 = 41;
const int din8 = 42;
const int din9 = 43;
const int dina = 44;
const int dinb = 45;
const int dinc = 46;
const int dind = 47;
const int dine = 48;
const int dinf = 49;
unsigned int prv_din = 65535 ;
unsigned int prv_ps3 = 65335 ;
unsigned int prv_dd = 65535;
unsigned int dd=0xffff;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE1 };
IPAddress ip(192,168,0,126);

// Enter the IP address of the server you're connecting to:
IPAddress server(192,168,0,125); 

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 23 is default for telnet;
// if you're using Processing's ChatServer, use  port 10002):
EthernetClient client;

void setup() {
  // start the Ethernet connection:
  Ethernet.begin(mac, ip);
 // Open serial communications and wait for port to open:
  Serial.begin(115200);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
  }
  Serial.print(F("\r\nPS3 USB Library Started\r\n"));
  pinMode(din0, INPUT_PULLUP);
  pinMode(din1, INPUT_PULLUP);
  pinMode(din2, INPUT_PULLUP);
  pinMode(din3, INPUT_PULLUP);
  pinMode(din4, INPUT_PULLUP);
  pinMode(din5, INPUT_PULLUP);
  pinMode(din6, INPUT_PULLUP);
  pinMode(din7, INPUT_PULLUP);

  pinMode(din8, INPUT_PULLUP);
  pinMode(din9, INPUT_PULLUP);
  pinMode(dina, INPUT_PULLUP);
  pinMode(dinb, INPUT_PULLUP);
  pinMode(dinc, INPUT_PULLUP);
  pinMode(dind, INPUT_PULLUP);
  pinMode(dine, INPUT_PULLUP);
  pinMode(dinf, INPUT_PULLUP);

  // give the Ethernet shield a second to initialize:
 
  Serial.println("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 23)) {
    Serial.println("connected");
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}
unsigned int ps3 = 0xffff;
void loop()
{
  // if there are incoming bytes available 
  // from the server, read them and print them:
 /* if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
*/
  // as long as there are bytes in the serial queue,
  // read them and send them out the socket if it's open:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    if (client.connected()) {
      client.print(inChar); 
    }
  }
  
  
   ps3 = 0xffff;
 
Usb.Task();
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
    
       if(PS3.getAnalogHat(LeftHatY)>200) ps3 &= 0xfffd ;//1
      if(PS3.getAnalogHat(LeftHatX)>200) ps3 &= 0xfff7 ;//3
      
      if(PS3.getAnalogHat(LeftHatX)<55) ps3 &= 0xffdf ;//5
      if(PS3.getAnalogHat(LeftHatY)<55) ps3 &= 0xff7f ;//7
    
      if(PS3.getAnalogHat(RightHatY)>200) ps3 &= 0xfdff ;//9
      if(PS3.getAnalogHat(RightHatX)>200) ps3 &= 0xf7ff ;//11
      
      if(PS3.getAnalogHat(RightHatX)<55) ps3 &= 0xdfff ;//13
      if(PS3.getAnalogHat(RightHatY)<55) ps3 &= 0x7fff ;//15
    

    if (PS3.getButtonPress(TRIANGLE)==1){ps3 &=0xffbf;}//6
    if (PS3.getButtonPress(CIRCLE)==1){ps3 &=0xfffb;}//2
    if (PS3.getButtonPress(CROSS)==1){ps3 &=0xfffe;}//0
    if (PS3.getButtonPress(SQUARE)==1){ps3 &=0xffef;}//4

    if (PS3.getButtonPress(UP)==1){ps3 &=0xbfff;}//14
    if (PS3.getButtonPress(RIGHT)==1){ps3 &=0xfbff;}//10
    if (PS3.getButtonPress(DOWN)==1) {ps3 &=0xfeff;}//8
    if (PS3.getButtonPress(LEFT)==1) {ps3 &=0xefff;}//12
  }


  unsigned int d = 0 ;
    int  b, k = 0;
    for( int i = 34 ; i< 50 ; ++i){
    b = digitalRead(i)&1;delay(5);
    b = digitalRead(i)&1;delay(5);
    b = digitalRead(i)&1;
    
    
    d |= (b<<k);
    ++k;
    }
    
 if(ps3 != prv_ps3){
     dd = ps3 ;
    prv_ps3 = ps3;
  }
  else if(d!=prv_din){
  dd = d ;
  prv_din = d ;

}

if(dd != prv_dd){
 prv_dd = dd ;
  if (client.connected()) {
       client.print("Input: [");
       client.print(dd,HEX);
       client.println("]");
  }
  else{
    client.stop();
    if (client.connect(server, 23)) {
    Serial.println("connected");
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  }
 }//IFDD
  
  
  
  
/*
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    // do nothing:
    while(true);
  }
  */
}

