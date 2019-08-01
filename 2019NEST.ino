#include "define.h"
#include"pin.h"
#include"prototype.h"

void setup(){
	Serial.begin(9600);
	pinMode(USSRtrigR,OUTPUT);
	pinMode(USSRtrigL,OUTPUT);
	pinMode(USSRechoR,INPUT);
	pinMode(USSRtrigL,INPUT);
}

void loop(){

	while(0){
	debug_pht();
	delay(200);
	}
	while(0){
	debug_motor();
	}

	int phase=judge_phase();
	
	//debug_pht();
	
	switch(phase){
		case case_rescue:
			rescue();
			break;

		case case_crossing:
			crossing();
			break;

		case case_rightangle:
			rightangle();
			break;

		case case_obstacle:
			obstacle();
			break;

		case case_linetrace:
			linetrace();
			break;

		default:
			break;
	}
}
