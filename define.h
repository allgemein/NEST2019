#pragma once
#include"pin.h"
#include"prototype.h"
#include"define.h"

#define case_rescue 0
#define case_crossing 1
#define case_rightangle 2
#define case_obstacle 3
#define case_linetrace 4

#define R_position 5
#define F_position 6
#define L_position 7
#define Uturn 8

const int basic_motorpower = 100;
const int boostpower_corner = 50;
const float p = 0.25;
const int limen = 750;
const int green_limen = 800;
