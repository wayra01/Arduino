void Opzione3(){
  if(c==0){
    lcd.clear();
  }
  c=c+1;
  if(digitalRead(A3)==HIGH){
    enter=1-enter;
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
