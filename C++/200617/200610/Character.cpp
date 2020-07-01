#include "Global.h"
#include "Character.h"
Character::Character(const char* p_name, const char* p_petname,JOB pjob, ItemFactory* p_factory)
{
	strcpy_s(name, sizeof(name), p_name);
	strcpy_s(pet, sizeof(pet), p_petname);
	Level = 1;
	status = new STATUS(10, 5, 20, 3);
	/*blacksmith = p_factory;
	weapon = blacksmith->CreateWeapon();
	armor = blacksmith->CreateArmor();*/
	NowWeapon = p_factory->CreateWeapon();
	NowArmor = p_factory->CreateArmor();
	itemCount = 0;
	Inventory[itemCount++] = p_factory->CreateWeapon();
	Inventory[itemCount++] = p_factory->CreateArmor();
	job = pjob;
}
Character::~Character()
{
	delete status;
}
void Character::SetName(const char* p_name)
{
	strcpy_s(name, sizeof(name), p_name);
}
const char* Character::GetName()
{
	return name;
}
int Character::GetLevel()
{
	return Level;
}
STATUS* Character::GetStatus()
{
	return status;
}
const char* Character::GetPetkind()
{
	return pet;
}
const char* Character::GetKind()
{
	if (kind == HUM)
		return "인간";
	else if (kind == ORC)
		return "오크";
	else if (kind == ELF)
		return "엘프";
}
const char* Character::GetJOB()
{
	if (job == WARRIOR)
		return "전사";
	else if (job == HEALER)
		return "사제";
	else if (job == ARCHER)
		return "궁수";
	else if (job == SORCERER)
		return "마법사";
}
Weapon* Character::GetWeapon()
{
	return NowWeapon;
}
Armor* Character::GetArmor()
{
	return NowArmor;
}

void Character::ShowInventroy()
{
	for (int i = 0; i < itemCount; i++)
	{
		cout << "-------------------------------------" << endl;
		cout << "\t이름 : "	<< Inventory[i]->GetName() << endl;
		cout << "\t분류 : "	<< Inventory[i]->GetJobCode() << '/' 
							<< Inventory[i]->GetTypeCode() << endl;
		cout << "\t가격 : "	<< Inventory[i]->GetPrice() << endl;
		cout << "\tHP : "	<< Inventory[i]->GetStatus()->Hp << endl;
		cout << "\tMP : "	<< Inventory[i]->GetStatus()->Mp << endl;
		cout << "\tATK : "	<< Inventory[i]->GetStatus()->ATK << endl;
		cout << "\tDEF : "	<< Inventory[i]->GetStatus()->DEF << endl;
	}
	cout << "-------------------------------------" << endl;
}
void Character::BuyItem(Item* pItem)
{
	Inventory[itemCount++] = pItem;
	return;
}
Item* Character::SellItem()
{
	ShowInventroy();

	char tempname[20];
	cout << "판매할 아이템 이름 : ";
	cin >> tempname;

	Item* temp = nullptr;
	int count = 0;
	for (int i = 0; i < itemCount; i++)
	{
		if (!strcmp(Inventory[i]->GetName(), tempname))
		{
			temp = Inventory[i];
			count = i;
			break;
		}
	}

	for (int i = count; i < itemCount; i++)
	{
		if (Inventory[i + 1] != nullptr)
		{
			Inventory[i] = Inventory[i + 1];
		}
		else
		{
			Inventory[i] = nullptr;
		}
	}

	itemCount--;
	return temp;
}