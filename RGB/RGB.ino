/*
 * MENU ARDUINO - v 0.1 Alpha
 * 
 * 
*/
#include <DHT.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal.h>
#define DHTPIN 8  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const char rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char cursore=0;
bool pulsante=0;
bool pulsante1=0;
bool cm=0;
signed int c;
signed int ca;
signed int cb;

void setup(){
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  lcd.begin(16,2);
}

void loop(){
  if(cursore==0 || cursore==1){
    if(ca==0){
      lcd.clear();
    }
    ca=ca+1;
    lcd.setCursor(14, 0);
    lcd.print("P1");
    lcd.setCursor(0,0);
    lcd.print("* Termostato");
    lcd.setCursor(0,1);
    lcd.print("* Opzione2");
    lcd.setCursor(0, cm);
    lcd.blink();
  }
  if(cursore==2 || cursore==3){
    if(cb==0){
      lcd.clear();
    }
    cb=cb+1;
    lcd.setCursor(14, 0);
    lcd.print("P2");
    lcd.setCursor(0,0);
    lcd.print("* Opzione3"); //AGGIUNGERE AZZERAMENTO CONTATORE NON APPENA AGGIUNTA LA FUNZIONE
    lcd.setCursor(0,1);
    lcd.print("* Opzione4"); // AGGIUNGERE AZZERAMENTO CONTATORE NON APPENA AGGIUNTA LA FUNZIONE
    lcd.setCursor(0, cm);
    lcd.blink();
  }
  if(digitalRead(A2)==HIGH){
    pulsante=1-pulsante;
    cm=1-cm;
    cursore=cursore+1;
    lcd.setCursor(0, cm);
    lcd.blink();
    delay(500);
  }
  if(digitalRead(A3)==HIGH){
    pulsante1=1-pulsante1;
    delay(500);
  }
  while(pulsante1==1 && cursore==0){
    if(c==0){
      lcd.clear();
    }
    c=c+1;
    delay(1000);
    if(digitalRead(A3)==HIGH){
      pulsante1=1-pulsante1;
    }
    int t=dht.readTemperature();
    int h=dht.readHumidity();
    lcd.setCursor(0, 0);
    lcd.print("T=");
    lcd.setCursor(5, 0);
    lcd.print("U=");
    lcd.setCursor(2, 0);
    lcd.print(t);
    lcd.setCursor(7, 0);
    lcd.print(h);
    lcd.setCursor(0, 1);
    lcd.print("* Menu");
    lcd.setCursor(0,1);
    lcd.blink();
  }
  if(cursore>3){
    cursore=0;
    lcd.setCursor(0,0);
    lcd.blink();
  }
  c=0;
  delay(10);
}
