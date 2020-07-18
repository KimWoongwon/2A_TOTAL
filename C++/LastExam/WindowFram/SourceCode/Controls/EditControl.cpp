#include "EditControl.h"
#include "../Windows/WindowFrame.h"

// ��Ʈ�� Ŭ���� ������
CEditControl::CEditControl(int x, int y, int width, int height, int id)
{
	// createwindow�Լ��� �����ؼ� ������ �ִ´�.
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

// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� ""���� �������ָ� ����Ʈ ��Ʈ���� ������ �Ҹ�ȴ�
void CEditControl::ResetControl()
{
	SetWindowText(mHWnd, TEXT(""));
}
// ������ �Լ��� �̿��� ��ġ�� �ٽ� ��� ũ����� �ٽ� �����Ҽ� �ֵ��� ���ش�.
void CEditControl::SetPosition(int x, int y, int width, int height)
{
	SetWindowPos(mHWnd, NULL, x, y, width, height, FALSE);
}
// ����Ʈ ��Ʈ�ѿ��� ���ڿ��� �������� �Լ�
void CEditControl::GetText(TCHAR* output, int size)
{
	GetWindowText(mHWnd, output, size);
}
// �Ű������� bool ������ ���� ���̱� ���θ� �����Ѵ�.
void CEditControl::SetVisable(bool flag)
{
	if (!flag)
		ShowWindow(mHWnd, SW_HIDE);
	else
		ShowWindow(mHWnd, SW_SHOW);
}