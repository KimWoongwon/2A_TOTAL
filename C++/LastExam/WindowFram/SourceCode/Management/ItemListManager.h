#pragma once

#include "../Global.h"
#include "../Items/Item.h"
#include "../LinkedList.h"

// ĳ������ ������ ����Ʈ : �κ��丮
class CItemListManager
{
private:
	char CharacterName[20];			// ���� ��ü�� ������ �������� �Ǻ��� ���� ����
	CLinkedList<Item*>* mItemList;	// ĳ������ ������ ����Ʈ : �κ��丮
	CNode<Item*>* mData;			// �ܺο��� �˻��� ����Ʈ�� ������ �Ѱ��ִ� �Լ�

	int ItemListCount;				// ����Ʈ ���� �������� �� ����
public:		
	CItemListManager(const char*); // ������ �Ű������δ� ���� �÷��̾ ������ �����ϱ� ���� �Լ�
	~CItemListManager();

	void Initialize(Item**, Item**);	// �ʱ�ȭ �Լ� �������� �κ��丮 ������ ��� ����Ʈ�� ���Ͽ��� ���� �ҷ��� �ʱ�ȭ
	void SaveInfo();					// �������� ���� �Ǹŵ��� ������ ���� ������ ���Ͽ� �����ϱ� ���� �Լ�
	void SaveNowInfo(Item*,Item*);		// ���������� ���Ͽ� ������� �Լ�

	bool Input(Item*);					// ������ �߰� �Լ�
	bool Delete(Item*);					// �ش� ������ ���� �Լ�
	bool GetData(Item**);				// �ܺο��� �������� �ϳ��� �Ѱ��ִ� �Լ�
	void GetDataEnd();					// �ܺο��� �˻��� �˻� ��ġ�� �ʱ�ȭ �Լ�
	int	 GetCount();					// �ܺο��� �˻��� ����Ʈ�� ������ üũ�ϱ� ���� �Լ�


};