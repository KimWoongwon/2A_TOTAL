#pragma once
#include "../Global.h"

class Character;

// ������ Ŭ����
class Item
{
private:
	char ItemName[50];	// �������� �̸�
	STATUS* status;		// ������ ����� ���ʽ� ���� ��ġ
	int price;			// ����
	CLASS ClassCode;	// ������ ���� ���� ����
	ITEMTYPE TypeCode;	// �������� �з� (����, ��)
public:
	Item(const char*, STATUS*, int, CLASS, ITEMTYPE);	// ������
	Item(Item& item);									// ���� ������
	~Item();

	char* GetName();									// �̸� �б� ������
	STATUS* GetStatus();								// ���� �б� ������
	int GetPrice();										// ���� �б� ������
	CLASS GetClassCode();								// Ŭ���� �ڵ� ��ȯ �Լ�
	ITEMTYPE GetTypeCode();								// �з� �ڵ� ��ȯ�Լ�

	virtual void OnItem(Character*);					// ������ ���� ���� �Լ�
	virtual void OffItem(Character*);					// ������ ���� ���� �Լ�
};

