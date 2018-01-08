#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
#include <Servo.h> 
char incoming_char = 0;
String info ;
#include <Keypad.h>
Servo myservo;
char hhh[4] ;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {24 , 34, 32,28 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 22, 30}; //connect to the column pinouts of the keypad
int i ;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   pinMode ( 2, OUTPUT);
  pinMode ( 3, OUTPUT);
  pinMode ( 4, OUTPUT);
  pinMode ( 5, OUTPUT);
  myservo.attach(12);
  Serial.begin(19200);
  SIM900.begin(19200); 
  pinMode(13,OUTPUT);
  myservo.write(0);
  
  delay(20000);
  SIM900.print("AT+CMGF=1\r");
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);

}
  
void loop(){


  char key = keypad.getKey();
  
  if (key){
   hhh[i] = key ;
   i ++ ;
   if ( i >= 3 )    i = 0 ;

   
   
   Serial.println(hhh);
   if ((hhh[0] == '3') && ( hhh[1] == '6' ) && (hhh[2] == '9' ))
   
    digitalWrite (13 , HIGH);
   else
   digitalWrite(13 , LOW);
   
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
