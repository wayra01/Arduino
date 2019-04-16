

void setup() {
  Serial.begin(9600);
  for(int pinNumber =2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(A0);
  Serial.println("Sensor Vlaue");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.println("Volts");
  Serial.print(voltage);
  Serial.println("Degrees C:");
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);
  
if(temperature < 20){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);

}
else if(temperature >= 20+4 && temperature < 20+4){
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);

}
else if(temperature >= 20+6 && temperature < 20+8){
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);

}
else if(temperature >= 20+12){
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);

}
delay(1);
}
