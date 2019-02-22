int led=5;
int pot=0;
int potval=0;
void setup(){
  pinMode (led, OUTPUT);
}
void loop(){
  pot = analogRead(A0);
  potval = map(pot, 0, 1023, 0, 255);
  analogWrite(led, potval);
}
