#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define MAPSIZE_Y 15		// �� ���� ������
#define MAPSIZE_X 23		// �� ���� ������
#define ENEMY_COUNT 7		// ���� �� ��

// ���� ��ũ��
#define Swap(x, y, type) \
do				\
{				\
	type temp;	\
	temp = x;	\
	x = y;		\
	y = temp;	\
} while(0)

/*--- ���� ������ ---*/
typedef struct {
	int no; 			/* ��ȣ */
	char ch; 		    /* ���� */
} DATA;

/*--- �����͸� �־��ֱ� ---*/
DATA DataSetting(int num, char ch);

void CursorView(char show);

void gotoxy(int x, int y);



