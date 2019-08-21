#include "define.h"
#include"pin.h"
#include"prototype.h"

void MOVE(int Lpower,int Rpower){//みんな大好きMOVE関数

	if(Lpower>255) Lpower=255;
	if(Lpower<-255) Lpower=-255;
	if(Rpower>255) Rpower=255;
	if(Rpower<-255)Rpower=-255;

	if(Lpower>0){
		analogWrite(motorL1,Lpower);
		analogWrite(motorL2,0);
	}
	else{
		analogWrite(motorL1,0);
		analogWrite(motorL2,-Lpower);
	}

	if(Rpower>0){
		analogWrite(motorR1,Rpower);
		analogWrite(motorR2,0);
	}
	else{
		analogWrite(motorR1,0);
		analogWrite(motorR2,-Rpower);
	}

}

void brake(){//モータのブレーキ関数。慣性で回り続けるのが気になるときに
	analogWrite(motorL1,255);
	analogWrite(motorL2,255);
	analogWrite(motorR1,255);
	analogWrite(motorR2,255);
	delay(50);
}

void rightangle(int position){
	while(analogRead(phtC)>150){
		if(position==R_position){
			MOVE(255,-255);
		}else{
			MOVE(-255,255);
		}
		delay(10);
		Serial.println("rightangle");
	}
}
