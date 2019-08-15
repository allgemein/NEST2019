#include "define.h"
#include"pin.h"
#include"prototype.h"

void setup(){
	Serial.begin(9600);
	Serial.setTimeout(5);
	//シリアル通信を開始。速度は求められないので9600でいいだろう
	pinMode(USSRtrigR,OUTPUT);
	pinMode(USSRtrigL,OUTPUT);
	pinMode(USSRechoR,INPUT);
	pinMode(USSRechoL,INPUT);
	//超音波センサ用のデジタルピンのpinMode
}

void loop(){
	while(1){
	get_distance(R_position);
	delay(50);
	}
	while(0){
	debug_pht();
	delay(200);
	}
	while(0){
	debug_motor();
	}
	while(1){
	linetrace();
	}
	//モータとフォトリフレクタのデバッグ用関数。使いたいときはwhie文の中身をtrue(=1)にすればよい

	int phase=judge_phase();
	//今何をするべきかを判断してphaseに値を代入する。下のswitchcase文の分岐に使う

	//debug_pht();
	
	switch(phase){//judge_phaseで決定したフェーズに移行する
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
