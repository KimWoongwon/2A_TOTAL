#include "EditControl.h"
#include "../Windows/WindowFrame.h"

// 컨트롤 클래스 생성자
CEditControl::CEditControl(int x, int y, int width, int height, int id)
{
	// createwindow함수로 생성해서 가지고 있는다.
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

// 에디트 컨트롤의 텍스트를 ""으로 설정해주면 에디트 컨트롤의 내용이 소멸된다
void CEditControl::ResetControl()
{
	SetWindowText(mHWnd, TEXT(""));
}
// 기존의 함수를 이용해 위치를 다시 잡고 크기또한 다시 셋팅할수 있도록 해준다.
void CEditControl::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}
// 에디트 컨트롤에서 문자열을 가져오는 함수
void CEditControl::GetText(TCHAR* output, int size)
{
	GetWindowText(mHWnd, output, size);
}
// 매개변수인 bool 변수를 통해 보이기 여부를 설정한다.
void CEditControl::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}