int pausa=100;
int pot1=1024;
int pot=255;

void setup(){
  for(int i=4; i<13; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  for(int i=4; i<13; i++){
    pot1=analogRead(A1);
    pot=map(pot, 1023, 0, 255, 0);
    analogWrite(i, pot);
    delay(pausa);
  }
  for(int i=12; i>3; i--){
    digitalWrite(i, LOW);
    delay(pausa);
  }
}
