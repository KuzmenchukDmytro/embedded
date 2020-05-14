#include <Arduino.h>
#include "TimerThree.h"
#define PIN_POT A0;
const int pin [3]={8,9,10};
int uref=5;
int t=1000;//ручками по кругу
int k;

void fun(){
	//t=millis()/double(1000); //само по кругу
	k=analogRead(A0)/4;
	//Serial.println(uref/(2*(sin(k*t+2*M_PI/3)+1)));
	analogWrite(pin[2], uref/(2*(sin(k*t+4*M_PI/3)+1)));
	analogWrite(pin[1], uref/(2*(sin(k*t+2*M_PI/3)+1)));
	analogWrite(pin[0], uref/(2*(sin(k*t)+1)));

}

void setup() {
	for(int i=0;i<3;i++){
		pinMode(pin[i], OUTPUT);
		digitalWrite(pin[i],LOW);}
	//Serial.begin(9600);
}

void loop() {
	Timer3.initialize(10000);
		Timer3.attachInterrupt(fun);
}
