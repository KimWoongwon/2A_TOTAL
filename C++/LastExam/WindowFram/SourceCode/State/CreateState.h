#pragma once
#include "GameState.h"

// ĳ���� ���� ������Ʈ Ŭ����
class CCreateState :public CGameState
{
public:
	CCreateState(CLoginSystem* _game);	// ������
	~CCreateState();

	virtual void InitializeProcess();	// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);	// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
};



