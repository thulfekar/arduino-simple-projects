void floorcolor(){
  // put your main code here, to run repeatedly:

 digitalWrite(aS2, LOW);
  digitalWrite(aS3, LOW);
  // Reading the output frequency
  red = pulseIn(asensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red);//printing RED color frequency
  Serial.print("  ");
  delay(1);
  // Setting Green filtered photodiodes to be read
  digitalWrite(aS2, HIGH);
  digitalWrite(aS3, HIGH);
  // Reading the output frequency
  green = pulseIn(asensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green);//printing RED color frequency
  Serial.print("  ");
  delay(1);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(aS2, LOW);
  digitalWrite(aS3, HIGH);
  // Reading the output frequency
  blue = pulseIn(asensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(blue);//printing RED color frequency
  Serial.println("  ");
  delay(1);
}
