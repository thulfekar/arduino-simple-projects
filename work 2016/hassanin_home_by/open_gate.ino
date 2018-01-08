void opengate() {
   digitalWrite(22, LOW);
    digitalWrite(27, LOW);
    delay(1000);
    digitalWrite(22, HIGH);

    delay(9000);
    digitalWrite(27, HIGH);
}

