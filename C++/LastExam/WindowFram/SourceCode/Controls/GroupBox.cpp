#include "GroupBox.h"
#include "../Windows/WindowFrame.h"

CGroupBox::CGroupBox(TCHAR* _str,int x, int y, int width, int height, int id)
{
	mHWnd = CreateWindow(TEXT("button"), _str, WS_CHILD | BS_GROUPBOX,
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)id, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CGroupBox::~CGroupBox()
{
}

HWND CGroupBox::GetHandle()
{
	return mHWnd;
}

void CGroupBox::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}

void CGroupBox::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}