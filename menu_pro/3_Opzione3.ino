void Opzione3(){
  lcd.clear();
  if(digitalRead(A3)==HIGH){
    pulsante1=1-pulsante1;
    delay(1000);
    ca=0;
    cb=0;
  }
  lcd.setCursor(0,0);
  lcd.print("Error->no comand");
  lcd.setCursor(0, 1);
  lcd.print("* Esci");
  lcd.setCursor(0,1);
  lcd.blink();
  delay(10);
}
