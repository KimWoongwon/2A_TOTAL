#pragma once
#include "../Global.h"


class CRadioButton
{
	HWND	mHWnd;

public:
	CRadioButton(TCHAR*,int, int, int, int, int, bool);
	~CRadioButton();

	HWND GetHandle();
	//void SetCheck(bool);
	void SetPosition(int, int, int, int);
	void SetCaption(TCHAR*);
	void SetVisable(bool);
};
