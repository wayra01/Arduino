int val;
int pot;
int led[7]={3,5,6,9,10,11};
void setup() {
  for(int i=0; i<7;i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  pot=analogRead(A0);
  val=map(pot, 0, 1023, 0, 255);
  analogWrite(led[2], val);
  analogWrite(led[3], val);
  delay(500);
  pot=analogRead(A0);
  val=map(pot, 0, 1023, 0, 255);
  analogWrite(led[1], val);
  analogWrite(led[4], val);
  delay(500);
  pot=analogRead(A0);
  val=map(pot, 0, 1023, 0, 255);
  analogWrite(led[0], val);
  analogWrite(led[5], val);
  delay(500);
  for(int i=255; i>0; i--){
    analogWrite(led[0], i);
    analogWrite(led[5], i);
    delay(5);
  }
  for(int i=255; i>0; i--){
    analogWrite(led[1], i);
    analogWrite(led[4], i);
    delay(5);
  }
  for(int i=255; i>0; i--){
    analogWrite(led[2], i);
    analogWrite(led[3], i);
    delay(5);
  }
  
}