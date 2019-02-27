
int val=0;
int LedPin;
void setup (){
	for (LedPin=1;LedPin<9; LedPin++) {
		pinMode (LedPin,OUTPUT);
	}
}

void loop (){
	
	for (LedPin=1;LedPin<9;LedPin++){
    int pot= analogRead (A0);
    val=map(val,0,1023,0,255);
		analogWrite(LedPin,val);
		delay(500);
		
	}
	for (LedPin=1;LedPin>9;LedPin--){
     int pot= analogRead (A0);
     val=map(val,0,1023,0,255);
		analogWrite(LedPin,val);
		delay(500);
	}
}


