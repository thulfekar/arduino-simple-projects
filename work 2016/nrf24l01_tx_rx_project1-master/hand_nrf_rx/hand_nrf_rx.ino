#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define CE_PIN 9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E2LL; // Define the transmit pipe
int serv1 = 0 ;
int serv2 = 0 ;
int serv3 = 0 ;
int serv4 = 0 ;
int serv5 = 0 ;
Servo fin1;  // create servo object to control a servo
Servo fin2;
Servo fin3;
Servo fin4;
Servo fin5;
Servo fin6;
Servo fin7;
/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[9];  // 6 element array holding Joystick readings

void setup()   /****** SETUP: RUNS ONCE ******/
{

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);


  Serial.begin(9600);
  delay(1000);


  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();;
  fin1.attach(14);  // attaches the servo on pin 9 to the servo object
  fin2.attach(15);
  fin3.attach(16);
  fin4.attach(7);
  fin5.attach(18);
  fin6.attach(19);
  fin7.attach(6);
  delay(1000);

  fin1.write(90);              // tell servo to go to position in variable 'pos'
  fin2.write(180);
  fin3.write(180);
  fin4.write(180);
  fin5.write(180);
  fin6.write(180);
  fin7.write(90);
}//--(end5 setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {
      radio.read( joystick, sizeof(joystick) );




      // the four button variables from joystick array
      int f1 = joystick[2];
      int f2 = joystick[3];
      int f3 = joystick[4];
      int f4 = joystick[5];
      int f5 = joystick[6];
      int joystickX = joystick[0];
      int joystickY = joystick[1];
      int x = joystick[7];
      int y = joystick[8];

      if ( (joystickX < 1) || (joystickY < 1))
        return;




      if (joystick[0] >= 900 )
      {
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
      }

      else if  (joystick[0] <= 100 )
      {

        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);

      }
      else if (joystick[1] >= 900 )
      {
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
      }
      else if  (joystick[1] <= 100 )
      {
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
      }
      else
      { digitalWrite(2 , HIGH);
        digitalWrite(3 , HIGH);
        digitalWrite(4 , HIGH);
        digitalWrite(5 , HIGH);

      }
      if (y > 60 )
        fin7.write(0);
        else
        if ((y + 120) < 0 )
      fin7.write(180);
      else
        fin7.write(90);


        if (x > 50 )
        fin1.write(140);
        else if ((x+140) < 0)
        fin1.write(45);
        else fin1.write(90);
      fin2.write(f1);
      fin3.write(f2);
      fin4.write(f5);
      fin5.write(f4);
      fin6.write(f3);
      delay(20);





      delay(10);
      // Fetch the data payload - Debugging code below

      Serial.print("X = ");

      Serial.print(joystick[0]);
      Serial.print(" Y = ");

      Serial.print(joystick[1]);
      Serial.print(" Up = ");

      Serial.print(joystick[2]);
      Serial.print(" Right = ");

      Serial.print(joystick[3]);
      Serial.print(" Down = ");

      Serial.print(joystick[4]);
      Serial.print(" Left = ");

      Serial.print(joystick[5]);
      Serial.print(" other = ");
      Serial.print(joystick[6]);

      Serial.print(" x= ");

      Serial.print(joystick[7]);
      Serial.print(" y= ");

      Serial.println(joystick[8]);

    }
  }
  else
  {
    Serial.println("No radio available");
  }

}
