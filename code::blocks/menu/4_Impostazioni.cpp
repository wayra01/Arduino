void Impostazioni(){
  char cau=0;
  if(c==0){
    ca=0;
    cb=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("* V.anim.");
    lcd.setCursor(0, 1);
    lcd.print("* Esci");
  }
  c=c+1;
  if(digitalRead(A2)==HIGH){
    cb=1-cb;
    cc=cc+1;
    delay(500);
  }
  if(digitalRead(A4)==HIGH){
    cb=1-cb;
    cc=cc-1;
    delay(500);
  }
  if(digitalRead(A3)==HIGH){
    cau=1-cau;
    delay(500);
  }
  delay(10);
  if(cc>1){
    cc=0;
  }
  while(cau==1 && cc==0){
    if(pausa<100){
    lcd.setCursor(13,0);
    lcd.print("  ");
    }
    if(pausa>995){
      pausa=0;
    }
    lcd.setCursor(11,0);
    lcd.print(pausa);
    lcd.setCursor(10,0);
    lcd.blink();
    if(digitalRead(A3)==HIGH){
      cau=0;
      delay(500);
    }
    if(digitalRead(A2)==HIGH){
      pausa=pausa+5;
      lcd.setCursor(2,0);
      lcd.print("         ");
      delay(pausa);
      lcd.setCursor(2,0);
      lcd.print("V");
      delay(pausa);
      lcd.print(".");
      delay(pausa);
      lcd.print("a");
      delay(pausa);
      lcd.print("n");
      delay(pausa);
      lcd.print("i");
      delay(pausa);
      lcd.print("m");
      delay(pausa);
      lcd.print(".");
      delay(pausa);
    }
    if(digitalRead(A4)==HIGH){
      pausa=pausa-5;
      lcd.setCursor(2,0);
      lcd.print("         ");
      delay(pausa);
      lcd.setCursor(2,0);
      lcd.print("V");
      delay(pausa);
      lcd.print(".");
      delay(pausa);
      lcd.print("a");
      delay(pausa);
      lcd.print("n");
      delay(pausa);
      lcd.print("i");
      delay(pausa);
      lcd.print("m");
      delay(pausa);
      lcd.print(".");
      delay(pausa);
    }
  }
  lcd.setCursor(11,0);
  lcd.print("    ");
  lcd.setCursor(11,0);
  lcd.print(pausa);
  lcd.setCursor(0,cc);
  lcd.blink();
  if(digitalRead(A3)==HIGH && cc==1){
    enter=0;
    delay(500);
  }
}
