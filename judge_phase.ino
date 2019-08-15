#include"define.h"
#include"pin.h"
#include"prototype.h"

int judge_phase(){
	int phase;
	if(count_pht_silver()>=3) phase = case_rescue;//銀テープを通ったとき
	else if(count_backpht_black()>=3) phase = case_crossing;//黒い線の上に乗ったとき
	else if((analogRead(phtLl)<limen&&analogRead(phtLr)<limen)&&!(analogRead(phtRl)<limen&&analogRead(phtRr)<limen)) phase = case_Lrightangle;//左側のフォトリフレクタのみ黒になったとき
	else if(!(analogRead(phtLl)<limen&&analogRead(phtLr)<limen)&&(analogRead(phtRl)<limen&&analogRead(phtRr)<limen)) phase = case_Rrightangle;//右側のフォトリフレクタのみ黒になったとき
	else if(get_distance(F_position)<10) phase = case_obstacle;//10cm未満の距離に物体があったとき
	else phase = 1024;//普通のライントレースに移行するとき。値は適当
}
