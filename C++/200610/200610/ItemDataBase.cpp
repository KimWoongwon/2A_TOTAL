#include "ItemDataBase.h"
IMPLEMENT_SINGLETON(ItemDataBase)
ItemDataBase::ItemDataBase()
{
	ItemList = new CLinkedList<Item*>;
}
ItemDataBase::~ItemDataBase()
{
	delete ItemList;
}
void ItemDataBase::Initialize()
{
	ItemList->Insert(new Weapon("강철 두손검", new STATUS(0, 0, 100, 0), 1500, CODE_WARRIOR));
	ItemListCount++;
	ItemList->Insert(new Armor("여신의 가호를 받은 로브", new STATUS(200, 500, 0, 50), 5000, CODE_SORCERER));
	ItemListCount++;
	ItemList->Insert(new Weapon("금으로 수놓은 기사의 두손검", new STATUS(0, 0, 150, 50), 3000, CODE_WARRIOR));
	ItemListCount++;
	ItemList->Insert(new Armor("금으로 수놓은 기사의 플레이트 갑옷", new STATUS(1000, 100, 0, 100), 15000, CODE_WARRIOR));
	ItemListCount++;
	
}
bool ItemDataBase::Input(Item* item)
{
	ItemListCount++;
	ItemList->Insert(item);
	
	return true;
}

bool ItemDataBase::Delete(Item* item)
{
	bool result = false;

	result = ItemList->Delete(item);
	if (result)
	{
		ItemListCount--;
	}

	return result;
}

bool ItemDataBase::GetData(Item** _stu)
{

	if (!mData)
	{
		mData = ItemList->GetmHead()->GetmNext();
	}
	else
	{
		mData = mData->GetmNext();
	}

	if (mData)
	{
		*_stu = mData->GetmData();
		return true;
	}

	return false;
}

void ItemDataBase::GetDataEnd()
{
	mData = nullptr;
}

int	 ItemDataBase::GetCount()
{
	return ItemListCount;
}