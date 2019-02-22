int pot=0;
int Temp=0;
int T=0;
int V=0;
int Tt=0;
void setup(){
  Serial.begin(9600);
}
  void loop(){
    for (int i=1; i<10; i++){
      pot = analogRead(A0);
      V = map (pot, 0, 1023, 0, 5000);
      Temp = map (V, 0, 5000, 0, 500);
      Tt = Temp+Tt;
      delay(2000);
    }
  Tt=0;
}
