#pragma once
#include "GameState.h"

// ȸ������ ȭ�� ��ü
class CSignupState : public CGameState
{

public:
	CSignupState(CLoginSystem* _game);		// ������
	~CSignupState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);		// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
};

