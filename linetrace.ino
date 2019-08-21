#include "define.h"
#include"pin.h"
#include"prototype.h"

void linetrace(){
	int diff,Lpower,Rpower,differential;
	Lpower=0;
	Rpower=0;

	float fix_power_differential;
	char str[254];
	static int previous_diff = 50;

	diff = analogRead(phtLr)-analogRead(phtRl);
	differential = abs(diff)-abs(previous_diff);

	if(differential>250){
		fix_power_differential=1.3;
	}else if(differential<50){
		fix_power_differential=0.75;
		Lpower+=100;
		Rpower+=100;
	}else{
		fix_power_differential=1;
	}

	Lpower = basic_motorpower+(diff*p*fix_power_differential);
	Rpower = basic_motorpower-(diff*p*fix_power_differential);
	if(analogRead(phtC)>60/*limen*/){
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
	delay(5);
}
