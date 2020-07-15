#pragma once
#include "../Global.h"

class CListBox
{
	HWND	mHWnd;
public:
	CListBox(int, int, int, int, int);
	~CListBox();
	
	HWND GetHandle();
	void SetPosition(int, int, int, int);
	void SetVisable(bool);
};