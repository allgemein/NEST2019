#include "define.h"
#include"pin.h"
#include"prototype.h"

void MOVE(int Lpower,int Rpower){

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
