#pragma once
#include "GameState.h"

// ������ ���� state 
class CBuyState :public CGameState
{
public:
	CBuyState(CLoginSystem* _game);		
	~CBuyState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� ȣ��� �ʱ�ȭ �Լ�
	virtual void ButtonProcess(WPARAM);		// ���� ��ư Ŭ���� �̺�Ʈ �޽��� ó�� �Լ�
};
