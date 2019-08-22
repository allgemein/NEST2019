#include "define.h"
#include"pin.h"
#include"prototype.h"

void setup(){
	Serial.begin(9600);//シリアル通信を開始。速度は要求されないので9600でいいだろう

	pinMode(USSRtrigR,OUTPUT);//超音波センサ用のデジタルピンのpinMode
	pinMode(USSRtrigL,OUTPUT);
	pinMode(USSRechoR,INPUT);
	pinMode(USSRechoL,INPUT);
}

void loop(){
	//デバッグ用関数たち。使いたいときはwhie文の中身をtrue(=1)にすればよい
	while(0){
		debug_USSR();
		delay(50);
	}
	while(0){
		debug_pht();
		delay(150);
	}
	while(0){
		debug_color();
		delay(150);
		}
	while(0){
		debug_motor();
	}
	while(0){
		linetrace();
	}

	while(0){
		Serial.println(analogRead(ilumL));
		delay(100);
		}

	int phase=judge_phase();//今何をするべきかを判断してphaseに値を代入する。下のswitchcase文の分岐に使う

	debug_pht();

	switch(phase){//judge_phaseで決定したフェーズに移行する
		/*case case_rescue:
		  rescue();
		  break;

		case case_crossing:
		  crossing();
		  break;
		  */

		case case_white:
			Serial.println("white");
			while(count_backpht_black()==0){
				MOVE(75,75);
				delay(5);
			}
			break;

		/*case case_Rrightangle:
			rightangle(R_position);
			break;

		case case_Lrightangle:
			rightangle(L_position);
			break;

		case case_obstacle:
			obstacle();
			break;

			 */
		default: 
			linetrace();
			break;

	}
}
