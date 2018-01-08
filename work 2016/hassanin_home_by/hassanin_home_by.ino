
#include <Keypad.h>
char hhh[4] ;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {41, 43, 45 , 47}; //connect to the row pinouts of the keypad
byte colPins[COLS] =  {40 , 42, 44, 46 }; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int i ;
int c = 0 ;
int j = 0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  Serial.begin(9600);
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);

}

void loop() {

  char key = keypad.getKey();



  if (key) {

    if (key == '#' ) {
      if ((hhh[0] == '0') && ( hhh[1] == '0' ) && (hhh[2] == '0' )) {
        if (j < 1 ) {
          
          j ++ ;
        }
        else if (j > 0 ) {
          j-- ;
        }
      }
    }
    hhh[i] = key ;
    i ++ ;
    if ( i >= 3 )    i = 0 ;

  }

  Serial.println(hhh);


  if ( (digitalRead(A0) > 0 ) || ( digitalRead(4) > 0 ) ) {

    if (j < 1 ) {
     opengate();
      j ++ ;
      goto ending;
    }
    else if (j > 0 ) {
      closegate();
      j-- ;
      goto ending;
    }
  }




if (digitalRead(5) > 0 ) {
  if (c < 1) {
    c = 1 ;
    opendoor();
    goto ending;
  }

  else if (c > 0 ) {
    c = 0 ;
    closedoor();

    goto ending ;


  }
}
ending:
Serial.println("nothing");

}
