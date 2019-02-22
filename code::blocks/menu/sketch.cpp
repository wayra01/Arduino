#include <Arduino.h>

/*
 * MENU ARDUINO - v 0.1-2 Alpha
 *
 * CHANGELOG:
 * * 0.1-1 ** Alpha ** 01:55  03/01/2019 ** First Release
 * / Diario del programmatore, data astrale 3119.1, ho sviluppato la prima
 *  versione utilizzabile(ma non troppo) del programma e dispositivo, ho riscontrato un bug
 *  nell'unica opzione di Termostato. Di seguito elenco il primo changelog relativo a questa versione. \
 *
 *  - Menu con animazioni
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
 *  le animazioni, di seguito elenco le novita di questa versione. \
 *
 *  - Risolto il problema del termostato
 *  - Ottimizzazione del codice
 *
 *  *****************************************************************************************************
 *
 * * 0.2-1 ** Alpha ** 21:15 02/01/2019 ** Update
 * / Diario del programmatore, data astrale 3119.21, ho sviluppato una seconda versione Alpha del
 *  dispositivo in cui ho aggiunto la sezione impostazioni in cui e' possibile modificare la velocita' delle
 *  animazioni(temporaneamente solo in versione avanzata). \
 *
 *  - Aggiunta la sezione "Impostazioni"
 *  - Controllo delle animazioni da parte dell'utilizzatore
 *
 *  ****************************************************************************************************
 *  / Diario del programmatore, data astrale 30119.19, dopo un cambio di distribuzione Linux ho rilevato
 *   problemi con le porte seriali, i cui permessi non erano concessi ad Arduino, dopo svariato tempo di
 *   ricerche e tentativi sono riuscito a risolvere il problema. \
*/

#include <NewPing.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const char rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int distanza=0;
char cursore=0;
bool down=0;
bool enter=0;
bool up=0;
bool cm=0;
signed int c;
signed int ca;
signed int cb;
signed int cc;
int pausa=100;

void setup(){
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  lcd.begin(16,2);
  bootanimation();  //primo avvio
}

void loop(){
  if(cursore==0 || cursore==1){  //Pagina 1
    if(ca==0){
      lcd.noBlink();
      lcd.clear();
      lcd.print("*");
      lcd.setCursor(0,1);
      lcd.print("*");
      delay(pausa);
      lcd.setCursor(1,0);
      lcd.print(" ");
      lcd.setCursor(1,1);
      lcd.print(" ");
      delay(pausa);
      lcd.setCursor(2,0);
      lcd.print("T");
      lcd.setCursor(2,1);
      lcd.print("D");
      delay(pausa);
      lcd.setCursor(3,0);
      lcd.print("e");
      lcd.setCursor(3,1);
      lcd.print("i");
      delay(pausa);
      lcd.setCursor(4,0);
      lcd.print("r");
      lcd.setCursor(4,1);
      lcd.print("s");
      delay(pausa);
      lcd.setCursor(5,0);
      lcd.print("m");
      lcd.setCursor(5,1);
      lcd.print("t");
      delay(pausa);
      lcd.setCursor(6,0);
      lcd.print("o");
      lcd.setCursor(6,1);
      lcd.print("a");
      delay(pausa);
      lcd.setCursor(7,0);
      lcd.print("s");
      lcd.setCursor(7,1);
      lcd.print("n");
      delay(pausa);
      lcd.setCursor(8,0);
      lcd.print("t");
      lcd.setCursor(8,1);
      lcd.print("z");
      delay(pausa);
      lcd.setCursor(9,0);
      lcd.print("a");
      lcd.setCursor(9,1);
      lcd.print("a");
      delay(pausa);
      lcd.setCursor(10,0);
      lcd.print("t");
      delay(pausa);
      lcd.setCursor(11,0);
      lcd.print("o");
      delay(pausa);
      lcd.setCursor(14, 0);
      lcd.print("P1");
    }
    ca=ca+1;
    lcd.setCursor(0, cm);
    lcd.blink();
    cb=0;
  }
  if(cursore==2 || cursore==3){  //Pagina 2
    if(cb==0){
      lcd.noBlink();
      lcd.clear();
      lcd.print("*");
      lcd.setCursor(0,1);
      lcd.print("*");
      delay(pausa);
      lcd.setCursor(1,0);
      lcd.print(" ");
      lcd.setCursor(1,1);
      lcd.print(" ");
      delay(pausa);
      lcd.setCursor(2,0);
      lcd.print("O");
      lcd.setCursor(2,1);
      lcd.print("I");
      delay(pausa);
      lcd.setCursor(3,0);
      lcd.print("p");
      lcd.setCursor(3,1);
      lcd.print("m");
      delay(pausa);
      lcd.setCursor(4,0);
      lcd.print("z");
      lcd.setCursor(4,1);
      lcd.print("p");
      delay(pausa);
      lcd.setCursor(5,0);
      lcd.print("i");
      lcd.setCursor(5,1);
      lcd.print("o");
      delay(pausa);
      lcd.setCursor(6,0);
      lcd.print("o");
      lcd.setCursor(6,1);
      lcd.print("s");
      delay(pausa);
      lcd.setCursor(7,0);
      lcd.print("n");
      lcd.setCursor(7,1);
      lcd.print("t");
      delay(pausa);
      lcd.setCursor(8,0);
      lcd.print("e");
      lcd.setCursor(8,1);
      lcd.print("a");
      delay(pausa);
      lcd.setCursor(9,0);
      lcd.print("3");
      lcd.setCursor(9,1);
      lcd.print("z");
      delay(pausa);
      lcd.setCursor(10,1);
      lcd.print("i");
      delay(pausa);
      lcd.setCursor(11,1);
      lcd.print("o");
      delay(pausa);
      lcd.setCursor(12,1);
      lcd.print("n");
      delay(pausa);
      lcd.setCursor(13,1);
      lcd.print("i");
      delay(pausa);
      lcd.setCursor(14, 0);
      lcd.print("P2");
    }
    cb=cb+1;
    lcd.setCursor(0, cm);
    lcd.blink();
    ca=0;
  }
  if(digitalRead(A2)==HIGH){  //Pulsante sinistra
    down=1-down;
    cm=1-cm;
    cursore=cursore+1;
    delay(500);
  }
  if(digitalRead(A3)==HIGH){  //Pulsante ENTER
    enter=1-enter;
    delay(500);
  }
  if(digitalRead(A4)==HIGH){  //Pulsante destra
    up=1-up;
    cm=1-cm;
    cursore=cursore-1;
    delay(500);
  }
  while(enter==1 && cursore==0){  //Avvio programma termostato
    Termostato();
  }
  while(enter==1 && cursore==1){  //Avvio programma sensore di distanza
    Distanza();
  }
  while(enter==1 && cursore==2){  //Avvio programma opzione 3
    Opzione3();
  }
  while(enter==1 && cursore==3){  //Avvio impostazioni
    Impostazioni();
  }
  if(cursore>3){  //gestore delle pagine crescente
    cursore=0;
    lcd.setCursor(0,0);
    lcd.blink();
  }
  if(cursore<0){  //gestore delle pagine decrescente
    cursore=3;
    lcd.setCursor(0,1);
    lcd.blink();
  }
  c=0;
  delay(10);
}
