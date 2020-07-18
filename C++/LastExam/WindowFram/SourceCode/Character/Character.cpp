#include "../Global.h"
#include "Character.h"
// 캐릭터 생성자
Character::Character(const char* p_name,CLASS pjob, ItemFactory* p_factory)
{
	strcpy_s(name, sizeof(name), p_name);
	Level = 1;
	status = new STATUS(10, 5, 20, 3);
	NowWeapon = p_factory->CreateWeapon();
	NowArmor = p_factory->CreateArmor();
	cls = pjob;
	Inventory = new CItemListManager(p_name);
	// 이니셜라이즈 함수에서 파일정보를 불러올때 파일에 전의 착용정보가 남아있기때문에 해당 장비로 셋팅해준다.
	Inventory->Initialize((Item**)&NowWeapon, (Item**)&NowArmor);	
}

Character::~Character()
{
	// 캐릭터를 삭제하기 전 현재 착용중인 장비의 정보를 먼저 파일에 쓰고 그뒤에 인벤토리가 삭제되면서
	// 인벤토리의 아이템정보를 파일에 출력한다.
	Inventory->SaveNowInfo(dynamic_cast<Item*>(NowWeapon),dynamic_cast<Item*>(NowArmor));
	OffItem(NowWeapon);
	OffItem(NowArmor);
	
	delete Inventory;
	delete status;
}
// 캐릭터 이름 반환 함수
char* Character::GetName()	
{
	return name;
}
// 파일에 저장시 문자열 형태로 저장하기 위해서 변환해서 반환해주는 함수
char* Character::GetRegion()	
{
	if (region == REGION::HUM)
		return "인간";
	else if (region == REGION::ORC)
		return "오크";
	else if (region == REGION::ELF)
		return "엘프";
}
// 파일에 저장시 문자열 형태로 저장하기 위해서 변환해서 반환해주는 함수
char* Character::GetClass()		
{
	if (cls == CLASS::WARRIOR)
		return "전사";
	else if (cls == CLASS::ARCHER)
		return "궁수";
	else if (cls == CLASS::SORCERER)
		return "마법사";
}
// 직업 비교시에 코드가 직접적으로 필요하기 때문에 구현한 반환함수
CLASS Character::GetClassType()	
{
	return cls;
}
// 아이템 장착 및 해제시에 스텟 변경을 위한 반환함수
STATUS* Character::GetStatus()	
{
	return status;
}
// 아이템을 사고 팔고 장착, 변경, 해제등을 하기 위해 인벤토리 반환해주는 함수
CItemListManager* Character::GetInventory()	
{
	return Inventory;
}
// 현재 착용한 무기를 반환해주는 함수
Weapon* Character::GetWeapon()
{
	return NowWeapon;
}
// 현재 착용한 방어구를 반환해주는 함수
Armor* Character::GetArmor()
{
	return NowArmor;
}
// 캐릭터 아이템을 장착하는 함수
bool Character::OnItem(Item* _item)
{
	// 넘겨온 아이템이 무기인경우
	if (_item->GetTypeCode() == ITEMTYPE::WEAPONE)	
	{
		// 현재 장착중인 아이템이 없어야 하기때문에 조건을 설정해준다.
		if (NowWeapon != nullptr)
			return false;
		// 받아온 아이템을 현재의 아이템으로 저장해준뒤
		NowWeapon = dynamic_cast<Weapon*>(_item);
	}

	if (_item->GetTypeCode() == ITEMTYPE::ARMOR)
	{
		if (NowArmor != nullptr)
			return false;
		NowArmor = dynamic_cast<Armor*>(_item);
	}
	// 아이템 착용해서 스텟을 변경한다.
	_item->OnItem(this);
	
}
// 캐릭터의 아이템을 장착 해제하는 함수
bool Character::OffItem(Item* _item)
{
	// 넘겨온 아이템이 무기나 방어구인 경우를 먼저 따진다.
	if (_item->GetTypeCode() == ITEMTYPE::WEAPONE)
	{
		// 장착된 아이템이 없을경우 해제가 말이 안되기때문에 조건을 설정해준다.
		if (NowWeapon == nullptr)
			return false;
		// 먼저 스텟을 변경하고 현재 착용 아이템이 없다고 설정해준다.
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

// 아이템을 구매했을때 인벤토리에 아이템을 저장하기 위한 함수
void Character::BuyItem(Item* pItem)
{
	// 외부에서 셋팅된 아이템을 인벤토리에 넣어주기만 한다.
	Inventory->Input(pItem);
	return;
}

// 아이템을 판매할때 인벤토리에서 해당 이름의 아이템을 찾아서 반환해준다.
Item* Character::SellItem(char* _str)
{
	// 아이템을 찾는 부분
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
	
	// 인벤토리에서 해당아이템을 바로 삭제하면 외부에서 접근이 사라지기 때문에
	Item* item = nullptr;
	if (flag)
	{
		// 복사생성자를 이용해서 새롭지만 똑같은 객체를 만들어 준다음 반환한다.
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