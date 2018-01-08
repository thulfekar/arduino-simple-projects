#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
#include <Servo.h> 
char incoming_char = 0;
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
   myservo.attach(4);
   myservo.write(45);
   delay(1000);
   myservo.write(0);
  Serial.begin(19200); // for serial monitor
  SIM900.begin(19200); // for GSM shield

  delay(20000);
  SIM900.print("AT+CMGF=1\r");
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  pinMode ( 2, OUTPUT);
  pinMode ( 3, OUTPUT);
  pinMode ( 4, OUTPUT);
  pinMode ( 5, OUTPUT);

}

void loop()
{
  if (SIM900.available() > 0)
  {
    incoming_char = SIM900.read(); //Get the character from the cellular serial port.
    Serial.print(incoming_char); //Print the incoming character to the terminal.

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
            analogWrite(5, 50);
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

      case 'F':
        c = 1;
        break;

      case 'N':
        if ((c > 0 ) && (d > 0 )) {
          if (fanpin == "OFF") {
            analogWrite(3, 50);
            fanpin = "ON" ;
            c = 0;
            d = 0;
          }
          else if (fanpin == "ON") {
            digitalWrite(3, LOW);
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
            digitalWrite(2, HIGH);
            acpin = "ON" ;
            b = 0 ;
          }
          else if (acpin == "ON") {
            digitalWrite(2, LOW);
            acpin = "OFF" ;
            b = 0 ;
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
            myservo.write(95);
            doorpin = "OPEN" ;
            e = 0 ;
            f = 0 ;
          }
          else if (doorpin == "OPEN") {
            myservo.write(0);
            doorpin = "CLOSED" ;
            e = 0 ;
            f = 0 ;
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
  SIM900.println("AT + CMGS = \"009647707231272\"");  // recipient's mobile number, in international format
  delay(100);
  SIM900.println(message);                         // message to send
  delay(100);
  SIM900.println((char)26);                        // End AT command with a ^Z, ASCII code 26
  delay(100);
  SIM900.println();
  delay(5000);                                     // give module time to send SMS
}
