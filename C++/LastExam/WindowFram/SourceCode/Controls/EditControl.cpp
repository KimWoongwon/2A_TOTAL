#include "EditControl.h"
#include "../Windows/WindowFrame.h"

CEditControl::CEditControl(int x, int y, int width, int height, int id)
{
	mHWnd = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_BORDER,
		x, y, width, height, CWindowFrame::GetInstance()->GethWnd(), (HMENU)id, CWindowFrame::GetInstance()->GetInstanceHandle(), NULL);
}


CEditControl::~CEditControl()
{
}

HWND CEditControl::GetHandle()
{
	return mHWnd;
}

void CEditControl::ResetControl()
{
	SetWindowText(mHWnd, TEXT(""));
}
void CEditControl::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}


void CEditControl::GetText(TCHAR** output, int size)
{
	GetWindowText(mHWnd, *output, size);
}

void CEditControl::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}