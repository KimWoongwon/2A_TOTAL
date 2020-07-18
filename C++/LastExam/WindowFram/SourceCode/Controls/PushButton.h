#pragma once

#include "../Global.h"

// Ǫ����ư ���� Ŭ����
class CPushButton
{
	HWND	mHWnd;	// Ǫ����ư�� �ڵ鰪

public:
	CPushButton(int, int, int, int, int);	// ������ ���ʴ�� x,y��ǥ, �ʺ�, ����, ID��
	~CPushButton();

	HWND GetHandle();						// �ڵ� �б� ������
	void SetPosition(int, int, int, int);	// ��ġ �� ũ�� �缳�� �Լ�
	void SetCaption(TCHAR*);				// ��ư ���� �۾� �缳�� �Լ�
	void SetVisable(bool);					// ���̱� ���� ���� �Լ�
};

