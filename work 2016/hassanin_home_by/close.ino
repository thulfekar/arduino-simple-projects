void closedoor() {
   Serial.println("close");
      digitalWrite(23, LOW);
      digitalWrite(23, HIGH);
      digitalWrite(24, LOW);
      delay(10000);
      digitalWrite(24, HIGH);
      digitalWrite(26, LOW);
      delay(3600);
      digitalWrite(26, HIGH);



      digitalWrite(28, LOW);
      delay(00);
      digitalWrite(28, HIGH);

      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(28, HIGH);

}

