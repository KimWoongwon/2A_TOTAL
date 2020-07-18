#include "ItemListManager.h"
#include "../Items/Weapon.h"
#include "../Items/Armor.h"

CItemListManager::CItemListManager(const char* name)
{
	strcpy_s(CharacterName, sizeof(CharacterName), name);
	mItemList = new CLinkedList<Item*>;
	mData = nullptr;
	ItemListCount = 0;
}
CItemListManager::~CItemListManager()
{
	SaveInfo();
	delete mItemList;
}
void CItemListManager::Initialize(Item** weapon, Item** armor)
{
	ifstream File;
	char filestr[100];
	wsprintf(filestr, "CharacterItems_%s.txt", CharacterName);
	File.open(filestr, ios::app);

	TCHAR tempstr[200];
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
			File.getline(tempstr, 500);
			if (!strcmp(tempstr, ""))
				break;

			name = strtok(tempstr, "|");
			if (!strcmp(name, "Âø¿ë¹«±â"))
			{
				name = strtok(NULL, "|");
				hp = atoi(strtok(NULL, "|"));
				mp = atoi(strtok(NULL, "|"));
				atk = atoi(strtok(NULL, "|"));
				def = atoi(strtok(NULL, "|"));
				price = atoi(strtok(NULL, "|"));
				Class = (CLASS)atoi(strtok(NULL, "|"));
				type = (ITEMTYPE)atoi(strtok(NULL, "|"));
				*weapon = new Weapon(name, new STATUS(hp, mp, atk, def), price, Class);
			}
			else if (!strcmp(name, "Âø¿ë¹æ¾î±¸"))
			{
				name = strtok(NULL, "|");
				hp = atoi(strtok(NULL, "|"));
				mp = atoi(strtok(NULL, "|"));
				atk = atoi(strtok(NULL, "|"));
				def = atoi(strtok(NULL, "|"));
				price = atoi(strtok(NULL, "|"));
				Class = (CLASS)atoi(strtok(NULL, "|"));
				type = (ITEMTYPE)atoi(strtok(NULL, "|"));
				*armor = new Armor(name, new STATUS(hp, mp, atk, def), price, Class);
			}
			else
			{
				hp = atoi(strtok(NULL, "|"));
				mp = atoi(strtok(NULL, "|"));
				atk = atoi(strtok(NULL, "|"));
				def = atoi(strtok(NULL, "|"));
				price = atoi(strtok(NULL, "|"));
				Class = (CLASS)atoi(strtok(NULL, "|"));
				type = (ITEMTYPE)atoi(strtok(NULL, "|"));

				if (type == ITEMTYPE::WEAPONE)
					tempitem = new Weapon(name, new STATUS(hp, mp, atk, def), price, Class);
				else if (type == ITEMTYPE::ARMOR)
					tempitem = new Armor(name, new STATUS(hp, mp, atk, def), price, Class);
				mItemList->Insert(tempitem);
				ItemListCount++;
			}
			
		}
	}

	File.close();

}
void CItemListManager::SaveInfo()
{
	ofstream File;
	char filestr[100];
	wsprintf(filestr, "CharacterItems_%s.txt", CharacterName);
	
	File.open(filestr, ios::app);
	string temp;

	CNode<Item*>* ptr = mItemList->GetmHead();
	Item* item;
	char str[100];
	if (File.is_open())
	{
		do
		{
			ptr = ptr->GetmNext();
			if (ptr->GetmData() == nullptr)
				break;
			item = ptr->GetmData();
			temp += item->GetName();
			temp += "|";
			_itoa_s(item->GetStatus()->Hp, str, 10);
			temp += str;
			temp += "|";
			_itoa_s(item->GetStatus()->Mp, str, 10);
			temp += str;
			temp += "|";
			_itoa_s(item->GetStatus()->ATK, str, 10);
			temp += str;
			temp += "|";
			_itoa_s(item->GetStatus()->DEF, str, 10);
			temp += str;
			temp += "|";
			_itoa_s(item->GetPrice(), str, 10);
			temp += str;
			temp += "|";
			_itoa_s((int)item->GetClassCode(), str, 10);
			temp += str;
			temp += "|";
			_itoa_s((int)item->GetTypeCode(), str, 10);
			temp += str;
			temp += "|";
			temp += "\n";

			File.write(temp.c_str(), temp.size());
			temp = "";

		} while (ptr->GetmNext() != NULL);
	}

	File.close();
}

void CItemListManager::SaveNowInfo(Item* weapon, Item* armor)
{
	ofstream File;
	char filestr[100];
	wsprintf(filestr, "CharacterItems_%s.txt", CharacterName);

	File.open(filestr);
	File.clear();
	string temp;

	char str[100];
	temp += "Âø¿ë¹«±â|";
	temp += weapon->GetName();
	temp += "|";
	_itoa_s(weapon->GetStatus()->Hp, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(weapon->GetStatus()->Mp, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(weapon->GetStatus()->ATK, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(weapon->GetStatus()->DEF, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(weapon->GetPrice(), str, 10);
	temp += str;
	temp += "|";
	_itoa_s((int)weapon->GetClassCode(), str, 10);
	temp += str;
	temp += "|";
	_itoa_s((int)weapon->GetTypeCode(), str, 10);
	temp += str;
	temp += "|";
	temp += "\n";

	File.write(temp.c_str(), temp.size());
	temp = "";

	temp += "Âø¿ë¹æ¾î±¸|";
	temp += armor->GetName();
	temp += "|";
	_itoa_s(armor->GetStatus()->Hp, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(armor->GetStatus()->Mp, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(armor->GetStatus()->ATK, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(armor->GetStatus()->DEF, str, 10);
	temp += str;
	temp += "|";
	_itoa_s(armor->GetPrice(), str, 10);
	temp += str;
	temp += "|";
	_itoa_s((int)armor->GetClassCode(), str, 10);
	temp += str;
	temp += "|";
	_itoa_s((int)armor->GetTypeCode(), str, 10);
	temp += str;
	temp += "|";
	temp += "\n";

	File.write(temp.c_str(), temp.size());
	temp = "";
}

bool CItemListManager::Input(Item* data)
{
	mItemList->Insert(data);
	ItemListCount++;
	return true;
}

bool CItemListManager::Delete(Item* data)
{
	bool result = false;

	result = mItemList->Delete(data);
	if (result)
		ItemListCount--;

	return result;
}

bool CItemListManager::GetData(Item** _item)
{

	if (!mData)
	{
		mData = mItemList->GetmHead()->GetmNext();
	}
	else
	{
		mData = mData->GetmNext();
	}

	if (mData)
	{
		*_item = mData->GetmData();
		return true;
	}

	return false;
}

void CItemListManager::GetDataEnd()
{
	mData = nullptr;
}

int	 CItemListManager::GetCount()
{
	return ItemListCount;
}

