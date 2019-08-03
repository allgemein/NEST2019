#include"define.h"
#include"pin.h"
#include"prototype.h"

int get_distance(int position){

	int Dis,time;

	switch(position){

		case R_position:
			digitalWrite(USSRtrigR,LOW);
			delayMicroseconds(2);
			digitalWrite(USSRtrigR,HIGH);
			delayMicroseconds(10);
			digitalWrite(USSRtrigR,LOW);
			time=pulseIn(USSRechoR,HIGH,100000);

		case F_position:	
			digitalWrite(USSRtrigF,LOW);
			delayMicroseconds(2);
			digitalWrite(USSRtrigF,HIGH);
			delayMicroseconds(10);
			digitalWrite(USSRtrigF,LOW);
			time=pulseIn(USSRechoF,HIGH,100000);

		case L_position:	
			digitalWrite(USSRtrigL,LOW);
			delayMicroseconds(2);
			digitalWrite(USSRtrigL,HIGH);
			delayMicroseconds(10);
			digitalWrite(USSRtrigL,LOW);
			time=pulseIn(USSRechoL,HIGH,100000);
		
		}

	if(time>0){
		time=time/2;
		Dis=(time*340*100)/1000000;
		Serial.print(Dis);
		Serial.println(" cm");
		}

	return Dis;

}
