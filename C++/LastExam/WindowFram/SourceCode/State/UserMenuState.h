#pragma once
#include "GameState.h"

// �����޴� ���� ȭ�� ��ü
class CUserMenuState :	public CGameState
{
public:
	CUserMenuState(CLoginSystem*);			// ������
	~CUserMenuState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);		// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
};

