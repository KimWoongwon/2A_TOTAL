#pragma once
#include "../Global.h"

// ����ƽ �ؽ�Ʈ ���� Ŭ����

class CStaticText
{
	HWND	mHWnd;			// ����ƽ �ؽ�Ʈ�� �ڵ鰪

public:
	CStaticText(int, int, int, int, int, TCHAR*);	// ������ ���ʴ�� x,y��ǥ, �ʺ�, ����, ID��, 
	~CStaticText();

	HWND GetHandle();								// �ڵ� �б� ������
	void ResetControl();							// ���� �۾� �ʱ�ȭ �Լ�
	void SetText(TCHAR*);							// ���� �۾� �缳�� �Լ�
	void SetAlignment(Alignment);					// ���� ���� �缳�� �Լ�
	void SetPosition(int, int, int, int);			// ��ġ �� ũ�� �缳�� �Լ�
	void SetVisable(bool);							// ���̱� ���� ���� �Լ�
};

