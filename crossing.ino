#include"define.h"
#include"pin.h"
#include"prototype.h"

void crossing(){//交差点処理関数
	int i,count;
	int color[6];
	count = 0;

	MOVE(-150,-150);
	delay(1000);
	while(1){
		get_color(color);
	if(((color[GreenL]-color[RedL])>L_limenG)||((color[GreenR]-color[RedR])>R_limenG)) break;
		if(phtLl<limenB && phtRr<limenB) break;
		linetrace();
	}

	if((!(color[GreenL]-color[RedL])>L_limenG)&&((color[GreenR]-color[RedR])>R_limenG)){
		turn(R_position);
	}//右のみ緑の場合右折

	else if(((color[GreenL]-color[RedL])>L_limenG)&&!((color[GreenR]-color[RedR])>R_limenG)){
		turn(R_position);
	}//左のみ緑の場合左折

	else if(((color[GreenL]-color[RedL])>L_limenG)&&((color[GreenR]-color[RedR])>R_limenG)){
		turn(Uturn);
	}//左右ともに緑の場合Uターン

	else{
		MOVE(150,150);
		delay(1000);
	}
}
