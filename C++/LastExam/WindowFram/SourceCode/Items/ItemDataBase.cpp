#include "ItemDataBase.h"
IMPLEMENT_SINGLETON(ItemDataBase)
ItemDataBase::ItemDataBase()
{
	ItemList = new CLinkedList<Item*>;
	mData = nullptr;
	ItemListCount = 0;
}
ItemDataBase::~ItemDataBase()
{
	delete ItemList;
}
void ItemDataBase::Initialize()
{
	ifstream File;
	File.open("ItemStoreDataBase.txt", ios::app);

	TCHAR temparr[500];
	char* name;
	int price, hp, mp, atk, def;
	CLASS Class;
	ITEMTYPE type;

	Item* tempitem = nullptr;
	CLASS cls;
	if (File.is_open())
	{
		//File.getline(temparr, 256);
		while (!File.eof())
		{
			File.getline(temparr, 500);
			if (!strcmp(temparr, ""))
				break;

			name = strtok(temparr, "|");
			hp = atoi(strtok(NULL, "|"));
			mp = atoi(strtok(NULL, "|"));
			atk = atoi(strtok(NULL, "|"));
			def = atoi(strtok(NULL, "|"));
			price = atoi(strtok(NULL, "|"));
			Class = (CLASS)atoi(strtok(NULL, "|"));
			type = (ITEMTYPE)atoi(strtok(NULL, "|"));

			if (type == ITEMTYPE::WEAPONE)
				tempitem = new Weapon(name, new STATUS(hp, mp, atk, def), price, Class);
			else if(type == ITEMTYPE::ARMOR)
				tempitem = new Armor(name, new STATUS(hp, mp, atk, def), price, Class);
			ItemList->Insert(tempitem);
			ItemListCount++;
		}
	}

	File.close();
}

bool ItemDataBase::Input(Item* item)
{
	ItemList->Insert(item);
	ItemListCount++;
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