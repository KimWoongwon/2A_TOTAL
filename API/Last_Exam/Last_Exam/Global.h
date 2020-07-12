#pragma once
#include <windows.h>
#include <time.h>
#include <math.h>
#include "resource.h"

// ��� ������ �κ��Դϴ�.
#define PI				3.141592654
#define MAX_PLBULLET	50
#define MAX_ENEMY		20
#define MAX_EYBULLET	20
#define MAX_LEVEL		8

// Ÿ�̸� ID ���Դϴ�.
#define IDT_MAP_LOOP			1000	// ����̹��� ����
#define IDT_PLAYER_MOVE			1001	// �÷��̾� �̵� 
#define IDT_BULLET_MOVE			1002	// ���� �Ѿ��� �̵�
#define IDT_ENEMY_MOVE			1003	// ���� ���� �̵�
#define IDT_FIXED_UPDATE		1004	// ���� ������Ʈ 
#define IDT_ENEMY_ANIMAITION	1005	// ���� �ִϸ��̼�

// ������ Ÿ�� 1~4 �̹����� �ٸ��ϴ�.
enum EnemyType { Enemy01 = 0, Enemy02, Enemy03, Enemy04 };

// �÷��̾� �̵��� x�� ���� ����
enum xMove { XLEFT	= -1, XNONE, XRIGHT };
// �÷��̾� �̵��� y�� ���� ����
enum yMove { YUP	= -1, YNONE, YDOWN };
// �÷��̾� ȸ���� ȸ������
enum Rotate{ RLEFT	= -1, RNONE, RRIGHT };