/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
             // tell servo to go to position in variable 'pos' 
myservo.attach(4);  // attaches the servo on pin 9 to the servo object 
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);


} 
 
void loop() 
{ 
    
delay(200);
myservo.write(0);              // tell servo to go to position in variable 'pos' 
    delay(3000);  

             myservo.write(100);              // tell servo to go to position in variable 'pos' 
   digitalWrite(2,HIGH);
   analogWrite(3,50);
   analogWrite(5,50);
   
    delay(3000);           
myservo.write(0); 
digitalWrite(2,LOW);
analogWrite(3,0);
analogWrite(5,0);

} 

