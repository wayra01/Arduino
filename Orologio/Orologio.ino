/* Versione di prova da implementare allo sketch del termostato
 * v.1.0 B
 */

int o=0;
int m=0;
int s=0;
void setup() {
Serial.begin(9600);
delay(1000);


}

void loop() {
  Serial.println(s);
  Serial.println(":");
  Serial.println(m);
  Serial.println(":");
  Serial.println(o);
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
  delay(1000);
}
