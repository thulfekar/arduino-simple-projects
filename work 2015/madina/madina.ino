
char command ;

void setup() {
  Serial1.begin(9600);
  delay(50);

  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);


  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void loop() {


  while (!Serial1.available()) {

  }

  command = Serial1.read();
  switch (command) {
    case 'F' :
      forward();
      break;

    case 'B' :
      back();
      break;

    case 'R' :
      right();
      break;

    case 'L' :
      left();
      break;

    default:
      stopit();






  }
}


void forward ()
{
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void back()
{
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
}


void right()
{

  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void left()
{

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}
void stopit()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}


