#include "define.h"
#include"pin.h"
#include"prototype.h"
void debug_pht(){//フォトリフレクタの読み取り値をシリアルモニタに表示する関数
	char str[124];

	int valLl = analogRead(phtLl);
	int valLr = analogRead(phtLr);
	int valC = analogRead(phtC);
	int valRl = analogRead(phtRl);
	int valRr = analogRead(phtRr);

	sprintf(str,"  pht: %4d%4d%4d%4d%4d",valLl,valLr,valC,valRl,valRr);
	Serial.println(str);

	}

void debug_motor(){//モータをデバッグしたいとき用。原則として左側が先に動く。

	MOVE(255,255);
	delay(750);
	MOVE(-255,-255);
	delay(750);
	brake();
	MOVE(255,0);
	delay(750);
	brake();
	MOVE(-255,0);
	delay(750);
	brake();
	MOVE(0,255);
	delay(750);
	brake();
	MOVE(0,-255);
	delay(750);
	MOVE(0,0);
	delay(250);

	}

//以下工事中
void rescue(){
	Serial.println("test");
}
void rightangle(int position){
	while(analogRead(phtC)>limen){
		if(position==R_position) MOVE(255,-255);
		else MOVE(-255,255);
	}
}
int get_colorG(int position){
	Serial.println("test");
	return 1;
}
void turn(int position){
	Serial.println("test");
}

