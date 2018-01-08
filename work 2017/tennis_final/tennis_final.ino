#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BRAKE 0
#define CW    1
#define CCW   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").

//MOTOR 1
#define MOTOR_A1_PIN 8
#define MOTOR_B1_PIN 7

//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9

#define PWM_MOTOR_1 5
#define PWM_MOTOR_2 6

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN_PIN_1 A0
#define EN_PIN_2 A1

#define MOTOR_1 0
#define MOTOR_2 1

short usSpeed = 200;  //default motor speed
unsigned short usMotor_Status = BRAKE;
 LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo servo1 ;
int c = 0;


void setup() {
servo1.attach(25);
servo1.write(10);
  lcd.begin();
  lcd.backlight();

pinMode(22,INPUT_PULLUP);
pinMode(24,INPUT_PULLUP);
pinMode(26,INPUT_PULLUP);
pinMode(28,INPUT_PULLUP);
pinMode(A8,INPUT_PULLUP);
pinMode(A9,INPUT);

Serial.begin(9600);
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);

  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(CURRENT_SEN_2, OUTPUT);  

  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);


lcd.print("TIME TO SHOOT :");

    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH); 


     while(digitalRead(26) > 0 ){
  motorGo(MOTOR_1, CW, 150);
}
Stop();

while(digitalRead(24) > 0 ){
    motorGo(MOTOR_2, CCW, 200);

}
Stop();


}

void loop() {
  // put your main code here, to run repeatedly:
shoot();

     while(digitalRead(28) > 0 ){
  motorGo(MOTOR_1, CCW, usSpeed);
}
Stop();

shoot();

     while(analogRead(A9) < 700 ){
      if (digitalRead(26) > 0 )
  motorGo(MOTOR_1, CW, 200);
}
Stop();

shoot();


while(digitalRead(22) > 0 ){
    motorGo(MOTOR_2, CW, usSpeed);

}
Stop();

shoot();


while(digitalRead(24) > 0 ){
    motorGo(MOTOR_2, CCW, usSpeed);

}
Stop();

     while(digitalRead(26) > 0 ){
  motorGo(MOTOR_1, CW, 100);
}
Stop();










}


void shoot() {
  int x = map(analogRead(A8) , 0,1023 , 1, 50 );
  lcd.setCursor(0, 1);
lcd.print(x + 3);
lcd.print(" Seconds");
delay(x * 1000) ;
servo1.write(170);
delay(900);
servo1.write(10);

}
void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Function that controls the variables: motor(0 ou 1), direction (cw ou ccw) e pwm (entra 0 e 255);
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_1, pwm); 
  }
  else if(motor == MOTOR_2)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_2, pwm);
  }
}


