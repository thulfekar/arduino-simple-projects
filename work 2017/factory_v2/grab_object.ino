void grabobject()
{
  delay(1000);
  graber.write(graberopen);
  delay(1000);
  pan.write(panleft);
  delay(1000);
  tilt.write(tiltdown);
  delay(1000);
graber.write(graberclosed);
delay(1000);
reader.write(readerdown);
delay(1000);
grabercolor();
delay(500);
reader.write(readerup);
  delay(1000);
  tilt.write(tiltup);
    delay(1000);
  pan.write(center);
if ((red > 100 ) && (green > 100) && ( blue > 100 ) )
{
   delay(1000);
  graber.write(graberopen);
  delay(1000);
  pan.write(center);
  delay(1000);
  tilt.write(tiltup);
  delay(1000);
  Reverse();
  delay(500);
  Stop();
}
else if ((red < green ) && (red < blue) ){
 chr = 'r' ;

 Forward();
 delay(200);
 Stop();
}

else if ((green < red ) && (green < blue) ){
chr =  'g' ;
 Forward();
 delay(200);
 Stop();
}
else if ( (blue < red ) && (blue < green)){
chr =  'b' ;
 Forward();
 delay(200);
 Stop();
}
}

void putdown(){
  delay(1000);
  pan.write(panleft);
  delay(1000);
  tilt.write(tiltdown);
  delay(1000);
graber.write(graberopen);
delay(1000);
tilt.write(tiltup);
  delay(1000);
   pan.write(center);
  delay(1000);
  chr =  'x' ;

}

