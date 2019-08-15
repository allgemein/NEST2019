#include "define.h"
#include"pin.h"
#include"prototype.h"

void linetrace(){
	int diff,Lpower,Rpower;
	char str[254];
	diff = analogRead(phtLr)-analogRead(phtRl);
	Lpower = basic_motorpower+(diff*p);
	Rpower = basic_motorpower-(diff*p);
	if(analogRead(phtC)>90/*limen*/){
		if(analogRead(phtLl)>analogRead(phtRr)){
			Lpower+=boostpower_corner;
			Rpower-=boostpower_corner;
		}else{
			Lpower-=boostpower_corner;
			Rpower+=boostpower_corner;
		}
	}

	sprintf(str,"power: %4d,%4d",Lpower,Rpower);
	Serial.print(str);
	debug_pht();

	MOVE(Lpower,Rpower);
	delay(10);
}
