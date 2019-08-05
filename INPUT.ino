#include"define.h"
#include"pin.h"
#include"prototype.h"

int get_distance(int position){//超音波センサ読み取り関数

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

int count_pht_silver(){//銀色を読み取った後部フォトリフレクタの数を数える関数
	int count = 0;
	if(analogRead(phtLl)>limen_silver) count++;
	if(analogRead(phtLr)>limen_silver) count++;
	if(analogRead(phtRl)>limen_silver) count++;
	if(analogRead(phtRr)>limen_silver) count++;
	return count;
}

int count_backpht_black(){//黒を読み取った後部フォトリフレクタの数を数える関数
	int count = 0;
	if(analogRead(phtLl)<limen) count++;
	if(analogRead(phtLr)<limen) count++;
	if(analogRead(phtRl)<limen) count++;
	if(analogRead(phtRr)<limen) count++;
	return count;
}
