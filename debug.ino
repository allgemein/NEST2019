#include "define.h"
#include"pin.h"
#include"prototype.h"
void debug_pht(){//デバッグ及び試験走行時用のフォトリフレクタ読み取り値表示関数。
	char str[124];

	int valLl = analogRead(phtLl);
	int valLr = analogRead(phtLr);
	int valC = analogRead(phtC);
	int valRl = analogRead(phtRl);
	int valRr = analogRead(phtRr);

	sprintf(str,"pht: %4d%4d%4d%4d%4d",valLl,valLr,valC,valRl,valRr);
	Serial.println(str);

	}

void debug_motor(){//前進→後退→左前進後退→右前進後退→停止の順で繰り返す関数。デバッグ用

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

//↓工事中
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
