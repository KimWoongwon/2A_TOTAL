#include "Global.h"
#include "Character.h"
#include "ItemStore.h"
Character::Character(const char* p_name, const char* p_petname,JOB pjob, ItemFactory* p_factory)
{
	strcpy_s(name, sizeof(name), p_name);
	strcpy_s(pet, sizeof(pet), p_petname);
	Level = 1;
	status = new STATUS(0, 0, 0, 0);
	WeaponStatus = false;
	ArmorStatus = false;
	NowWeapon = p_factory->CreateWeapon();
	NowArmor = p_factory->CreateArmor();
	NowWeapon->OnItem(this);
	NowArmor->OnItem(this);
	itemCount = 0;
	
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
void Character::SetWStatus(bool status)
{
	WeaponStatus = status;
}
void Character::SetAStatus(bool status)
{
	ArmorStatus = status;
}
void Character::SetStatus(STATUS* pSta)
{
	status->Hp = pSta->Hp;
	status->Mp = pSta->Mp;
	status->ATK = pSta->ATK;
	status->DEF = pSta->DEF;
}
void Character::SetWeapon(Item* ptr)
{
	if (ptr == nullptr)
	{
		NowWeapon = nullptr;
		return;
	}
	NowWeapon = dynamic_cast<Weapon*>(ptr);
}
void Character::SetArmor(Item* ptr)
{
	if (ptr == nullptr)
	{
		NowArmor = nullptr;
		return;
	}
	NowArmor = dynamic_cast<Armor*>(ptr);
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
		return "�ΰ�";
	else if (kind == ORC)
		return "��ũ";
	else if (kind == ELF)
		return "����";
}
const char* Character::GetJOB()
{
	if (job == WARRIOR)
		return "����";
	else if (job == HEALER)
		return "����";
	else if (job == ARCHER)
		return "�ü�";
	else if (job == SORCERER)
		return "������";
}
Weapon* Character::GetWeapon()
{
	return NowWeapon;
}
Armor* Character::GetArmor()
{
	return NowArmor;
}
bool Character::GetWStatus()
{
	return WeaponStatus;
}
bool Character::GetAStatus()
{
	return ArmorStatus;
}
void Character::ShowInventroy()
{
	for (int i = 0; i < itemCount; i++)
	{
		if(i == 0)
			cout << "-------------------�κ��丮------------------" << endl;
		else
			cout << "--------------------------------------------" << endl;
		cout << "< " << i + 1 << " >" << endl;
		cout << "\t�̸� : "	<< Inventory[i]->GetName() << endl;
		cout << "\t�з� : "	<< Inventory[i]->GetJobCode() << '/' 
							<< Inventory[i]->GetTypeCode() << endl;
		cout << "\t���� : "	<< Inventory[i]->GetPrice() << endl;
		cout << "\tHP : "	<< Inventory[i]->GetStatus()->Hp << endl;
		cout << "\tMP : "	<< Inventory[i]->GetStatus()->Mp << endl;
		cout << "\tATK : "	<< Inventory[i]->GetStatus()->ATK << endl;
		cout << "\tDEF : "	<< Inventory[i]->GetStatus()->DEF << endl;
	}
	cout << "--------------------------------------------" << endl;
}
void Character::BuyItem(Item* pItem)
{
	Inventory[itemCount++] = pItem;
	return;
}
Item* Character::SellItem()
{
	ShowInventroy();
	if (itemCount == 0)
	{
		cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
		return nullptr;
	}

	int idx;
 	cout << "�Ǹ��� ������ ��ȣ : ";
	cin >> idx;

	Item* temp = nullptr;
	if (idx < 20 && idx > 0)
		temp = Inventory[idx - 1];
	else
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		return nullptr;
	}
		
	Delete(idx);
	

	
	return temp;
	
}
void Character::ChangeItem()
{
	int select = 0;
	cout << "< ���ⱳü �޴� >" << endl;
	cout << "1.���� ����" << endl;
	cout << "2.���� ����" << endl;
	cout << "3.�� ����" << endl;
	cout << "4.�� ����" << endl;
	cout << "���� : ";
	cin >> select;


	int idx = 0;
	Item* temp = nullptr;
	switch (select)
	{
	case 1:
		ShowInventroy();
		cout << "������ ������ ��ȣ : ";
		cin >> idx;
		
		temp = this->GetWeapon();
		Inventory[idx - 1]->OnItem(this);
		this->NowWeapon = dynamic_cast<Weapon*>(Inventory[idx - 1]);
		Delete(idx-1);
		break;
	case 2:
		temp = GetWeapon()->OffItem(this);
		if (temp != nullptr)
			Inventory[itemCount++] = temp;
		break;
	case 3:
		ShowInventroy();
		cout << "������ ������ ��ȣ : ";
		cin >> idx;

		temp = this->GetArmor();
		Inventory[idx - 1]->OnItem(this);
		this->NowWeapon = dynamic_cast<Weapon*>(Inventory[idx - 1]);
		Delete(idx - 1);
		break;
	case 4:
		temp = GetArmor()->OffItem(this);
		if (temp != nullptr)
			Inventory[itemCount++] = temp;
		break;
	}
}
void Character::DeletefromInventory(int idx)
{
	for (int i = idx; i < itemCount; i++)
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
}