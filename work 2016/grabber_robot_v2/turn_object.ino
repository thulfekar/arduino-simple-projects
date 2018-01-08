void turnobject()
{
  Serial.println("turnobject");
  if (i < 70 ) {

    right();
    delay(75);
    stopit();
  }
  else if (i > 82 ) {
    left();
    delay(75);
    stopit();
  }
  else gotoobject();
  Serial.println("locked");
  stopit();
}

