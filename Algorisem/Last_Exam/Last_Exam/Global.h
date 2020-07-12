#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define MAPSIZE_Y 15		// 맵 세로 사이즈
#define MAPSIZE_X 23		// 맵 가로 사이즈
#define ENEMY_COUNT 7		// 몬스터 총 수

// 스왑 메크로
#define Swap(x, y, type) \
do				\
{				\
	type temp;	\
	temp = x;	\
	x = y;		\
	y = temp;	\
} while(0)

/*--- 몬스터 데이터 ---*/
typedef struct {
	int no; 			/* 번호 */
	char ch; 		    /* 글자 */
} DATA;

/*--- 데이터를 넣어주기 ---*/
DATA DataSetting(int num, char ch);

void CursorView(char show);

void gotoxy(int x, int y);



