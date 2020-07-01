#pragma once
#include "Global.h"
#include "LinkedList.h"
#include "Weapon.h"
#include "Armor.h"
class ItemDataBase
{
	DECLARE_SINGLETONE(ItemDataBase)
private:
	CLinkedList<Item*>* ItemList;
	CNode<Item*>* mData;
	int ItemListCount;
	ItemDataBase();
	~ItemDataBase();
public:
	void Initialize();
	bool Input(Item*);
	bool Delete(Item*);
	bool GetData(Item**);
	void GetDataEnd();
	int	 GetCount();
};

