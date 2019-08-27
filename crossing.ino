#include"define.h"
#include"pin.h"
#include"prototype.h"

void crossing(){//交差点処理関数
	int i,count,num_of_loop_to_back_line_width;
	int color[6];
	count = 0;

	while(1){//中央センサ黒、その他白となるまで

		MOVE(-150,-150);
		delay(5);

		count++;
		//後退し、その所要時間を計測

		if(analogRead(phtLl)>limenW && analogRead(phtRr)>limenW) break;//中央センサ黒、その他白となるまで
}


	num_of_loop_to_back_line_width = count;
	//わかりやすい変数に代入

	for(i=0; i<(int)num_of_loop_to_back_line_width*1.5; i++){
		MOVE(-150,-150);
		delay(50);
	}//先ほどの後退の所要時間を鑑み、1.5単位ぶん後退して照度センサとカラーマーカの位置を合わせる

	get_color(color);

	//照度センサで緑の値を取得

	if(color[GreenL]<limen_green && color[GreenR]>limen_green){
		turn(R_position);
	}//右のみ緑の場合右折

	else if(color[GreenL]>limen_green && color[GreenL]<limen_green){
		turn(R_position);
	}//左のみ緑の場合左折

	else if(color[GreenL]>limen_green && color[GreenR]>limen_green){
		turn(Uturn);
	}//左右ともに緑の場合Uターン

	else{
		for(i=0; i<(int)num_of_loop_to_back_line_width*3.5; i++){
			MOVE(150,150);
			delay(50);
		}
	}//緑マーカが検出されなかった場合、直角の誤認やcrossing無限ループの防止のために3.5単位ぶん前進
}
