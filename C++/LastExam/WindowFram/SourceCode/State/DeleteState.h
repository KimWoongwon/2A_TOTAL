#pragma once
#include "GameState.h"

// ĳ���� ���� ����
class CDeleteState :public CGameState
{

public:
	CDeleteState(CLoginSystem* _game);		// ������
	~CDeleteState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);		// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
};

