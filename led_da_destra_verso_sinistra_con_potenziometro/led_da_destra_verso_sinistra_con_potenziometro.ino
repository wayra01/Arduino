int val=0;
int pot=0;
int led1=3;
int led2=5;
int led3=6;
int led4=9;
int led5=10;
int led6=11;
void setup (){
	for (int i=1;i<13; i++) {
		pinMode (i,OUTPUT);
	}
}

void loop (){
	pot=analogRead(A1);
	val=map(pot, 0, 1023, 0, 255);
	analogWrite(led1, val);
	delay(500);
	pot=analogRead(A1);
	val=map(pot, 0, 1023, 0, 255);
	analogWrite(led2, val);
	delay(500);
	pot=analogRead(A1);
	val=map(pot, 0, 1023, 0, 255);
	analogWrite(led3, val);
	delay(500);
	pot=analogRead(A1);
	val=map(pot, 0, 1023, 0, 255);
	analogWrite(led4, val);
	delay(500);
	pot=analogRead(A1);
	val=map(pot, 0, 1023, 0, 255);
	analogWrite(led5, val);
	delay(500);
	pot=analogRead(A1);
	val=map(pot, 0, 1023, 0, 255);
	analogWrite(led6, val);
	delay(500);
	digitalWrite(led6, LOW);
	delay(500);
	digitalWrite(led5, LOW);
	delay(500);
	digitalWrite(led4, LOW);
	delay(500);
	digitalWrite(led3, LOW);
	delay(500);
	digitalWrite(led2, LOW);
	delay(500);
	digitalWrite(led1, LOW);
	delay(500);
}


