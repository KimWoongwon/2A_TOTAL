#pragma once
#include "../Global.h"

// ������ ������ EditControl�� ������ Ŭ����
class CEditControl
{
	HWND	mHWnd;	// �ش� �������� �ڵ鰪

public:
	CEditControl(int, int, int, int, int);	// ������ ���ʴ�� x��ǥ, y��ǥ, �ʺ�, ����, ID��
	~CEditControl();

	HWND GetHandle();						// ������ �ڵ� �б� ������

	void ResetControl();					// ����Ʈ ��Ʈ�� ���� �ؽ�Ʈ �ʱ�ȭ �Լ�
	void SetPosition(int, int, int, int);	// ��ġ �� ũ�� �缳�� �Լ�
	void GetText(TCHAR*, int);				// ����Ʈ ��Ʈ�ѿ� �Էµ� �ؽ�Ʈ �������� �Լ�
	void SetVisable(bool);					// ���̱� ���� ������ ���� �Լ�
};

