#include"define.h"
#include"pin.h"
#include"prototype.h"

int judge_phase(){

	int phase;

	/*if(count_pht_silver()>=3){

		phase = case_rescue;//銀テープを通ったとき
		Serial.println("rescue");

	}else*/if(count_backpht_black()>=3){

		phase = case_crossing;//黒い線の上に乗ったとき
		Serial.println("crossing");

	}else if(analogRead(phtC)>limenC && count_backpht_white()==4){
		
		phase = case_white;

	}/*else if(analogRead(phtC)>limenC &&
		analogRead(phtLl)<limen && analogRead(phtLr)<limen && 
		analogRead(phtRl)>limen && analogRead(phtRr)>limen){

		phase = case_Lrightangle;//左側のフォトリフレクタのみ黒になったとき

	}else if(analogRead(phtC)>limenC &&
			analogRead(phtLl)>limen && analogRead(phtLr)>limen &&
			analogRead(phtRl)<limen && analogRead(phtRr)<limen){

		phase = case_Rrightangle;//右側のフォトリフレクタのみ黒になったとき

	}*/else if(digitalRead(bumperL)==0){

		phase = case_obstacle;//10cm未満の距離に物体があったとき
		Serial.println("obstacle");

	}else {

		phase = 1024;//普通のライントレースに移行するとき。値は適当

	}

	return phase;
}
