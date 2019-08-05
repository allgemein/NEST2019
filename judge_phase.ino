#include"define.h"
#include"pin.h"
#include"prototype.h"

int judge_phase(){
	int phase;
	if(count_pht_silver()>=3) phase = case_rescue;//��e�[�v�𓥂�ł��邩�ǂ���
	else if(count_backpht_black()>=3) phase = case_crossing;//�����_���ǂ���
	else if((analogRead(phtLl)<limen&&analogRead(phtLr)<limen)&&!(analogRead(phtRl)<limen&&analogRead(phtRr)<limen)) phase = case_Lrightangle;//�����p���ǂ���
	else if(!(analogRead(phtLl)<limen&&analogRead(phtLr)<limen)&&(analogRead(phtRl)<limen&&analogRead(phtRr)<limen)) phase = case_Rrightangle;//�E���p���ǂ���
	else if(get_distance(F_position)<10) phase = case_obstacle;//��Q�������邩�ǂ���
	else phase = 1024;//���̑��̏ꍇ(=���C���g���[�X)�B�l�͓K��
}
