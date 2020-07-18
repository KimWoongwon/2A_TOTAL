#ifndef CUSER_H
#define CUSER_H

#include "../Global.h"
#include "CharacterManager.h"

// ���� Ŭ����
class CUser
{
private:
	char mId[10];						// ������ ���̵�
	char mPw[10];						// ������ ��й�ȣ
	
	CCharacterManager* CharList;		// ������ ������ ĳ���� ����Ʈ
	bool mLoginState;					// ������ �α��� ����

	int money;							// ������ �� ����

public:
	CUser(const char*, const char*);	// ������ 
	~CUser();

	const char* GetId();				// ���̵� �б� ������
	const char* GetPw();				// ��й�ȣ �б� ������
	int GetMoney();						// �� �б� ������
	void SetMoney(int);					// �� ���� ������
	bool  GetLoginState();				// �α��� ���� �б� ������
	Character* GetChar(const char*);	// �Ű������� ���� ���ڿ��� �´� ĳ���͸� ã�� ��ȯ�ϴ� �Լ�
	CCharacterManager* GetCharList();	// ĳ���� ����Ʈ �б� ������
	int GetCount();						// ĳ���� ����Ʈ ������ ĳ���� ���� ��ȯ �Լ�

	void SetLogin();					// ������ �α��λ��� ���� �Լ�
	void SetLogout();
	
	void InsertCharacter(Character*);	// ĳ���� ���� �Լ�
	bool RemoveCharacter(const char*);	// ĳ���� ����Ʈ���� �Ű������� ���� ���ڿ��� �ش��ϴ� ĳ���� ���� �Լ�
};

#endif