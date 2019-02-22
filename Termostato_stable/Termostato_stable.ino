/*
 * PROGETTO FITZGERALD
 * by Guaira Jaramillo Nitoglia
 * 
 * 
 * V. 3.0
 * 
 * -------------------------
 * -------------------------
 * 
 * Sensore di temperatura e umidità con led indicativi e LCD su cui vengono riportati i valori e delle frasi simpatiche.
 * 
 * -------------------------
 * -------------------------
 * 
 * Changelog:
 * ** 25/11/2018 ** 0.0.1 A **
 * -Creazione del progetto e ideazione del funzionamento
 * 
 * ** 27/11/2018 ** 1.0 **
 * -Prima versione del progetto priva di bug (le versioni beta sono state testate direttamente in fase di sviluppo)
 * -Led colorati funzionanti
 * -Sensore di temperatura e umidità funzionante
 * -LCD funzionante
 * 
 * ** 27/11/2018 ** 1.1 **
 * -Rimozione lettura dei dati sull'umidità che possono risultare superflui in questo caso
 * -Aggiunte frasi carine dipendenti dalla temperatura
 * -Aggiornamento della descrizione per una più accurata idealizzazione del progetto
 * 
 * ** 28/11/2018 ** 1.2 **
 * -È stato ripristinata la lettura dell'umidità limitando lo spazio utilizzato dalle scritte
 * -Ottimizzazione degli spazi utilizzati
 * 
 * ** 28/11/2018 ** 2.1 **
 * -Aggiunto un dialogo di benvenuto con i dati di inizio
 * -Aggiunta una frase per le temperature molto basse
 * -Aggiunto il bottone che permette di visualizzare una scritta
 * 
 * ** 30/11/2018 ** 3.0.0 Beta **
 * -Aggiornato l'interfacciamento di boot
 * -Aggiunta dell'orologio in corso(progetto in creazione su un altro file per preservare il programma)
 * 
 * ** 01/12/2018 ** 3.0.2 Alpha **
 * -Aggiunto l'orologio
 * -Miglioramento dell'interfaccia
 * -Rimozioni frasi inutili
 * [BUG] L'orologio ha un errore di qualche millisecondo/secondo
 * [BUG] I Pulsanti non funzionanti per la modifica dell'ora
 * 
 * ** 01/12/2018 ** 3.0 Major Update **
 * -Aggiunto l'orologio
 * -Aggiunti i controlli dell'orologio
 * -Migliorata l'interfaccia di avvio
 * -Migliorata l'interfaccia di visualizzazione
 * -Rimosse le scritte inutili
 * -Ottimizzazione del linguaggio e eliminazione di alcune righe di codice inutili
 */

#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 1  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int ledrosso=7;
int ledverde=8;
int ledblu=9;
int bottoneo=13;
int statobo=0;
int bottonem=10;
int statobm=0;
int s=0;
int m=0;
int o=0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(ledrosso, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledblu, OUTPUT);
  pinMode(bottoneo, INPUT);
  pinMode(bottonem, INPUT);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("   BENVENUTI!   ");
  lcd.setCursor(0, 1);
  lcd.print("----------------");
  digitalWrite(ledrosso, HIGH);
  digitalWrite(ledverde, HIGH);
  digitalWrite(ledblu, HIGH);
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("P. Fitzgerald   ");
  lcd.setCursor(0, 1);
  lcd.print("versione 3.0    ");
  
  delay(5000);
  lcd.clear();
  lcd.print("  Projected by  ");
  lcd.setCursor(0, 1);
  lcd.print("  Guaira J. N.  ");
  delay(1000);
  digitalWrite(ledrosso, LOW);
  delay(1000);
  digitalWrite(ledverde, LOW);
  delay(1000);
  digitalWrite(ledblu, LOW);
  delay(2000);
  lcd.clear();
}
void loop() {
  statobm=digitalRead(bottonem);
  statobo=digitalRead(bottoneo);
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
  
// OROLOGIO
  s=s+1;
  if(s==60){
    m=m+1;
    s=0;
  }
  if(m==60){
    o=o+1;
    m=0;
  }
  if(o==24){
    o=0;
    m=0;
    s=0;
  }

//BOTTONE
  if(statobm==1){
    m=m+1;
  }
  else{
    m=m+0;
  }
  if(statobo==1){
    o=o+1;
  }
  else{
    o=o+0;
  }
  
  
  lcd.setCursor(0, 1);
  lcd.print(o);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);
  
  if(t>16 && t<25){
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledrosso, LOW);
    digitalWrite(ledblu, LOW);
  }
  if(t<17){
    digitalWrite(ledverde, LOW);
    digitalWrite(ledrosso, LOW);
    digitalWrite(ledblu, HIGH); 
  }
  if(t>24){
    digitalWrite(ledverde, LOW);
    digitalWrite(ledrosso, HIGH);
    digitalWrite(ledblu, LOW);
  }
  delay(858);
  if(s==59){
    lcd.clear();
  }
}
