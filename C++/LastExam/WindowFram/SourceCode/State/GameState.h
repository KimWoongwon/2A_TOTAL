#pragma once
#include "../Global.h"

//������� �浹�� ���� �ӽ� ������ Ŭ����
class CLoginSystem;

// ������Ʈ ������ ������ ���� ������ Ŭ����
class CGameState
{
private:
	CLoginSystem*    mSystem;	// STATE ������ �ְ��� ���� Ŭ����
public:
	CGameState(CLoginSystem* );
	~CGameState();

	CLoginSystem* GetSystem();	// �� ������Ʈ������ �����Ҽ� �ֵ��� ������ ����
	virtual void InitializeProcess() = 0;	// �ʱ�ȭ �����Լ�
	virtual void ButtonProcess(WPARAM) = 0;	// ��ưŬ���� ȣ��� �����Լ�

};

