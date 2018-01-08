while ( mySerial.available() > 0) mySerial.read();
  // request Basic string
  mySerial.println("AT+CGNSINF"); //sendATcommand("AT+CGNSINF", "AT+CGNSINF\r\n\r\n", 2000);

  counter = 0;
  answer = 0;
  memset(frame, '\0', sizeof(frame));    // Initialize the string
  previous = millis();
  // this loop waits for the NMEA string
  do {

    if (mySerial.available() != 0) {
      frame[counter] = mySerial.read();
      counter++;
      // check if the desired answer is in the response of the module
      if (strstr(frame, "OK") != NULL)
      {
        answer = 1;
      }
    }
    // Waits for the asnwer with time out
  }
  while ((answer == 0) && ((millis() - previous) < 2000));

  frame[counter - 3] = '\0';
