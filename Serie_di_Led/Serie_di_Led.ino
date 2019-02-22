int cacca=1;
int giorgino=2;
int alberto=3;
int femmate=1000;
int femmatetanto=1000;
void setup(){
  pinMode(cacca, OUTPUT);
  pinMode(giorgino, OUTPUT);
  pinMode(alberto, OUTPUT);
  delay(femmate);
}
void loop(){
  digitalWrite(cacca, HIGH);
  delay(femmate);
  digitalWrite(giorgino, HIGH);
  delay(femmatetanto);
  digitalWrite(alberto, HIGH);
  delay(femmate);
  digitalWrite(cacca, LOW);
  delay(femmate);
  digitalWrite(giorgino, LOW);
  delay(femmate);
  digitalWrite(alberto, LOW);
  delay(femmate);
}
