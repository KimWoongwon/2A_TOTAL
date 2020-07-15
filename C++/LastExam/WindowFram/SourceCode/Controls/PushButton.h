#pragma once

#include "../Global.h"


class CPushButton
{
	HWND	mHWnd;

public:
	CPushButton(int, int, int, int, int);
	~CPushButton();

	HWND GetHandle();
	void SetPosition(int, int, int, int);
	void SetCaption(TCHAR*);
	void SetVisable(bool);
};

