/*
 * MENU ARDUINO - v 0.1-2 Alpha
 * 
 * CHANGELOG:
 * * 0.1-1 ** Alpha ** 01:55  03/01/2019 ** First Release
 * / Diario del programmatore, data astrale 3119.1, ho sviluppato la prima 
 *  versione utilizzabile(ma non troppo) del programma e dispositivo, ho riscontrato un bug
 *  nell'unica opzione di Termostato, vista la stanchezza e la frequente abitudine delle
 *  mie palpebre nell'abbassarsi temo che non potrò risolvere i problemi nell'immediato arco di
 *  tempo e sono obbligato ad andare a dormire e posporre il compito a un'altro periodo utile. Di
 *  seguito elenco il primo changelog relativo a questa versione. \
 *  
 *  - Menù con animazioni
 *  - Bootanimation v 1
 *  - Termostato
 *  - Controllo tramite pulsanti
 * 
 * / Diario del programmatore, complemento, ieri sera mi sono dimenticato di aggiungere i bug, vista
 * la stanchezza non me ne sorprendo, li elenco qui di seguito. \
 * 
 * [BUG] il termostato non si chiude, se si tenta di uscire il cursore va al punto (0,0) dell' LCD
 * 
 * ******************************************************************************************************
 * 
 * * 0.1-2 ** Alpha ** 12:48 03/01/2019 ** Bugfix
 * / Diario del programmatore, data astrale 3119.12, ho effettuato delle correzione del codice e lo
 *  ho ottimizzato, sto per aggiungere le impostazioni del dispositivo che permetteranno di controllare
 *  le animazioni, di seguito elenco le novità di questa versione. \
 *  
 *  - Risolto il problema del termostato
 *  - Ottimizzazione del codice
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
  bootanimation();
}

void loop(){
  if(cursore==0 || cursore==1){
    if(ca==0){
      lcd.noBlink();
      lcd.clear();
      lcd.print("*");
      lcd.setCursor(0,1);
      lcd.print("*");
      delay(100);
      lcd.setCursor(1,0);
      lcd.print(" ");
      lcd.setCursor(1,1);
      lcd.print(" ");
      delay(100);
      lcd.setCursor(2,0);
      lcd.print("T");
      lcd.setCursor(2,1);
      lcd.print("O");
      delay(100);
      lcd.setCursor(3,0);
      lcd.print("e");
      lcd.setCursor(3,1);
      lcd.print("p");
      delay(100);
      lcd.setCursor(4,0);
      lcd.print("r");
      lcd.setCursor(4,1);
      lcd.print("z");
      delay(100);
      lcd.setCursor(5,0);
      lcd.print("m");
      lcd.setCursor(5,1);
      lcd.print("i");
      delay(100);
      lcd.setCursor(6,0);
      lcd.print("o");
      lcd.setCursor(6,1);
      lcd.print("o");
      delay(100);
      lcd.setCursor(7,0);
      lcd.print("s");
      lcd.setCursor(7,1);
      lcd.print("n");
      delay(100);
      lcd.setCursor(8,0);
      lcd.print("t");
      lcd.setCursor(8,1);
      lcd.print("e");
      delay(100);
      lcd.setCursor(9,0);
      lcd.print("a");
      lcd.setCursor(9,1);
      lcd.print("2");
      delay(100);
      lcd.setCursor(10,0);
      lcd.print("t");
      delay(100);
      lcd.setCursor(11,0);
      lcd.print("o");
      delay(200);
      lcd.setCursor(14, 0);
      lcd.print("P1");
    }
    ca=ca+1;
    lcd.setCursor(0, cm);
    lcd.blink();
    cb=0;
  }
  if(cursore==2 || cursore==3){
    if(cb==0){
      lcd.noBlink();
      lcd.clear();
      lcd.print("*");
      lcd.setCursor(0,1);
      lcd.print("*");
      delay(100);
      lcd.setCursor(1,0);
      lcd.print(" ");
      lcd.setCursor(1,1);
      lcd.print(" ");
      delay(100);
      lcd.setCursor(2,0);
      lcd.print("O");
      lcd.setCursor(2,1);
      lcd.print("O");
      delay(100);
      lcd.setCursor(3,0);
      lcd.print("p");
      lcd.setCursor(3,1);
      lcd.print("p");
      delay(100);
      lcd.setCursor(4,0);
      lcd.print("z");
      lcd.setCursor(4,1);
      lcd.print("z");
      delay(100);
      lcd.setCursor(5,0);
      lcd.print("i");
      lcd.setCursor(5,1);
      lcd.print("i");
      delay(100);
      lcd.setCursor(6,0);
      lcd.print("o");
      lcd.setCursor(6,1);
      lcd.print("o");
      delay(100);
      lcd.setCursor(7,0);
      lcd.print("n");
      lcd.setCursor(7,1);
      lcd.print("n");
      delay(100);
      lcd.setCursor(8,0);
      lcd.print("e");
      lcd.setCursor(8,1);
      lcd.print("e");
      delay(100);
      lcd.setCursor(9,0);
      lcd.print("3");
      lcd.setCursor(9,1);
      lcd.print("4");
      delay(200);
      lcd.setCursor(14, 0);
      lcd.print("P2");
    }
    cb=cb+1;
    lcd.setCursor(0, cm);
    lcd.blink();
    ca=0;
  }
  if(digitalRead(A2)==HIGH){
    pulsante=1-pulsante;
    cm=1-cm;
    cursore=cursore+1;
    delay(500);
  }
  if(digitalRead(A3)==HIGH){
    pulsante1=1-pulsante1;
    delay(500);
  }
  while(pulsante1==1 && cursore==0){
    Termostato();
  }
  while(pulsante1==1 && cursore==1){
    Opzione2();
  }
  while(pulsante1==1 && cursore==2){
    Opzione3();
  }
  while(pulsante1==1 && cursore==3){
    Opzione4();
  }
  if(cursore>3){
    cursore=0;
    lcd.setCursor(0,0);
    lcd.blink();
  }
  c=0;
  delay(10);
}
