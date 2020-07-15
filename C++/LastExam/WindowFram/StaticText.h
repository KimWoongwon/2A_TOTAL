#pragma once
#include "Global.h"

class CStaticText
{
	HWND	mHWnd;

public:
	CStaticText(int, int, int, int, int, TCHAR*);
	~CStaticText();

	HWND GetHandle();
	void ResetControl();
	void SetText(TCHAR*);
	void SetAlignment(Alignment);
	void SetPosition(int, int, int, int);
	void SetVisable(bool);
};

