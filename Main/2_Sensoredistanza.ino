void Distanza(){
  if(c==0){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("* Esci");
  }
  c=c+1;
  if(digitalRead(A3)==HIGH){
    enter=1-enter;
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Uscita...");
    lcd.noBlink();
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("         ");
    ca=0;
    cb=0;
  }
  unsigned int uS = sonar.ping();
  distanza = uS / US_ROUNDTRIP_CM;
  lcd.setCursor(0, 0);
  lcd.print("distanza:");
  lcd.setCursor(9,0);
  lcd.print(distanza);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.blink();
  delay(200);
  lcd.setCursor(9,0);
  lcd.print("      ");
}
