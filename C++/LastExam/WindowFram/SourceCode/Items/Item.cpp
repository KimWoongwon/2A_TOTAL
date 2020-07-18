#include "Item.h"
#include "../Character/Character.h"
Item::Item(const char* pName, STATUS* pStatus, int pPrice, CLASS pClassCode, ITEMTYPE pTypeCode)
{
	strcpy_s(ItemName, sizeof(ItemName), pName);
	status = new STATUS(*pStatus);
	price = pPrice;
	ClassCode = pClassCode;
	TypeCode = pTypeCode;
}
Item::Item(Item& item)
{
	strcpy_s(ItemName, sizeof(ItemName), item.ItemName);
	status = new STATUS(*item.status);
	price = item.price;
	ClassCode = item.ClassCode;
	TypeCode = item.TypeCode;
}
Item::~Item()
{
	if (status != nullptr)
		delete status;
}
char* Item::GetName()
{
	return ItemName;
}
STATUS* Item::GetStatus()
{
	return status;
}
int Item::GetPrice()
{
	return price;
}
CLASS Item::GetClassCode()
{
	return ClassCode;
}
ITEMTYPE Item::GetTypeCode()
{
	return TypeCode;
}

void Item::OnItem(Character* _char)
{
	_char->GetStatus()->Hp += status->Hp;
	_char->GetStatus()->Mp += status->Mp;
	_char->GetStatus()->ATK += status->ATK;
	_char->GetStatus()->DEF += status->DEF;
}

void Item::OffItem(Character* _char)
{
	_char->GetStatus()->Hp -= status->Hp;
	_char->GetStatus()->Mp -= status->Mp;
	_char->GetStatus()->ATK -= status->ATK;
	_char->GetStatus()->DEF -= status->DEF;
}
