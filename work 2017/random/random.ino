int no[9] = {1,2,3,4,1,2,3,4};
int c = 0 ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
int g =(int)random(1-5);
if ((no[g] < 9 )&&( no[g] > 0 )){
Serial.println(no[g]);
no[g] = 100 ;
}

}
