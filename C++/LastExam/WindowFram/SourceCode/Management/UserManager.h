#pragma once

#include "../Global.h"
#include "User.h"

// ������ ����Ʈ�� �����ϴ� �����ͺ��̽��Դϴ�.
// ������ ����Ʈ�� ������ ���� ������ �����Ƿ� �̱��� �������� �����մϴ�.

class CUserManager
{
	DECLARE_SINGLETONE(CUserManager)	// �̱������� ���� ��ũ��
private:
	CLinkedList<CUser*>* mUserList;		// ���� ����Ʈ
	CNode<CUser*>* mData;				// �����͸� �ϳ��� �Ѱ��ٶ� ����ϴ� ���
	int UserListCount;					// ������ �� ��

	CUserManager();						// ������
	~CUserManager();					// �Ҹ���
public:

	void Initialize();					// �ʱ�ȭ �Լ�	: ���Ͽ��� ��������Ʈ ������ �о�ɴϴ�.
	void SaveInfo(CUser*);				// ���� �Լ�		: ���Ͽ� ��������Ʈ�� �����մϴ�.
	bool Input(CUser*);					// ��������Ʈ�� ������ �߰��մϴ�.
	bool Delete(CUser*);				// ��������Ʈ���� ������ �����մϴ�.
	bool GetData(CUser**);				// �ܺο��� ������ �Ѱ��� �Ѱ��ٶ� ����մϴ�.
	void GetDataEnd();					// �ܺο��� �Ѱ��� �Ѱ��ְ� ���� �� �Լ��� ���� ��ġ�� �ʱ�� �ǵ����ϴ�.
	int	 GetCount();					// ������ ���� ��ȯ�մϴ�.
	
};

