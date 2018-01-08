void forward() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}

void back() {
  digitalWrite(R2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L1, HIGH);

}

void left() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
}

void right() {
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}

void stopit() {
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
}

