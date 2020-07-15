#include "ListBox.h"
#include "WindowFrame.h"


CListBox::CListBox(int x, int y, int width, int height, int ID)
{
	mHWnd = CreateWindow(TEXT("ListBox"), TEXT(""), WS_CHILD | WS_BORDER ,
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)ID, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CListBox::~CListBox()
{
}

HWND CListBox::GetHandle()
{
	return mHWnd;
}

void CListBox::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}

void CListBox::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}