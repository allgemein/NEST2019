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

void debug_USSR(){
	double disL,disF,disR;
	char str[254];

	disL=get_distance(L_position);
	disF=get_distance(F_position);
	disR=get_distance(R_position);
	sprintf(str,"L: %2.3fcm  F:%2.3fcm  R:%2.3fcm",disL,disF,disR);
	Serial.println(str);
	delay(100);
}

//以下工事中
void rescue(){
	Serial.println("testrescue");
}
void get_color(int *p){
	digitalWrite(0,HIGH);
	*p=analogRead(ilumL);

	}
void turn(int position){
	Serial.println("testturn");
}

