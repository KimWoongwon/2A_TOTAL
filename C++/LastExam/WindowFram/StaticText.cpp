#include "StaticText.h"
#include "WindowFrame.h"

CStaticText::CStaticText(int x, int y, int width, int height,int ID, TCHAR* _str)
{
	mHWnd = CreateWindow(TEXT("static"), _str, WS_CHILD | SS_RIGHT,
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)ID, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CStaticText::~CStaticText()
{
}
void CStaticText::ResetControl()
{
	SetWindowText(mHWnd, TEXT(""));
}
HWND CStaticText::GetHandle()
{
	return mHWnd;
}
void CStaticText::SetText(TCHAR* _str)
{
	SetWindowText(mHWnd, _str);
}

void CStaticText::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}

void CStaticText::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}