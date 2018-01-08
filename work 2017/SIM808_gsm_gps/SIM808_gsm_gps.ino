
char incoming_char = 0;
String str;
long i ;
int strl ;
int x = 0 ;
char num[15];
String phone ;
#include <SoftwareSerial.h>
SoftwareSerial SIM808(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
  SIM808.begin(9600);
  delay(5000);


  SIM808.print("AT+CMGF=1\r");
  delay(50);
  
  SIM808.print("AT+CNMI=2,2,0,0,0\r");

  delay(50);

  SIM808.print("AT+CGNSPWR=1\r");

  delay(50);
  SIM808.print("AT+CMEE=1\r");
  delay(50);

Serial.println("starting");
}




void loop()
{

  if (SIM808.available() > 0)
  {
    incoming_char = SIM808.read();
    Serial.print(incoming_char);
    str = str + incoming_char ;
    strl = str.length();

    if (str.substring((strl - 4) , strl - 1) == "CMT") {
      Serial.println("found CMT");
      str = "";

    }
    if (str.substring((strl - 4) , strl - 1) == "NF:") {
      Serial.println("found INF");
      str = "";
    }

    if (incoming_char == '?' )
    {
      phone = str.substring(1, 17);
      Serial.println("");
      Serial.print("phone num = ");
      Serial.println(phone);
      str = "";
      x ++ ;
      strl = 0 ;
      SIM808.println("AT + CGNSINF");

    }

    if ((x >= 1 ) && ( strl >= 45 )) {
      String lat = str.substring(23 , 32 );
      String lon = str.substring(33 , 42 );
      Serial.print("lattitude = ");
      Serial.println(lat);
      Serial.print("longitude = ");
      Serial.println(lon);
      x = 0 ;
      String sms ;
      sms = "lattitude ="  + lat + "      " + "longitude =" + lon  +"          " + "http://maps.google.com/maps?q=" + lat +"," + lon ;


      SIM808.print("AT+CMGS=");  // recipient's mobile number, in international format
      SIM808.println(phone);
      delay(100);


      SIM808.println(sms);                         // message to send
      delay(100);
      SIM808.println((char)26);                        // End AT command with a ^Z, ASCII code 26
      delay(100);
      SIM808.println();
      delay(5000);
    }

  }


}


