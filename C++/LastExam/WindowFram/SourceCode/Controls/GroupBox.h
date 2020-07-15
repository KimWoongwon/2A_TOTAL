#pragma once
#include "../Global.h"

class CGroupBox
{
	HWND	mHWnd;

public:
	CGroupBox(TCHAR*, int, int, int, int, int);
	~CGroupBox();

	HWND GetHandle();
	void SetPosition(int, int, int, int);
	void SetCaption(TCHAR*);
	void SetVisable(bool);
};

