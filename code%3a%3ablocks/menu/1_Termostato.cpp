void Termostato(){
  if(c==0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.setCursor(5, 0);
    lcd.print("U=");
    lcd.setCursor(0, 1);
    lcd.print("* Esci");
  }
  c=c+1;
  delay(10);
  if(digitalRead(A3)==HIGH){
    enter=1-enter;
    delay(1000);
    ca=0;
    cb=0;
  }
  int t=dht.readTemperature();
  int h=dht.readHumidity();
  lcd.setCursor(2, 0);
  lcd.print(t);
  lcd.setCursor(7, 0);
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.blink();
}
