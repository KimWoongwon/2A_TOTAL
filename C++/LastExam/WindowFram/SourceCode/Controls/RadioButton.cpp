#include "RadioButton.h"
#include "../Windows/WindowFrame.h"

CRadioButton::CRadioButton(TCHAR* _str,int x, int y, int width, int height, int id, bool isGroup)
{
	if(isGroup)
		mHWnd = CreateWindow(TEXT("button"), _str, WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)id, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
	else
		mHWnd = CreateWindow(TEXT("button"), _str, WS_CHILD | BS_AUTORADIOBUTTON,
			x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)id, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CRadioButton::~CRadioButton()
{

}

HWND CRadioButton::GetHandle()
{
	return mHWnd;
}

void CRadioButton::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}


void CRadioButton::SetCaption(TCHAR* _str)
{
	SetWindowText(mHWnd, _str);
}

void CRadioButton::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}