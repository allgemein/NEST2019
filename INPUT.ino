#include"define.h"
#include"pin.h"
#include"prototype.h"

int get_distance(int position){//超音波センサにより距離を計測して返す関数

	unsigned long dur;
	double Dis;

	switch(position){

		case R_position:
			digitalWrite(USSRtrigR,LOW);
			delayMicroseconds(2);
			digitalWrite(USSRtrigR,HIGH);
			delayMicroseconds(10);
			digitalWrite(USSRtrigR,LOW);
			dur=pulseIn(USSRechoR,HIGH);
			break;

		case F_position:	
			digitalWrite(USSRtrigF,LOW);
			delayMicroseconds(2);
			digitalWrite(USSRtrigF,HIGH);
			delayMicroseconds(10);
			digitalWrite(USSRtrigF,LOW);
			dur=pulseIn(USSRechoF,HIGH);
			break;

		case L_position:	
			digitalWrite(USSRtrigL,LOW);
			delayMicroseconds(2);
			digitalWrite(USSRtrigL,HIGH);
			delayMicroseconds(10);
			digitalWrite(USSRtrigL,LOW);
			dur=pulseIn(USSRechoL,HIGH);
			break;

		default:
			break;
		}
		Dis=(dur*340*100)/2000000;
		Serial.print(Dis);
		Serial.println(" cm");

	return Dis;

}

int count_pht_silver(){//後列のフォトリフレクタのうちいくつが銀色を読んでいるかを返す関数
	int count = 0;
	if(analogRead(phtLl)>limen_silver) count++;
	if(analogRead(phtLr)>limen_silver) count++;
	if(analogRead(phtRl)>limen_silver) count++;
	if(analogRead(phtRr)>limen_silver) count++;
	return count;

}
int count_backpht_black(){//後列のフォトリフレクタのうちいくつが黒を読んでいるのかを返す関数
	int count = 0;
	if(analogRead(phtLl)<limen) count++;
	if(analogRead(phtLr)<limen) count++;
	if(analogRead(phtRl)<limen) count++;
	if(analogRead(phtRr)<limen) count++;
	return count;
}
