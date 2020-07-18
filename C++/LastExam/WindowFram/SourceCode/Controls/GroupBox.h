#pragma once
#include "../Global.h"

// ������ ������ GroupBox�� ������ Ŭ����
class CGroupBox
{
	HWND	mHWnd;		// ������ �ڵ鰪

public:
	CGroupBox(TCHAR*, int, int, int, int, int);		// ������ ���ʴ�� �׷�ڽ��� �ؽ�Ʈ, x,y��ǥ��, �ʺ�, ����, ID��
	~CGroupBox();

	HWND GetHandle();								// ������ �ڵ� �б� ������
	void SetPosition(int, int, int, int);			// ��ġ �� ũ�� �缳�� �Լ�
	void SetVisable(bool);							// ���̱� ���� ���� �Լ�
};

