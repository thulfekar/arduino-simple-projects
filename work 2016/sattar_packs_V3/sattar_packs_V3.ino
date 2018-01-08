

#include <EEPROM.h>     // We are going to read and write PICC's UIDs from/to EEPROM
#include <SPI.h>        // RC522 Module uses SPI protocol
#include <MFRC522.h>	// Library for Mifare RC522 Devices
#include <Keypad.h>

#define LED_ON 150
#define LED_OFF 0

#define button A2

#define redLed A3		// Set Led Pins
#define greenLed A4
#define blueLed A5
#define buzzer A7
#define relay A1			// Set Relay Pin
#define wipeB A0			// Button pin for WipeMode

boolean match = false;          // initialize card match to false
boolean programMode = false;	// initialize programming mode to false
boolean replaceMaster = false;
char incoming_char = 0;
String info ;
int successRead;		// Variable integer to keep if we have Successful Read from Reader

byte storedCard[4];		// Stores an ID read from EEPROM
byte readCard[4];		// Stores scanned ID read from RFID Module
byte masterCard[4];		// Stores master card's ID read from EEPROM



#define SS_PIN 9
#define RST_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.
char hhh[5] ;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2 }; //connect to the column pinouts of the keypad
int i ;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

///////////////////////////////////////// Setup ///////////////////////////////////
void setup() {
  //Arduino Pin Configuration
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(wipeB, INPUT_PULLUP);    // Enable pin's pull up resistor
  pinMode(button, INPUT_PULLUP);    // Enable pin's pull up resistor
  pinMode(relay, OUTPUT);

  //Be careful how relay circuit behave on while resetting or power-cycling your Arduino
  digitalWrite(relay, LOW);		// Make sure door is locked
  analogWrite(redLed, LED_OFF);	// Make sure led is off
  analogWrite(greenLed, LED_OFF);	// Make sure led is off
  analogWrite(blueLed, LED_OFF);	// Make sure led is off
  digitalWrite(buzzer , LOW);
  //Protocol Configuration
  Serial.begin(9600);	 // Initialize serial communications with PC
  SPI.begin();           // MFRC522 Hardware uses SPI protocol
  mfrc522.PCD_Init();    // Initialize MFRC522 Hardware

  //If you set Antenna Gain to Max it will increase reading distance
  //mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);

  Serial.println(F("Access Control v3.4"));   // For debugging purposes
  ShowReaderDetails();	// Show details of PCD - MFRC522 Card Reader details

  //Wipe Code if Button Pressed while setup run (powered on) it wipes EEPROM
  if (digitalRead(wipeB) == LOW) {	// when button pressed pin should get low, button connected to ground
    analogWrite(redLed, LED_ON);	// Red Led stays on to inform user we are going to wipe
    Serial.println(F("Wipe Button Pressed"));
    Serial.println(F("You have 15 seconds to Cancel"));
    Serial.println(F("This will be remove all records and cannot be undone"));
    delay(15000);                        // Give user enough time to cancel operation
    if (digitalRead(wipeB) == LOW) {    // If button still be pressed, wipe EEPROM
      Serial.println(F("Starting Wiping EEPROM"));
      for (int x = 0; x < EEPROM.length(); x = x + 1) {    //Loop end of EEPROM address
        if (EEPROM.read(x) == 0) {              //If EEPROM address 0
          // do nothing, already clear, go to the next address in order to save time and reduce writes to EEPROM
        }
        else {
          EEPROM.write(x, 0); 			// if not write 0 to clear, it takes 3.3mS
        }
      }
      Serial.println(F("EEPROM Successfully Wiped"));
      analogWrite(redLed, LED_OFF); 	// visualize successful wipe
      delay(200);
      analogWrite(redLed, LED_ON);
      delay(200);
      analogWrite(redLed, LED_OFF);
      delay(200);
      analogWrite(redLed, LED_ON);
      delay(200);
      analogWrite(redLed, LED_OFF);
    }
    else {
      Serial.println(F("Wiping Cancelled"));
      analogWrite(redLed, LED_OFF);
    }
  }
  // Check if master card defined, if not let user choose a master card
  // This also useful to just redefine Master Card
  // You can keep other EEPROM records just write other than 143 to EEPROM address 1
  // EEPROM address 1 should hold magical number which is '143'
  if (EEPROM.read(1) != 143) {
    Serial.println(F("No Master Card Defined"));
    Serial.println(F("Scan A PICC to Define as Master Card"));
    do {
      successRead = getID();            // sets successRead to 1 when we get read from reader otherwise 0
      analogWrite(blueLed, LED_ON);    // Visualize Master Card need to be defined
      delay(200);
      analogWrite(blueLed, LED_OFF);
      delay(200);
    }
    while (!successRead);                  // Program will not go further while you not get a successful read
    for ( int j = 0; j < 4; j++ ) {        // Loop 4 times
      EEPROM.write( 2 + j, readCard[j] );  // Write scanned PICC's UID to EEPROM, start from address 3
    }
    EEPROM.write(1, 143);                  // Write to EEPROM we defined Master Card.
    Serial.println(F("Master Card Defined"));
  }
  Serial.println(F("-------------------"));
  Serial.println(F("Master Card's UID"));
  for ( int i = 0; i < 4; i++ ) {          // Read Master Card's UID from EEPROM
    masterCard[i] = EEPROM.read(2 + i);    // Write it to masterCard
    Serial.print(masterCard[i], HEX);
  }
  Serial.println("");
  Serial.println(F("-------------------"));
  Serial.println(F("Everything Ready"));
  Serial.println(F("Waiting PICCs to be scanned"));
  cycleLeds();    // Everything ready lets give user some feedback by cycling leds
  
    }


///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () {
  
  do {
  if (analogRead(button) <= 100 ) granted(2000);         // Open the door lock for 300 ms
  
opened:

    char key = keypad.getKey();
    if (key) {

      if (key == '*') {
        i = 0 ;
        goto opened;
      }

      if (key == '#' ) {
        if ((hhh[0] == '1') && ( hhh[1] == '9' ) && (hhh[2] == '8' ) && (hhh[3] == '4' ))
        {
          hhh[0] = '0' ;
          granted(2000);         // Open the door lock for 300 ms
        
        }
        else {
          denied();

        }
        i = 0 ;
        goto opened;
      }
      if ( i > 3)    i = 0 ;
      hhh[i] = key ;
      i ++ ;
      Serial.println(hhh);
    }

    successRead = getID(); 	// sets successRead to 1 when we get read from reader otherwise 0
    if (digitalRead(wipeB) == LOW) {
      analogWrite(redLed, LED_ON);  // Make sure led is off
      analogWrite(greenLed, LED_OFF);  // Make sure led is off
      analogWrite(blueLed, LED_OFF); // Make sure led is off
      Serial.println(F("Wipe Button Pressed"));
      Serial.println(F("Master Card will be Erased! in 10 seconds"));
      delay(10000);
      if (digitalRead(wipeB) == LOW) {
        EEPROM.write(1, 0);                  // Reset Magic Number.
        Serial.println(F("Restart device to re-program Master Card"));
        while (1);
      }
    }
    if (programMode) {
      cycleLeds();              // Program Mode cycles through RGB waiting to read a new card
    }
    else {
      normalModeOn(); 		// Normal mode, blue Power LED is on, all others are off
    }
  }
  while (!successRead); 	//the program will not go further while you not get a successful read
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer , LOW );
  if (programMode) {
    if ( isMaster(readCard) ) { //If master card scanned again exit program mode
      Serial.println(F("Master Card Scanned"));
      Serial.println(F("Exiting Program Mode"));
      Serial.println(F("-----------------------------"));
      programMode = false;
      return;
    }
    else {
      if ( findID(readCard) ) { // If scanned card is known delete it
        Serial.println(F("I know this PICC, removing..."));
        deleteID(readCard);
        Serial.println("-----------------------------");
        Serial.println(F("Scan a PICC to ADD or REMOVE to EEPROM"));
      }
      else {                    // If scanned card is not known add it
        Serial.println(F("I do not know this PICC, adding..."));
        writeID(readCard);
        Serial.println(F("-----------------------------"));
        Serial.println(F("Scan a PICC to ADD or REMOVE to EEPROM"));
      }
    }
  }
  else {
    if ( isMaster(readCard)) {  	// If scanned card's ID matches Master Card's ID enter program mode
      programMode = true;
      Serial.println(F("Hello Master - Entered Program Mode"));
      int count = EEPROM.read(0); 	// Read the first Byte of EEPROM that
      Serial.print(F("I have "));    	// stores the number of ID's in EEPROM
      Serial.print(count);
      Serial.print(F(" record(s) on EEPROM"));
      Serial.println("");
      Serial.println(F("Scan a PICC to ADD or REMOVE to EEPROM"));
      Serial.println(F("Scan Master Card again to Exit Program Mode"));
      Serial.println(F("-----------------------------"));
    }
    else {
      if ( findID(readCard) ) {	// If not, see if the card is in the EEPROM
        Serial.println(F("Welcome, You shall pass"));
        granted(2000);        	// Open the door lock for 300 ms
      }
      else {			// If not, show that the ID was not valid
        Serial.println(F("You shall not pass"));
        denied();
      }
    }
  }
}

/////////////////////////////////////////  Access Granted    ///////////////////////////////////
void granted (int setDelay) {
  Serial.println("Access Granted");
  analogWrite(blueLed, LED_OFF); 	// Turn off blue LED
  analogWrite(redLed, LED_OFF); 	// Turn off red LED
  analogWrite(greenLed, LED_ON); 	// Turn on green LED
  digitalWrite(relay, HIGH); 		// Unlock door!
  delay(setDelay); 					// Hold door lock open for given seconds
  digitalWrite(relay, LOW); 		// Relock door
  delay(1000); 						// Hold green LED on for a second
}

///////////////////////////////////////// Access Denied  ///////////////////////////////////
void denied() {
  Serial.println("Access Denied");
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  analogWrite(redLed, LED_ON); 	// Turn on red LED
  digitalWrite(buzzer , HIGH);
  delay(1000);
  digitalWrite(buzzer , LOW);

}


///////////////////////////////////////// Get PICC's UID ///////////////////////////////////
int getID() {
  // Getting ready for Reading PICCs
  if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
    return 0;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {   //Since a PICC placed get Serial and continue
    return 0;
  }
  // There are Mifare PICCs which have 4 byte or 7 byte UID care if you use 7 byte PICC
  // I think we should assume every PICC as they have 4 byte UID
  // Until we support 7 byte PICCs
  Serial.println(F("Scanned PICC's UID:"));
  for (int i = 0; i < 4; i++) {  //
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
  }
  Serial.println("");
  mfrc522.PICC_HaltA(); // Stop reading
  return 1;
}

void ShowReaderDetails() {
  // Get the MFRC522 software version
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown),probably a chinese clone?"));
  Serial.println("");
  // When 0x00 or 0xFF is returned, communication probably failed
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
    Serial.println(F("SYSTEM HALTED: Check connections."));
    while (true); // do not go further
  }
}

///////////////////////////////////////// Cycle Leds (Program Mode) ///////////////////////////////////
void cycleLeds() {
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  analogWrite(greenLed, LED_ON); 	// Make sure green LED is on
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  delay(200);
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  analogWrite(blueLed, LED_ON); 	// Make sure blue LED is on
  delay(200);
  analogWrite(redLed, LED_ON); 	// Make sure red LED is on
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  delay(200);
}

//////////////////////////////////////// Normal Mode Led  ///////////////////////////////////
void normalModeOn () {
  analogWrite(blueLed, LED_ON); 	// Blue LED ON and ready to read card
  analogWrite(redLed, LED_OFF); 	// Make sure Red LED is off
  analogWrite(greenLed, LED_OFF); 	// Make sure Green LED is off
  digitalWrite(relay, LOW); 		// Make sure Door is Locked
}

//////////////////////////////////////// Read an ID from EEPROM //////////////////////////////
void readID( int number ) {
  int start = (number * 4 ) + 2; 		// Figure out starting position
  for ( int i = 0; i < 4; i++ ) { 		// Loop 4 times to get the 4 Bytes
    storedCard[i] = EEPROM.read(start + i); 	// Assign values read from EEPROM to array
  }
}

///////////////////////////////////////// Add ID to EEPROM   ///////////////////////////////////
void writeID( byte a[] ) {
  if ( !findID( a ) ) { 		// Before we write to the EEPROM, check to see if we have seen this card before!
    int num = EEPROM.read(0); 		// Get the numer of used spaces, position 0 stores the number of ID cards
    int start = ( num * 4 ) + 6; 	// Figure out where the next slot starts
    num++; 								// Increment the counter by one
    EEPROM.write( 0, num ); 		// Write the new count to the counter
    for ( int j = 0; j < 4; j++ ) { 	// Loop 4 times
      EEPROM.write( start + j, a[j] ); 	// Write the array values to EEPROM in the right position
    }
    successWrite();
    Serial.println(F("Succesfully added ID record to EEPROM"));
  }
  else {
    failedWrite();
    Serial.println(F("Failed! There is something wrong with ID or bad EEPROM"));
  }
}

///////////////////////////////////////// Remove ID from EEPROM   ///////////////////////////////////
void deleteID( byte a[] ) {
  if ( !findID( a ) ) { 		// Before we delete from the EEPROM, check to see if we have this card!
    failedWrite(); 			// If not
    Serial.println(F("Failed! There is something wrong with ID or bad EEPROM"));
  }
  else {
    int num = EEPROM.read(0); 	// Get the numer of used spaces, position 0 stores the number of ID cards
    int slot; 			// Figure out the slot number of the card
    int start;			// = ( num * 4 ) + 6; // Figure out where the next slot starts
    int looping; 		// The number of times the loop repeats
    int j;
    int count = EEPROM.read(0); // Read the first Byte of EEPROM that stores number of cards
    slot = findIDSLOT( a ); 	// Figure out the slot number of the card to delete
    start = (slot * 4) + 2;
    looping = ((num - slot) * 4);
    num--; 			// Decrement the counter by one
    EEPROM.write( 0, num ); 	// Write the new count to the counter
    for ( j = 0; j < looping; j++ ) { 				// Loop the card shift times
      EEPROM.write( start + j, EEPROM.read(start + 4 + j)); 	// Shift the array values to 4 places earlier in the EEPROM
    }
    for ( int k = 0; k < 4; k++ ) { 				// Shifting loop
      EEPROM.write( start + j + k, 0);
    }
    successDelete();
    Serial.println(F("Succesfully removed ID record from EEPROM"));
  }
}

///////////////////////////////////////// Check Bytes   ///////////////////////////////////
boolean checkTwo ( byte a[], byte b[] ) {
  if ( a[0] != NULL ) 			// Make sure there is something in the array first
    match = true; 			// Assume they match at first
  for ( int k = 0; k < 4; k++ ) { 	// Loop 4 times
    if ( a[k] != b[k] ) 		// IF a != b then set match = false, one fails, all fail
      match = false;
  }
  if ( match ) { 			// Check to see if if match is still true
    return true; 			// Return true
  }
  else  {
    return false; 			// Return false
  }
}

///////////////////////////////////////// Find Slot   ///////////////////////////////////
int findIDSLOT( byte find[] ) {
  int count = EEPROM.read(0); 			// Read the first Byte of EEPROM that
  for ( int i = 1; i <= count; i++ ) { 		// Loop once for each EEPROM entry
    readID(i); 								// Read an ID from EEPROM, it is stored in storedCard[4]
    if ( checkTwo( find, storedCard ) ) { 	// Check to see if the storedCard read from EEPROM
      // is the same as the find[] ID card passed
      return i; 				// The slot number of the card
      break; 					// Stop looking we found it
    }
  }
}

///////////////////////////////////////// Find ID From EEPROM   ///////////////////////////////////
boolean findID( byte find[] ) {
  int count = EEPROM.read(0);			// Read the first Byte of EEPROM that
  for ( int i = 1; i <= count; i++ ) {  	// Loop once for each EEPROM entry
    readID(i); 					// Read an ID from EEPROM, it is stored in storedCard[4]
    if ( checkTwo( find, storedCard ) ) {  	// Check to see if the storedCard read from EEPROM
      return true;
      break; 	// Stop looking we found it
    }
    else {  	// If not, return false
    }
  }
  return false;
}

///////////////////////////////////////// Write Success to EEPROM   ///////////////////////////////////
// Flashes the green LED 3 times to indicate a successful write to EEPROM
void successWrite() {
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is on
  delay(200);
  analogWrite(greenLed, LED_ON); 	// Make sure green LED is on
  delay(200);
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  delay(200);
  analogWrite(greenLed, LED_ON); 	// Make sure green LED is on
  delay(200);
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  delay(200);
  analogWrite(greenLed, LED_ON); 	// Make sure green LED is on
  delay(200);
}

///////////////////////////////////////// Write Failed to EEPROM   ///////////////////////////////////
// Flashes the red LED 3 times to indicate a failed write to EEPROM
void failedWrite() {
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  delay(200);
  analogWrite(redLed, LED_ON); 	// Make sure red LED is on
  delay(200);
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  delay(200);
  analogWrite(redLed, LED_ON); 	// Make sure red LED is on
  delay(200);
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  delay(200);
  analogWrite(redLed, LED_ON); 	// Make sure red LED is on
  delay(200);
}

///////////////////////////////////////// Success Remove UID From EEPROM  ///////////////////////////////////
// Flashes the blue LED 3 times to indicate a success delete to EEPROM
void successDelete() {
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  analogWrite(redLed, LED_OFF); 	// Make sure red LED is off
  analogWrite(greenLed, LED_OFF); 	// Make sure green LED is off
  delay(200);
  analogWrite(blueLed, LED_ON); 	// Make sure blue LED is on
  delay(200);
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  delay(200);
  analogWrite(blueLed, LED_ON); 	// Make sure blue LED is on
  delay(200);
  analogWrite(blueLed, LED_OFF); 	// Make sure blue LED is off
  delay(200);
  analogWrite(blueLed, LED_ON); 	// Make sure blue LED is on
  delay(200);
}

////////////////////// Check readCard IF is masterCard   ///////////////////////////////////
// Check to see if the ID passed is the master programing card
boolean isMaster( byte test[] ) {
  if ( checkTwo( test, masterCard ) )
    return true;
  else
    return false;
}

