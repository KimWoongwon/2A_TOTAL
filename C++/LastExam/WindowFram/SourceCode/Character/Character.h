#pragma once
#include "../Global.h"
#include "../Management/ItemListManager.h"
#include "../Items/Factorys/ItemFactory.h"

class Character
{
protected:
	char name[20];									// ĳ������ �̸�
	int Level;										// ĳ������ ����
	STATUS* status;									// ĳ���� ���ݼ�ġ

	REGION		region;								// ĳ���� ����
	CLASS		cls;								// ĳ���� ����

	Weapon*		NowWeapon;							// ���� �������� ����
	Armor*		NowArmor;							// ���� �������� ��

	CItemListManager* Inventory;					// �κ��丮	:	������ ����Ʈ�� �����ϴ� �Ŵ�����ü�Դϴ�.
public:
	Character(const char*, CLASS, ItemFactory*);	// ������
	virtual ~Character();							// �Ҹ���

	char* GetName();								// ĳ���� �г��� �б� ������
	char* GetRegion();								// ĳ���� �����ڵ带 ���ڿ��� ��ȯ�� ��ȯ�ϴ� �Լ�
	char* GetClass();								// ĳ���� �����ڵ带 ���ڿ��� ��ȯ�� ��ȯ�ϴ� �Լ�
	CLASS GetClassType();							// ĳ���� ���� �ڵ� �б� ������

	STATUS* GetStatus();							// ĳ������ ���� �б� ������
	CItemListManager* GetInventory();				// ĳ������ �κ��丮 �б� ������

	Weapon* GetWeapon();							// ĳ������ ���� ���� �б� ������
	Armor* GetArmor();								// ĳ������ ���� �� �б� ������

	bool OnItem(Item*);								// �Ű������� ���� �������� �������� ������ �����ϰ� �ش� �������� OnItem �Լ� ȣ��
	bool OffItem(Item*);							// �Ű������� ���� �������� �������� ������ �����ϰ� ���� �������� OffItem �Լ� ȣ��

	void BuyItem(Item*);							// �������� �� �������� �Ű������� �޾� �κ��丮�� �־��ִ� �Լ�
	Item* SellItem(char*);							// �κ��丮���� �Ű������� ���� �������̸�(���ڿ�)�� ���� ã�Ƽ� ������ �ȱ����� �Ѱ��ִ� �Լ�

	virtual void SetHp() = 0;						// �����Լ� ��� : Elf, Orc, Human ���� �ʱ� ������ �ٸ��� �����ϱ� ���� �����Լ�ȭ
	virtual void SetMp() = 0;
	virtual void SetATK() = 0;
	virtual void SetDEF() = 0;
	

};

