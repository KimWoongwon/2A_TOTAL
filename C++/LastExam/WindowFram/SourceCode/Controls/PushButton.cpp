#include "PushButton.h"
#include "../Windows/WindowFrame.h"

CPushButton::CPushButton(int x, int y, int width, int height, int id)
{
	mHWnd = CreateWindow(TEXT("button"), TEXT(""), WS_CHILD, 
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)id, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CPushButton::~CPushButton()
{
}

HWND CPushButton::GetHandle()
{
	return mHWnd;
}

void CPushButton::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}


void CPushButton::SetCaption(TCHAR* _str)
{
	SetWindowText(mHWnd, _str);
}

void CPushButton::SetVisable(bool flag)
{
	if(!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}