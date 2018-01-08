#include <SoftwareSerial.h>
SoftwareSerial SIM900(10, 9);
#include <Servo.h>
char incoming_char ;
String info ;
String tvpin = "OFF" ;
String acpin = "OFF" ;
String fanpin = "OFF" ;
String doorpin = "CLOSED" ;
Servo myservo;
int a = 0 ;
int b = 0 ;
int c = 0 ;
int d = 0 ;
int e = 0 ;
int f = 0 ;

void setup()
{
  myservo.attach(2);
  myservo.write(45);
  delay(10000);
  myservo.write(0);
  
  SIM900.begin(19200); // for GSM shield
  

  SIM900.print("AT+CMGF=1\r");
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);

  pinMode ( 6, OUTPUT);
  pinMode ( 4, OUTPUT);
  pinMode ( 5, OUTPUT);
  pinMode ( 7, OUTPUT);
  pinMode ( 14, OUTPUT);
  pinMode ( 15, OUTPUT);
  pinMode ( 16, OUTPUT);
  pinMode ( 17, OUTPUT);
  pinMode ( 18, OUTPUT);
  pinMode ( 19, OUTPUT);
  digitalWrite(14,HIGH);
  digitalWrite(15,HIGH);
  digitalWrite(16,HIGH);
  digitalWrite(17,HIGH);
  digitalWrite(18,HIGH);
  digitalWrite(19,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  
}

void loop()
{
  if (SIM900.available() > 0)
  {
    incoming_char = SIM900.read(); //Get the character from the cellular serial port.
    

    switch ( incoming_char ) {

      case '?' :

        info = info + "T.V. is " ;
        info += tvpin;
        info = info + " ...";
        info = info + "A.C. is ";
        info += acpin;
        info = info + " ...";
        info = info + "F.A.N is " ;
        info += fanpin;
        info = info + " ...";
        info = info + "D.O.O.R is " ;
        info += doorpin;

        sendSMS(info);
        delay(3000);
        info = " " ;

        break;

      case 'T':
        a = 1;
        break;

      case 'V':
        if (a > 0 ) {
          if (tvpin == "OFF") {
            digitalWrite(5, HIGH);
            tvpin = "ON" ;
            a = 0 ;
          }
          else if (tvpin == "ON") {
            digitalWrite(5, LOW);
            tvpin = "OFF" ;
            a = 0 ;
          }
        }
        break;
 case 'D':
        e  = 1;
        break;

      case 'O':
        f  = 1;
        break;

      case 'R':
        if ((e > 0 ) && (f > 0)) {
          if (doorpin == "CLOSED") {
            digitalWrite(7,LOW);
            delay(300);
            myservo.write(95);
            doorpin = "OPEN" ;
            e = 0 ;
            f = 0 ;
            delay(1000);
            digitalWrite(7,HIGH);
            
          }
          else if (doorpin == "OPEN") {
            digitalWrite(7,LOW);
            delay(300);
            myservo.write(0);
            doorpin = "CLOSED" ;
            e = 0 ;
            f = 0 ;
            delay(1000);
            digitalWrite(7,HIGH);
          }
        }
        break;



      case 'F':
        c = 1;
        break;

      case 'N':
        if ((c > 0 ) && (d > 0 )) {
          if (fanpin == "OFF") {
            analogWrite(4, LOW);
            fanpin = "ON" ;
            c = 0;
            d = 0;
          }
          else if (fanpin == "ON") {
            digitalWrite(4, HIGH);
            fanpin = "OFF" ;
            c = 0;
            d = 0;
          }
        }
        break;

      case 'A':
        b = 1;
        d = 1;
        break;

      case 'C':
        if (b > 0 ) {
          if (acpin == "OFF") {
            digitalWrite(6, HIGH);
            acpin = "ON" ;
            b = 0 ;
          }
          else if (acpin == "ON") {
            digitalWrite(6, LOW);
            acpin = "OFF" ;
            b = 0 ;
          }
        }
        break;

     
      default:
        a = 0 ;
        b = 0 ;
        c = 0 ;
        d = 0 ;
        e = 0 ;
        f = 0 ;

        break;


    }

  }
}


void sendSMS(String message)
{
  SIM900.println("AT + CMGS = \"009647702886634\"");  // recipient's mobile number, in international format
  delay(100);
  SIM900.println(message);                         // message to send
  delay(100);
  SIM900.println((char)26);                        // End AT command with a ^Z, ASCII code 26
  delay(100);
  SIM900.println();
  delay(5000);                                     // give module time to send SMS
}
