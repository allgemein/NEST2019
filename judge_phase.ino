#include"define.h"
#include"pin.h"
#include"prototype.h"

int judge_phase(){
	int phase;
	if(count_pht_silver()>=3) phase = case_rescue;//銀テープを踏んでいるかどうか
	else if(count_backpht_black()>=3) phase = case_crossing;//交差点かどうか
	else if((analogRead(phtLl)<limen&&analogRead(phtLr)<limen)&&!(analogRead(phtRl)<limen&&analogRead(phtRr)<limen)) phase = case_Lrightangle;//左直角かどうか
	else if(!(analogRead(phtLl)<limen&&analogRead(phtLr)<limen)&&(analogRead(phtRl)<limen&&analogRead(phtRr)<limen)) phase = case_Rrightangle;//右直角かどうか
	else if(get_distance(F_position)<10) phase = case_obstacle;//障害物があるかどうか
	else phase = 1024;//その他の場合(=ライントレース)。値は適当
}
