int pausa=500;
int pot=0;
void setup() {
	for(int i=3; i<10; i++){
		pinMode(i, OUTPUT);
	}
	
}

void loop() {
	for(int i=3; i<10; i++){
		pot=analogRead(A1);
		pausa=map(pot, 0, 1023, 0, 255);
		digitalWrite(i,HIGH);
		delay(pausa);
	}
	for(int i=9; i>2; i=i-1){
		pot=analogRead(A1);
		pausa=map(pot, 0, 1023, 0, 255);
		digitalWrite(i,LOW);
		delay(pausa);
	}
}