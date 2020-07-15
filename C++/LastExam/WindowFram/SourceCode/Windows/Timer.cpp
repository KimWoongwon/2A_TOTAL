#include "Timer.h"


int 	CTimer::mTimerNumber = 0;
CTimer::CTimer(HWND _hwnd, int _speed)
{
	mTimerNumber++;
	mTimerID = mTimerNumber;
	mWnd = _hwnd;
	mSpeed = _speed;
	SetTimer(mWnd, mTimerNumber, mSpeed, NULL);
}

int CTimer::GetTimerNumber()
{
	return mTimerNumber;
}

HWND CTimer::GetmWnd()
{
	return mWnd;
}

int	CTimer::GetSpeed()
{
	return mSpeed;
}

int	CTimer::GetTimerID()
{
	return mTimerID;
}
CTimer::~CTimer()
{
	KillTimer(mWnd, mTimerID);
}
