#include <Servo.h>
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

#define aS0 26
#define aS1 27
#define aS2 28
#define aS3 29
#define asensorOut 30
#define bS0 32
#define bS1 33
#define bS2 34
#define bS3 35
#define bsensorOut 36
#define riir 38
#define leir 39
#define tiltup 30
#define tiltdown 120
#define panleft 160
#define panright 40
#define center 90
#define graberopen 10
#define graberclosed 60
#define readerdown 20
#define readerup 120
short usSpeed = 60;  //default motor speed
unsigned short usMotor_Status = BRAKE;


Servo pan;
Servo tilt;
Servo graber;
Servo reader;

int frequency = 0;
int c = 0 ;
int red = 0;
int green = 0;
int blue = 0;
char chr;
void setup() {
  pan.attach(22);
  tilt.attach(23);
  graber.attach(24);
  reader.attach(25);

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

  pinMode(aS0, OUTPUT);
  pinMode(aS1, OUTPUT);
  pinMode(aS2, OUTPUT);
  pinMode(aS3, OUTPUT);
  pinMode(asensorOut, INPUT);
  pinMode(bS0, OUTPUT);
  pinMode(bS1, OUTPUT);
  pinMode(bS2, OUTPUT);
  pinMode(bS3, OUTPUT);
  pinMode(bsensorOut, INPUT);

  pinMode(riir, INPUT);
  pinMode(leir, INPUT);
  digitalWrite(aS0, HIGH);
  digitalWrite(aS1, LOW);
  digitalWrite(bS0, HIGH);
  digitalWrite(bS1, LOW);
  graber.write(graberopen);
  tilt.write(tiltup);

  digitalWrite(EN_PIN_1, HIGH);
  digitalWrite(EN_PIN_2, HIGH);

 chr =  'x' ;
}



void loop() {

 
 int rir = digitalRead(riir);
  int lir = digitalRead(leir);
  if  ((rir > 0 ) && (lir > 0 )) {
    Stop();
    return;
  }
  else if ((rir < 1 ) && (lir < 1 ))
   {
    Forward();
      floorcolor();
      Stop();
   }
  else if ((rir > 0 ) && (lir < 1 ) )
  {
    right();
    delay(10);
    Stop();
    return;
  }
  else if ((rir < 1 ) && (lir > 0 ))
  {
    left();
    delay(10);
    Stop();
    return;
  }


  if ( (red < 200 ) && (green < 200 ) && (blue < 200 ))
    return;
  else if ( (red > 200 ) && (green > 200 ) && (blue > 200 ) && ( chr ==  'x' ))
    grabobject();
  else if (  (red < 100 ) && (green > 100 ) && (blue > 100 ) && ( chr == 'r' ))
    putdown();
  else if (  (red > 100 ) && (green < 100 ) && (blue > 100 ) && ( chr == 'g' ))
    putdown();
  else if (  (red > 100 ) && (green > 100 ) && (blue < 100 ) && ( chr == 'b' ))
    putdown();



}


void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);
}

void Forward()
{
  Serial.println("Forward");
  usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void right()
{
  usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  usMotor_Status = CCW;
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}

void left()
{
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  usMotor_Status = CW;
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}
void Reverse()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
}


void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Function that controls the variables: motor(0 ou 1), direction (cw ou ccw) e pwm (entra 0 e 255);
{
  if (motor == MOTOR_1)
  {
    if (direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if (direct == CCW)
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
  else if (motor == MOTOR_2)
  {
    if (direct == CW)
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if (direct == CCW)
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
