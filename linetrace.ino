#include "define.h"
#include"pin.h"
#include"prototype.h"

void linetrace(){
	int diff,Lpower,Rpower,differential;
	Lpower=0;
	Rpower=0;

	float fix_power_differential;
	char str[254];//sprintf()用の文字配列
	static int previous_diff = 50;

	diff = analogRead(phtLr)-analogRead(phtRl);//左右内側のフォトリフレクタの値の差を取る
	differential = abs(diff)-abs(previous_diff);//前回のループと今回のループのdiffの差を取り、両者の間での変化の激しさを調べる。この値を用いて微分的な処理などを行う

	if(differential>250){//diffに激しい変化があった場合
		fix_power_differential=1.3;//p値の係数を大きくする
	}else if(differential<50){//diffの変化が少量であった場合
		fix_power_differential=0.75;//p値の係数を小さくし
		Lpower+=100;
		Rpower+=100;//左右のモータの基礎出力を上げる
	}else{//乗算に使う変数なので、どちらでもない場合には影響のないよう1を代入しておく
		fix_power_differential=1;
	}

	Lpower = basic_motorpower+(diff*p*fix_power_differential);
	Rpower = basic_motorpower-(diff*p*fix_power_differential);//前進するための基礎出力に対し、左右のフォトリフレクタの値の差と比例の係数と先ほどの係数とをかけたものを加算(と減算)する

	if(analogRead(phtC)>limenC){//中央のフォトリフレクタが白のとき、角やカーブと判定して出力の差を増強する

		if(analogRead(phtLl)>analogRead(phtRr)){
			Lpower+=boostpower_corner;
			Rpower-=boostpower_corner;
		}else{
			Lpower-=boostpower_corner;
			Rpower+=boostpower_corner;
		}

	}



	sprintf(str,"power: %4d,%4d",Lpower,Rpower);//シリアルモニタに見やすく表示されるよう、配列にLpowerとRpowerと文字列を結合した文字列を格納する
	Serial.print(str);//先の文字列をシリアルモニタに出力する
	debug_pht();//フォトリフレクタの値を出力する

	MOVE(Lpower,Rpower);//決定された出力でモータを動かす
	delay(5);//負荷軽減のためにdelayをかける

	previous_diff = diff;//比較に使うために今回のdiffの値を保存しておく
}
