#include "define.h"
#include"pin.h"
#include"prototype.h"
void debug_pht(){//�f�o�b�O�y�ю������s���p�̃t�H�g���t���N�^�ǂݎ��l�\���֐��B
	char str[124];

	int valLl = analogRead(phtLl);
	int valLr = analogRead(phtLr);
	int valC = analogRead(phtC);
	int valRl = analogRead(phtRl);
	int valRr = analogRead(phtRr);

	sprintf(str,"pht: %4d%4d%4d%4d%4d",valLl,valLr,valC,valRl,valRr);
	Serial.println(str);

	}

void debug_motor(){//�O�i����ށ����O�i��ށ��E�O�i��ށ���~�̏��ŌJ��Ԃ��֐��B�f�o�b�O�p

	MOVE(255,255);
	delay(750);
	MOVE(-255,-255);
	delay(750);
	MOVE(255,0);
	delay(750);
	MOVE(-255,0);
	delay(750);
	MOVE(0,255);
	delay(750);
	MOVE(0,-255);
	delay(750);
	MOVE(0,0);
	delay(250);

	}

//���H����
void rescue(){
	Serial.println("test");
}
void rightangle(int position){
	Serial.println("test");
}
int get_colorG(int position){
	Serial.println("test");
	return 1;
}
void turn(int position){
	Serial.println("test");
}
