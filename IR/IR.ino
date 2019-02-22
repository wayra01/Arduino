#include <IRremote.h>
int IRpin=8;
int led1=4;
int led2=2;
int led3=3;
IRrecv irrecv(IRpin);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();
  }

  if(/*led1==LOW && */results.value==0xFF30CF){
    digitalWrite(led1, HIGH);
  }
  if(/*led1==HIGH && */results.value==0xFF18E7){
    digitalWrite(led1, LOW);
  }
  /*if(led2==LOW && results.value==0xFF18E7){
    digitalWrite(led2, HIGH);
  }
  if(led2==HIGH && results.value==0xFF18E7){
    digitalWrite(led2, LOW);
  }
  if(led3==LOW && results.value==0xFF7A85){
    digitalWrite(led1, HIGH);
  }
  if(led3==HIGH && results.value==0xFF7A85){
    digitalWrite(led1, LOW);
  }*/
}
