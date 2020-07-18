#include "../Global.h"
#include "Character.h"
// ĳ���� ������
Character::Character(const char* p_name,CLASS pjob, ItemFactory* p_factory)
{
	strcpy_s(name, sizeof(name), p_name);
	Level = 1;
	status = new STATUS(10, 5, 20, 3);
	NowWeapon = p_factory->CreateWeapon();
	NowArmor = p_factory->CreateArmor();
	cls = pjob;
	Inventory = new CItemListManager(p_name);
	// �̴ϼȶ����� �Լ����� ���������� �ҷ��ö� ���Ͽ� ���� ���������� �����ֱ⶧���� �ش� ���� �������ش�.
	Inventory->Initialize((Item**)&NowWeapon, (Item**)&NowArmor);	
}

Character::~Character()
{
	// ĳ���͸� �����ϱ� �� ���� �������� ����� ������ ���� ���Ͽ� ���� �׵ڿ� �κ��丮�� �����Ǹ鼭
	// �κ��丮�� ������������ ���Ͽ� ����Ѵ�.
	Inventory->SaveNowInfo(dynamic_cast<Item*>(NowWeapon),dynamic_cast<Item*>(NowArmor));
	OffItem(NowWeapon);
	OffItem(NowArmor);
	
	delete Inventory;
	delete status;
}
// ĳ���� �̸� ��ȯ �Լ�
char* Character::GetName()	
{
	return name;
}
// ���Ͽ� ����� ���ڿ� ���·� �����ϱ� ���ؼ� ��ȯ�ؼ� ��ȯ���ִ� �Լ�
char* Character::GetRegion()	
{
	if (region == REGION::HUM)
		return "�ΰ�";
	else if (region == REGION::ORC)
		return "��ũ";
	else if (region == REGION::ELF)
		return "����";
}
// ���Ͽ� ����� ���ڿ� ���·� �����ϱ� ���ؼ� ��ȯ�ؼ� ��ȯ���ִ� �Լ�
char* Character::GetClass()		
{
	if (cls == CLASS::WARRIOR)
		return "����";
	else if (cls == CLASS::ARCHER)
		return "�ü�";
	else if (cls == CLASS::SORCERER)
		return "������";
}
// ���� �񱳽ÿ� �ڵ尡 ���������� �ʿ��ϱ� ������ ������ ��ȯ�Լ�
CLASS Character::GetClassType()	
{
	return cls;
}
// ������ ���� �� �����ÿ� ���� ������ ���� ��ȯ�Լ�
STATUS* Character::GetStatus()	
{
	return status;
}
// �������� ��� �Ȱ� ����, ����, �������� �ϱ� ���� �κ��丮 ��ȯ���ִ� �Լ�
CItemListManager* Character::GetInventory()	
{
	return Inventory;
}
// ���� ������ ���⸦ ��ȯ���ִ� �Լ�
Weapon* Character::GetWeapon()
{
	return NowWeapon;
}
// ���� ������ ���� ��ȯ���ִ� �Լ�
Armor* Character::GetArmor()
{
	return NowArmor;
}
// ĳ���� �������� �����ϴ� �Լ�
bool Character::OnItem(Item* _item)
{
	// �Ѱܿ� �������� �����ΰ��
	if (_item->GetTypeCode() == ITEMTYPE::WEAPONE)	
	{
		// ���� �������� �������� ����� �ϱ⶧���� ������ �������ش�.
		if (NowWeapon != nullptr)
			return false;
		// �޾ƿ� �������� ������ ���������� �������ص�
		NowWeapon = dynamic_cast<Weapon*>(_item);
	}

	if (_item->GetTypeCode() == ITEMTYPE::ARMOR)
	{
		if (NowArmor != nullptr)
			return false;
		NowArmor = dynamic_cast<Armor*>(_item);
	}
	// ������ �����ؼ� ������ �����Ѵ�.
	_item->OnItem(this);
	
}
// ĳ������ �������� ���� �����ϴ� �Լ�
bool Character::OffItem(Item* _item)
{
	// �Ѱܿ� �������� ���⳪ ���� ��츦 ���� ������.
	if (_item->GetTypeCode() == ITEMTYPE::WEAPONE)
	{
		// ������ �������� ������� ������ ���� �ȵǱ⶧���� ������ �������ش�.
		if (NowWeapon == nullptr)
			return false;
		// ���� ������ �����ϰ� ���� ���� �������� ���ٰ� �������ش�.
		_item->OffItem(this);
		NowWeapon = nullptr;
		return true;
	}

	if (_item->GetTypeCode() == ITEMTYPE::ARMOR)
	{
		if (NowArmor == nullptr)
			return false;
		_item->OffItem(this);
		NowArmor = nullptr;
		return true;
	}
}

// �������� ���������� �κ��丮�� �������� �����ϱ� ���� �Լ�
void Character::BuyItem(Item* pItem)
{
	// �ܺο��� ���õ� �������� �κ��丮�� �־��ֱ⸸ �Ѵ�.
	Inventory->Input(pItem);
	return;
}

// �������� �Ǹ��Ҷ� �κ��丮���� �ش� �̸��� �������� ã�Ƽ� ��ȯ���ش�.
Item* Character::SellItem(char* _str)
{
	// �������� ã�� �κ�
	Item* temp = nullptr;
	int count = Inventory->GetCount();
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (Inventory->GetData(&temp))
		{
			if (!strcmp(temp->GetName(), _str))
			{
				flag = true;
				break;
			}
		}
		
	}

	Inventory->GetDataEnd();
	
	// �κ��丮���� �ش�������� �ٷ� �����ϸ� �ܺο��� ������ ������� ������
	Item* item = nullptr;
	if (flag)
	{
		// ��������ڸ� �̿��ؼ� �������� �Ȱ��� ��ü�� ����� �ش��� ��ȯ�Ѵ�.
		if (temp->GetTypeCode() == ITEMTYPE::WEAPONE)
			item = new Weapon(*dynamic_cast<Weapon*>(temp));
		else if (temp->GetTypeCode() == ITEMTYPE::ARMOR)
			item = new Armor(*dynamic_cast<Armor*>(temp));
		Inventory->Delete(temp);
		return item;
	}
	else
		return nullptr;
}