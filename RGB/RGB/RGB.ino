/*
 * PROGETTO MILLER
 * by Guaira Jaramillo Nitoglia
 * 
 * 
 * V. 0.2
 * 
 * -------------------------
 * -------------------------
 * 
 * Obiettivo progetto: controllo di un RGB tramite la pressione di alcuni pulsanti su un telecomando a infrarossi
 * 
 * -------------------------
 * -------------------------
 * 
 * CHANGELOG:
 * ** 25/12/2018 ** v 0.1 **
 * -Creazione progetto
 * -Abilitazione dell' RGB
 * -Aggiunto display LCD
 * [BUG] controllo tramite telecomando non funzionante
 * 
 * ** 25/12/2018 ** v 0.2 **
 * -
 */
#include <LiquidCrystal.h>
#include <IRremote.h>
int IRpin=6;
int rgbrosso=2;
int rgbverde=3;
int rgbblu=4;
int contatore=0;
int contatore1=0;
int riga=0;
int valore=0;
IRrecv irrecv(IRpin);
decode_results results;
const int rs=12, en=11, d4=10, d5=9, d6=8, d7=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(rgbrosso, OUTPUT);
  pinMode(rgbverde, OUTPUT);
  pinMode(rgbblu, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Benvenuto");
  lcd.setCursor(0, 1);
  lcd.print("P. Miller 0.2");
  delay(1000);
  lcd.clear();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();
  }

  if(results.value==0xFF30CF){
    lcd.print("1");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF18E7){
    lcd.print("2");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF7A85){
    lcd.print("3");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF10EF){
    lcd.print("4");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF38C7){
    lcd.print("5");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF5AA5){
    lcd.print("6");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF42BD){
    lcd.print("7");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF4AB5){
    lcd.print("8");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF52AD){
    lcd.print("9");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFF6897){
    lcd.print("0");
    delay(500);
    if(riga=0){
      contatore=contatore+1;
    }
    else{
      contatore1=contatore1+1;
    }
  }
  if(results.value==0xFFA25D){
    lcd.clear();
    contatore=0;
    contatore1=0;
  }
  if(results.value==0xFFE01F){
    lcd.setCursor(contatore, 1);
    riga=1;
  }
  if(results.value==0xFF906F){
    lcd.setCursor(contatore1, 0);
    riga=0;
  }
  
  
  analogWrite(rgbrosso, 200);
  analogWrite(rgbverde, 100);
  analogWrite(rgbblu, 180);

  lcd.print("ciao Mondo!");
  delay(3000);
  lcd.setCursor(0, 4);
  lcd.print("           ");
  delay(3000);

}
