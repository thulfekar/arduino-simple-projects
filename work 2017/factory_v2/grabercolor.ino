void grabercolor() {
  digitalWrite(bS2, LOW);
  digitalWrite(bS3, LOW);
  // Reading the output frequency
  red = pulseIn(bsensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red);//printing RED color frequency
  Serial.print("  ");
  delay(30);
  // Setting Green filtered photodiodes to be read
  digitalWrite(bS2, HIGH);
  digitalWrite(bS3, HIGH);
  // Reading the output frequency
  green = pulseIn(bsensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green);//printing RED color frequency
  Serial.print("  ");
  delay(30);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(bS2, LOW);
  digitalWrite(bS3, HIGH);
  // Reading the output frequency
  blue = pulseIn(bsensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(blue);//printing RED color frequency
  Serial.println("  ");
  delay(30);

}

