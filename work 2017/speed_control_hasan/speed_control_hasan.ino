#include <TimerOne.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

unsigned int counter = 0;

int b1a = 6;  // motor pin
int motorspeed = 50 ; // start speed
int rotation ;
int rps = 5 ;
int g;
void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
}

void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
  Serial.print("Motor Speed: ");
  rotation = (counter / 20);  // divide by number of holes in Disc
  Serial.print(rotation, DEC);
  Serial.print(" Rotation per seconds");
  Serial.print("---- Required round per seconds = ");
  Serial.print(rps);
  Serial.print("---- voltage feed = ");
  Serial.print(g);
  Serial.println("%");


  if ( (rotation - rps) > 0 ) motorspeed = motorspeed - 5 ;
  if ( (rps - rotation) > 0 ) motorspeed = motorspeed + 5 ;
  if (motorspeed < 50) motorspeed = 50;
  if (motorspeed > 255) motorspeed = 255;
  g = map(motorspeed , 50 , 255 , 0 , 100 );
  counter = 0; //  reset counter to zero
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(b1a, OUTPUT);
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(0, docount, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt( timerIsr ); // enable the timer
}

void loop()
{
  int potvalue = analogRead(1);  // Potentiometer connected to Pin A1
  rps = map(potvalue, 0, 1024, 30, 0); // required speed limit


  analogWrite(b1a, motorspeed);  // set speed of motor (0-255)
lcd.setCursor(0, 0);
lcd.print("Selct Spd:");
lcd.print(rps);
lcd.print(" RPS");
  lcd.setCursor(0, 1);
  lcd.print("Motor Spd:");
  lcd.print(rotation);
  lcd.print(" RPS");
  

}
