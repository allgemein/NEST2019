#pragma once

/*プロトタイプ宣言用ヘッダーファイル*/

void MOVE(int Lpower, int Rpower);
void debug_pht();
void debug_color();
void debug_motor();
void debug_USSR();
int judge_phase();
double get_distance(int position);
void get_color(int *p);
int count_pht_silver();
int count_backpht_black();
int count_backpht_black();
void turn(int position);
void rescue();
void crossing();
void rightangle(int position);
void obstacle();
void linetrace();
void brake();
