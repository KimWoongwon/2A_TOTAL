#pragma once
#include "../Global.h"

// ���� ��ư ���� Ŭ����
class CRadioButton
{
	HWND	mHWnd;		// ���� ��ư�� �ڵ鰪

public:
	CRadioButton(TCHAR*,int, int, int, int, int, bool); // ������ ���ʴ�� ������ư ĸ��, x,y��ǥ, �ʺ�, ����, ID��, �׷쿩��
	~CRadioButton();

	HWND GetHandle();									// �ڵ� �б� ������
	bool GetCheckInfo();								// üũ ����� ���� ��ȯ �Լ�
														
	void SetPosition(int, int, int, int);				// ��ġ �� ũ�� �缳�� �Լ�
	void SetCaption(TCHAR*);							// ��ư ���� �۾� �缳�� �Լ�
	void SetVisable(bool);								// ���̱� ���� ���� �Լ�
};
