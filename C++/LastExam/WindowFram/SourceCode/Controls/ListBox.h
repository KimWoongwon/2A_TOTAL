#pragma once
#include "../Global.h"

// ListVeiw ���� Ŭ����
class CListBox
{
	HWND	mHWnd;	// ����Ʈ���� �ڵ鰪
public:
	CListBox(int, int, int, int, int);		// ������ ���ʴ�� x,y��ǥ, �ʺ�, ����, ID��
	~CListBox();			
	
	HWND GetHandle();						// �ڵ� �б� ������
	void SetPosition(int, int, int, int);	// ��ġ �� ũ�� �缳�� �Լ�
	void SetVisable(bool);					// ���̱� ���� ���� �Լ�
};