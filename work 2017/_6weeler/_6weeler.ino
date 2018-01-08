/*
   Created by Vasilakis Michalis // 12-12-2014 ver.1
   Project: Control RC Car via Bluetooth with Android Smartphone
   http://www.ardumotive.com/arduino-car
   More information at www.ardumotive.com
*/
#include <Servo.h>
Servo servo;
//L293 Connection
const int motorA1  = 5;  // Pin  2 of L293
const int motorA2  = 6;  // Pin  7 of L293
const int motorB1  = 10; // Pin 10 of L293
const int motorB2  = 9;  // Pin 14 of L293
//Leds connected to Arduino UNO Pin 12
const int lights  = 12;
//Buzzer / Speaker to Arduino UNO Pin 3
const int buzzer = 3 ;
//Bluetooth (HC-06 JY-MCU) State pin on pin 2 of Arduino
const int BTState = 2;
//Calculate Battery Level
const float maxBattery = 8.0;// Change value to your max battery voltage level!
int perVolt;                 // Percentage variable
float voltage = 0.0;         // Read battery voltage
int level;
// Use it to make a delay... without delay() function!
long previousMillis = -1000 * 10; // -1000*10=-10sec. to read the first value. If you use 0 then you will take the first value after 10sec.
long interval = 1000 * 10;     // interval at which to read battery voltage, change it if you want! (10*1000=10sec)
unsigned long currentMillis;   //unsigned long currentMillis;
//Useful Variables
int i = 0;
int j = 0;
int state;
int vSpeed = 200;   // Default speed, from 0 to 255
int qq = 90;
void setup() {
  // Set pins as outputs:
  pinMode(30, OUTPUT);
  pinMode(31, INPUT);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(lights, OUTPUT);
  pinMode(BTState, INPUT);
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  servo.attach(4);
  servo.write(90);
}

void loop() {
  //Stop car when connection lost or bluetooth disconnected
  // if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
  if (Serial.available() > 0) {
    state = Serial.read();
  }


  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
  if (state == '0') {
    vSpeed = 0;
  }
  else if (state == '2') {
    vSpeed = 50;
  }
  else if (state == '4') {
    vSpeed = 100;
  }
  else if (state == '6') {
    vSpeed = 160;
  }
  else if (state == '8') {
    vSpeed = 190;
  }
  else if (state == 'q') {
    vSpeed = 255;
  }


  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
  if (state == 'F') {
    digitalWrite(30, LOW);
    delayMicroseconds(2);
    digitalWrite(30, HIGH);
    delayMicroseconds(5);
    digitalWrite(30, LOW);
    long duration = pulseIn(31, HIGH);
   
    analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0);
 if (( duration / 29 / 2 ) <= 30 ) {
   analogWrite(motorA1, 0); analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);      analogWrite(motorB2, 0);

 }

  }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
  else if (state == 'G') {
    analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);    analogWrite(motorB2, 0);
  }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
  else if (state == 'I') {
    analogWrite(motorA1,100 ); analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0);
  }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
  else if (state == 'B') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);
  }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
  else if (state == 'H') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0); analogWrite(motorB2, 100);
  }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
  else if (state == 'J') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, 100 );
    analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);
  }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
  else if (state == 'L') {
    analogWrite(motorA1, 200);   analogWrite(motorA2, 0);
    analogWrite(motorB1, 0); analogWrite(motorB2, 200);
  }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
  else if (state == 'R') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, 200);
    analogWrite(motorB1, 200);   analogWrite(motorB2, 0);
  }
  /************************Lights*****************************/
  //If state is equal with letter 'W', turn leds on or of off
  else if (state == 'W') {
    if (i == 0) {
      digitalWrite(lights, HIGH);
      i = 1;
    }
    else if (i == 1) {
      digitalWrite(lights, LOW);
      i = 0;
    }
    state = 'n';
  }
  /**********************Horn sound***************************/
  //If state is equal with letter 'V', play (or stop) horn sound
  else if (state == 'V') {
    if (j == 0) {
      tone(buzzer, 1000);//Speaker on
      j = 1;
    }
    else if (j == 1) {
      noTone(buzzer);    //Speaker off
      j = 0;
    }
    state = 'n';
  }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
  else if (state == 'S') {
    analogWrite(motorA1, 0);  analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
  }
  /***********************Battery*****************************/
  else if (state == 'y') {
    qq = qq - 1 ;
    if (qq <= 10 ) qq = 10 ;
    servo.write(qq);
    delay(10);

  }
  else if (state == 'x') {
    qq = qq + 1 ;
    if (qq >= 170 ) qq = 170 ;
    servo.write(qq);
    delay(10);

  }

  else if (state == 'z') {
    qq = 90 ;
    servo.write(qq);

  }
}



