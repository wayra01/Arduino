/*####################################################################
  FILE: dht11_esempio_lcd.ino
  VERSION: 2.0
  Descrizione: Programma di prova per sensore digitale di umidità e temperatura
  tipo DHT11, il programma legge le informazioni  attraverso la linea DATA
  e scrive i valori su display LCD

  Collegamenti
   BOARD -> ARDUINO
   +5V   -> 5V
   GND   -> GND
   DATA  -> 2
   LCD   -> 5

  Ultima modifica il 1/10/2014
  Applicazione realizzata da Adriano Gandolfo
  Sito https://www.adrirobot.it
  Blog http://it.emcelettronica.com/author/adrirobot
  Pagina Facebook https://www.facebook.com/Adrirobot-318949048122955
  Istagram https://www.instagram.com/adrirobot/
  This example code is in the public domain.
  #######################################################################*/

#include <dht11.h>
#include <SoftwareSerial.h>
#include <SerLCD.h>

dht11 DHT11;
SoftwareSerial NSS(0, 5);
SerLCD lcd(NSS);

#define DHT11PIN 2 //Pin a cui è collegato il sensore

void setup()
{
  NSS.begin(9600);
  lcd.begin();
  lcd.setBacklight(255);
  lcd.clear();
  lcd.setPosition(1, 0);
  lcd.print("Temperat.[C]: ");
  lcd.setPosition(2, 0);
  lcd.print("Umidita' [%]: ");
  delay(1000);  // Pausa di stabilizzazione sensore
}

void loop()
{
  uint8_t chk = DHT11.read(DHT11PIN);
  //Valori su display 16X2
  lcd.setPosition(1, 13);
  lcd.print(DHT11.temperature, DEC);
  lcd.setPosition(2, 13);
  lcd.print(DHT11.humidity, DEC);
  delay(2000); //Intervallo di misura
}
