int val;
int pot;
int led[6]={3,5,6,9,10,11};
void setup() {
}

void loop() {
  pot=analogRead(A0);
  val=map(pot, 0, 1023, 0, 255);
  analogWrite(led[3], val);
  analogWrite(led[4], val);
  delay(500);
  pot=analogRead(A0);
  val=map(pot, 0, 1023, 0, 255);
  analogWrite(led[2], val);
  analogWrite(led[5], val);
  delay(500);
  pot=analogRead(A0);
  val=map(pot, 0, 1023, 0, 255);
  analogWrite(led[1], val);
  analogWrite(led[6], val);
  delay(500);
  for(int i=6; i>0;i--){
    digitalWrite(led[i], LOW);
    delay(500);
  }
}
