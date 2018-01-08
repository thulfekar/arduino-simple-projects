#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <Stepper.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // lcd pins
Stepper myStepper(200, 10, 11, 12, 13); // stepper pins

#define ONE_WIRE_BUS 8 // heat sensor pin   

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
int x ;

void setup() {
  sensors.begin();
  lcd.begin(16, 4);
  lcd.print("  Temp Control");
  myStepper.setSpeed(30);
  delay(500);
  myStepper.step(-800); // close the water all the way
  delay(500);
  x = 0 ;
}

void loop() {
  
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 1);
  lcd.print(Celsius);
  lcd.print(" C ");
  lcd.print("        ");
  delay(100);
    lcd.setCursor(10, 1);
    int y = map(x , 0 , 800 , 0 , 1440);
  lcd.print(y);
  lcd.print(" D");
  

  delay(100);

if ((Celsius > 20 ) && (x < 800 )) { // this will keep temp under 25 degree 
    myStepper.step(50); // 50 steps of opening the water
    x = x + 50 ;
    delay(1000);
  
}

if ((Celsius < 19 ) && ( x > 0)) { // this will keep temp over 25 degree
   myStepper.step(-50); // 50 stop of closing the water
    x = x - 50 ;
    delay(1000);
}


}
