#include "StaticText.h"
#include "../Windows/WindowFrame.h"

CStaticText::CStaticText(int x, int y, int width, int height,int ID, TCHAR* _str)
{
	mHWnd = CreateWindow(TEXT("static"), _str, WS_CHILD | SS_RIGHT,
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)ID, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CStaticText::~CStaticText()
{
}
HWND CStaticText::GetHandle()
{
	return mHWnd;
}
void CStaticText::ResetControl()
{
	SetWindowText(mHWnd, TEXT(""));
}

void CStaticText::SetText(TCHAR* _str)
{
	SetWindowText(mHWnd, _str);
}

void CStaticText::SetAlignment(Alignment settingID)
{
	switch (settingID)
	{
	case Alignment::Left:
		SetWindowLong(mHWnd, GWL_STYLE, WS_CHILD | SS_LEFT);
		break;
	case Alignment::Center:
		SetWindowLong(mHWnd, GWL_STYLE, WS_CHILD | SS_CENTER);
		break;
	case Alignment::Right:
		SetWindowLong(mHWnd, GWL_STYLE, WS_CHILD | SS_RIGHT);
		break;
	}
	
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