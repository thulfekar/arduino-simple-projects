#include <TM74HC595Display.h>
#include <Servo.h>
Servo ser1;
Servo ser2;
int SCLK = 7;
int RCLK = 6;
int DIO = 5;
  int h = 0 ;
  int y = 0 ;

TM74HC595Display disp(SCLK, RCLK, DIO);
unsigned char LED_0F[29];

void setup() {
  ser1.attach(2);
  ser2.attach(3);

  LED_0F[0] = 0xC0; //0
  LED_0F[1] = 0xF9; //1
  LED_0F[2] = 0xA4; //2
  LED_0F[3] = 0xB0; //3
  LED_0F[4] = 0x99; //4
  LED_0F[5] = 0x92; //5
  LED_0F[6] = 0x82; //6
  LED_0F[7] = 0xF8; //7
  LED_0F[8] = 0x80; //8
  LED_0F[9] = 0x90; //9
  LED_0F[10] = 0x88; //A
  LED_0F[11] = 0x83; //b
  LED_0F[12] = 0xC6; //C
  LED_0F[13] = 0xA1; //d
  LED_0F[14] = 0x86; //E
  LED_0F[15] = 0x8E; //F
  LED_0F[16] = 0xC2; //G
  LED_0F[17] = 0x89; //H
  LED_0F[18] = 0xF9; //I
  LED_0F[19] = 0xF1; //J
  LED_0F[20] = 0xC3; //L
  LED_0F[21] = 0xA9; //n
  LED_0F[22] = 0xC0; //O
  LED_0F[23] = 0x8C; //P
  LED_0F[24] = 0x98; //q
  LED_0F[25] = 0x92; //S
  LED_0F[26] = 0xC1; //U
  LED_0F[27] = 0x91; //Y
  LED_0F[28] = 0xFE; //hight -
  Serial.begin(9600);

}

void loop() {  

  int x = 0 ;
  int g ;
  int j = 0 ;
  int l;

  
  for(int i = 0; i<=1000; i++){
    disp.digit4showZero(i, 1550);               //send counter 0-100 with delay 50 cicles with zero

    x ++ ;
    g = x % 5 ; 
    if ( g == 0 ){
    Serial.println("pass");

      if (y < 1) ser1.write(55);
      if (y > 0 ) ser1.write(130);
      if (y < 1 ) y = 1 ;
      else y = 0 ;
    }


    j ++ ;
    l = j % 7 ; 
    if ( l == 0 ){
    Serial.println("pass2");

      if (h < 1) ser2.write(55);
      if (h > 0 ) ser2.write(130);
      if (h < 1 ) h = 1 ;
      else h = 0 ;
    }

  }
  
}


