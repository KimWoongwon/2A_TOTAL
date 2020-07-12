#pragma once
#include <windows.h>
#include <time.h>
#include <math.h>
#include "resource.h"

#define PI				3.141592654

#define IDT_MAP_LOOP	1000
#define IDT_PLAYER_MOVE 1001
#define IDT_BULLET_MOVE 1002
#define IDT_ENEMY_MOVE	1003
#define IDT_ENEMY_GEN	1004

enum xMove
{
	XLEFT = -1,
	XNONE = 0,
	XRIGHT = 1
};

enum yMove
{
	YUP = -1, 
	YNONE = 0,
	YDOWN = 1
};

enum Rotate
{
	RLEFT = -1,
	RNONE = 0,
	RRIGHT = 1
};