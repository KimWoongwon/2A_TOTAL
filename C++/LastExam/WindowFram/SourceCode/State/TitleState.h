#pragma once
#include "GameState.h"

// Ÿ��Ʋ ȭ�� ��ü
class CTitleState :	public CGameState
{

public:
	CTitleState(CLoginSystem* _game);	// ������
	~CTitleState();

	virtual void InitializeProcess();	// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);	// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
};

