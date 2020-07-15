#ifndef _PUSHBUTTON_H
#define	_PUSHBUTTON_H

#include "Global.h"


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

#endif
