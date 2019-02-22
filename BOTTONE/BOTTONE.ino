int led = 1;
int bottone = 2;
int val = 0;
 void setup(){
  pinMode(led, OUTPUT);
  pinMode(bottone, INPUT);
 }

void loop(){
  val = digitalRead(bottone);
  if(val == HIGH){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
  else{
    digitalWrite(led, LOW);
  }
  
}
