#pragma once
#include"pin.h"
#include"prototype.h"
#include"define.h"

#define case_rescue 0
#define case_crossing 1
#define case_Rrightangle 2
#define case_Lrightangle 3
#define case_obstacle 4

#define R_position 6
#define F_position 7
#define L_position 8
#define Uturn 9

const int basic_motorpower = 100;
const int boostpower_corner = 50;
const float p = 0.25;
const int limen = 750;
const int limen_green = 800;
const int limen_silver = 900;
