#pragma once
#include "Global.h"

class CTimer
{
	static  int 	mTimerNumber;
	HWND			mWnd;
	int				mSpeed;
	int				mTimerID;
public:
	int GetTimerNumber();
	HWND GetmWnd();
	int	GetSpeed();
	int	GetTimerID();
	CTimer(HWND, int);
	~CTimer();
};

