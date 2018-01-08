void opendoor(){



   Serial.println("open");
      digitalWrite(22, LOW);
      digitalWrite(27, LOW);
      delay(1000);

      digitalWrite(22, HIGH);
      digitalWrite(29, LOW);
      delay(2000);
      delay(9000);
      digitalWrite(29, HIGH);

      digitalWrite(25, LOW);
      delay(00);
      digitalWrite(25, HIGH);



      digitalWrite(22, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(29, HIGH);
}

