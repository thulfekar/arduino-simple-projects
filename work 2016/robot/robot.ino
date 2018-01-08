#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE0 };
IPAddress ip(192,168,0, 125);
IPAddress gateway(192,168,0, 1);
IPAddress subnet(255, 255, 0, 0);


// telnet defaults to port 23
EthernetServer server(23);
boolean alreadyConnected = false; // whether or not the client was connected previously


const int dout0 = 34;
const int dout1 = 49;
const int dout2 = 36;
const int dout3 = 47;
const int dout4 = 38;
const int dout5 = 45;
const int dout6 = 40;
const int dout7 = 43;
const int dout8 = 42;
const int dout9 = 41;
const int douta = 44;
const int doutb = 39;
const int doutc = 46;
const int doutd = 37;
const int doute = 48;
const int doutf = 35;
int leds[16]={36,49,34,47,40,45,38,43,46,41,42,39,48,37,44,35};



void setup() {
  
  pinMode(dout0, OUTPUT);
  pinMode(dout1, OUTPUT);
  pinMode(dout2, OUTPUT);
  pinMode(dout3, OUTPUT);
  pinMode(dout4, OUTPUT);
  pinMode(dout5, OUTPUT);
  pinMode(dout6, OUTPUT);
  pinMode(dout7, OUTPUT);
  pinMode(dout8, OUTPUT);
  pinMode(dout9, OUTPUT);
  pinMode(douta, OUTPUT);
  pinMode(doutb, OUTPUT);
  pinMode(doutc, OUTPUT);
  pinMode(doutd, OUTPUT);
  pinMode(doute, OUTPUT);
  pinMode(doutf, OUTPUT);
  // initialize the ethernet device
  Ethernet.begin(mac, ip, gateway, subnet);
  // start listening for clients
  server.begin();
 // Open serial communications and wait for port to open:
  Serial.begin(115200);


  Serial.print("Robot Address:");
  Serial.println(Ethernet.localIP());
}

unsigned int n1,n2,n3,n4,n,k;
char s1,s2,s3,s4;
int i,d;
int indx = -1;

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      // clead out the input buffer:
      client.flush();    
      Serial.println("We have a new Remote");
      client.println("Remote is connected!"); 
      alreadyConnected = true;
    } 

    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char c = client.read();
    if(indx==3){s4=c;indx=4;}
    if(indx==2){s3=c;indx=3;}
    if(indx==1){s2=c;indx=2;}
    if(indx==0){s1=c;indx=1;}
    if((c=='[')&&(indx==-1))indx=0;
    
    if((c==']')&&(indx==4)){
       indx=-1;
      if(s1<='9')n1=s1-48;else n1 = s1 - 55;
      if(s2<='9')n2=s2-48;else n2 = s2 - 55;
      if(s3<='9')n3=s3-48;else n3 = s3 - 55;
      if(s4<='9')n4=s4-48;else n4 = s4 - 55;
      n1 &=0xf;n2 &=0xf;n3 &=0xf;n4 &=0xf;
      Serial.print(n1,HEX);Serial.print(",");
      Serial.print(n2,HEX);Serial.print(",");
      Serial.print(n3,HEX);Serial.print(",");
      Serial.println(n4,HEX);
       n = (n1<<12) + (n2<<8) + (n3<<4) + n4 ;
       k = 0 ;
       Serial.println(n,HEX);
       for ( i = 34 ; i <50 ; ++i ){
         d = (n>>k)&1;
         digitalWrite(leds[k],1-d);
         //Serial.print(d);
         if(d==0)Serial.print(i);
         ++k;  
       } 
       Serial.println("");
  }      
      
      
      // echo the bytes back to the client:
      server.write(c);
      // echo the bytes to the server as well:
      Serial.write(c);
    }
  }
}
