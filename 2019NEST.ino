#include "define.h"
#include"pin.h"
#include"prototype.h"

void setup(){
	Serial.begin(9600);
	//�V���A���ʐM���J�n�B���x�͋��߂��Ȃ��̂�9600�ł������낤
	pinMode(USSRtrigR,OUTPUT);
	pinMode(USSRtrigL,OUTPUT);
	pinMode(USSRechoR,INPUT);
	pinMode(USSRtrigL,INPUT);
	//�����g�Z���T�p�̃f�W�^���s����pinMode
}

void loop(){

	while(0){
	debug_pht();
	delay(200);
	}
	while(0){
	debug_motor();
	}
	//���[�^�ƃt�H�g���t���N�^�̃f�o�b�O�p�֐��B�g�������Ƃ���whie���̒��g��true(=1)�ɂ���΂悢

	int phase=judge_phase();
	//����������ׂ����𔻒f����phase�ɒl��������B����switchcase���̕���Ɏg��
	
	//debug_pht();
	
	switch(phase){//judge_phase�Ō��肵���t�F�[�Y�Ɉڍs����
		case case_rescue:
			rescue();
			break;

		case case_crossing:
			crossing();
			break;

		case case_Rrightangle:
			rightangle(R_position);
			break;

		case case_Lrightangle:
			rightangle(L_position);
			break;

		case case_obstacle:
			obstacle();
			break;

		default: 
			linetrace();
			break;
	}
}
