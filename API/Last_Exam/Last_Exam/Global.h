#pragma once
#include <windows.h>
#include <time.h>
#include <math.h>
#include "resource.h"

// 상수 정의한 부분입니다.
#define PI				3.141592654
#define MAX_PLBULLET	50
#define MAX_ENEMY		20
#define MAX_EYBULLET	20
#define MAX_LEVEL		8

// 타이머 ID 값입니다.
#define IDT_MAP_LOOP			1000	// 배경이미지 루프
#define IDT_PLAYER_MOVE			1001	// 플레이어 이동 
#define IDT_BULLET_MOVE			1002	// 각종 총알의 이동
#define IDT_ENEMY_MOVE			1003	// 몬스터 관련 이동
#define IDT_FIXED_UPDATE		1004	// 물리 업데이트 
#define IDT_ENEMY_ANIMAITION	1005	// 몬스터 애니메이션

// 몬스터의 타입 1~4 이미지가 다릅니다.
enum EnemyType { Enemy01 = 0, Enemy02, Enemy03, Enemy04 };

// 플레이어 이동시 x축 기준 방향
enum xMove { XLEFT	= -1, XNONE, XRIGHT };
// 플레이어 이동시 y축 기준 방향
enum yMove { YUP	= -1, YNONE, YDOWN };
// 플레이어 회전시 회전방향
enum Rotate{ RLEFT	= -1, RNONE, RRIGHT };