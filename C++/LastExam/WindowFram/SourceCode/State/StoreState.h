#pragma once
#include "GameState.h"

// ������ ���� �޴� ȭ�� ��ü
class CStoreState :public CGameState
{	

public:
	CStoreState(CLoginSystem* _game);		// ������
	~CStoreState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);		// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�
		
};

