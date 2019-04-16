const int pot=A0;
const float baselineTemp=20.0;

void setup() {
  Serial.begin(9600);
  for(int led =2; led<4; led++){
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
  }
}

void loop() {
  int Val = analogRead(pot);
  Serial.println("Sensor Vlaue");
  Serial.print(Val);
  float voltage = (Val/1024.0) * 5.0;
  Serial.println("Volts");
  Serial.println(voltage);
  Serial.println("Degrees C:");
  float temperature = (voltage) * 100;
  Serial.println(temperature);
  
if(temperature < baselineTemp){
digitalWrite(2, HIGH);
digitalWrite(3, LOW);

}
else if(temperature >= baselineTemp){
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
}
delay(500);
}
