#pragma once
#include "../Global.h"
#include "../LinkedList.h"
#include "Weapon.h"
#include "Armor.h"
// ������ ����� State �� ���Ǵ� ������ ���̽�
class ItemDataBase	
{
	DECLARE_SINGLETONE(ItemDataBase)	// �̱��� ���� ����
private:
	CLinkedList<Item*>* ItemList;		// ������ ������ ������ ����Ʈ
	CNode<Item*>* mData;				// �������� �Ѱ��� ȣ��� �Ѱ��� ���
	int ItemListCount;					// ���� �������� �� ����
	ItemDataBase();				
	~ItemDataBase();
public:
	void Initialize();					// �ʱ�ȭ �Լ� : ���Ͽ��� ������ ���� �о����
	bool Input(Item*);					// �÷��̾ �����ۿ� ������ �ǰ�� ������ �������� �־��ִ� �Լ�
	bool Delete(Item*);					// �÷��̾ �������� ���� �ش� �������� �������� �����ֱ� �����Լ�
	bool GetData(Item**);				// ������ ��ü �ϳ��� �ܺη� �����ϱ� ���� �Լ�
	void GetDataEnd();					// ������ ��ü ������ ��ġ���� �ʱ�ȭ �ϴ� �Լ�
	int	 GetCount();					// �ش� ����Ʈ ���� ������ ��ȯ�ϴ� �Լ�
};

