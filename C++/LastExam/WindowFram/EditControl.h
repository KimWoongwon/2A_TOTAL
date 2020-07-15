#pragma once
#include "Global.h"


class CEditControl
{
	HWND	mHWnd;

public:
	CEditControl(int, int, int, int, int);
	~CEditControl();

	HWND GetHandle();

	void ResetControl();
	void SetPosition(int, int, int, int);
	void GetText(TCHAR**, int);
	void SetVisable(bool);
};

