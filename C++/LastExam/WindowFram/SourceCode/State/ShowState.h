#pragma once
#include "GameState.h"

// �κ��丮 ���ȭ�� ��ü
class CShowState : public CGameState
{
public:
	CShowState(CLoginSystem* _game);		// ������
	~CShowState();

	virtual void InitializeProcess();		// ȭ�� ��ȯ�� �ʱ�ȭ�� ���� �Լ�
	virtual void ButtonProcess(WPARAM);		// � ��ư Ŭ���� �ش� �̺�Ʈ ó�� �Լ�

};

