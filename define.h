#pragma once

#include"pin.h"
#include"prototype.h"
#include"define.h"


/*プログラムの可読性を高めるために文字列を数字に置換するための命令*/

#define case_rescue 0
#define case_crossing 1
#define case_Rrightangle 2
#define case_Lrightangle 3
#define case_obstacle 4

#define R_position 6
#define F_position 7
#define L_position 8
#define Uturn 9

#define RedR 0
#define GreenR 1
#define BlueR 2
#define RedL 3
#define GreenL 4
#define BlueL 5


/*閾値、比例の係数などの定数の定義*/

const int basic_motorpower = 50;
const int boostpower_corner = 30;
const float p = 0.18;
const int limen = 550;
const int limenC = 80;
const int limen_green = 800;
const int limen_silver = 900;
