#pragma once
#include "GameState.h"

// ������ �Ǹ� ȭ�� ��ü
class CSellState :public CGameState
{

public:
	CSellState(CLoginSystem* _game);		// ������
	~CSellState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);		// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
};

