#ifndef  GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAX_CHARACTER 5

struct STATUS
{
	int Hp;
	int Mp;
	int ATK;
	int DEF;
	STATUS(int pHp, int pMp, int pATK, int pDEF) 
	{
		Hp = pHp;
		Mp = pMp;
		ATK = pATK;
		DEF = pDEF;
	}
};


enum JOB
{
	NONE = -1,
	WARRIOR = 1,
	HEALER,
	ARCHER,
	SORCERER
};

enum CHAR_MENU
{
	HUM =1,
	ORC,
	ELF
};

enum MAIN_MENU 
{ 
	JOIN=1, 
	LOGIN, 
	EXIT
};

enum LOGIN_MENU 
{
	CREATE = 1,
	DESTROY,
	DISPLAY,
	LOGOUT,
	DROP
};

istream& operator>>(istream& i, MAIN_MENU& input);

istream& operator>>(istream& i, LOGIN_MENU& input);

istream& operator>>(istream& i, CHAR_MENU& input);
istream& operator>>(istream& i, JOB& input);


#endif // ! _GLOBAL_H
