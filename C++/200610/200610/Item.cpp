#include "Item.h"
Item::Item(const char* pName, STATUS* pStatus, int pPrice, int pJobCode, int pTypeCode)
{
	strcpy_s(ItemName, sizeof(ItemName), pName);
	status = pStatus;
	price = pPrice;
	JobCode = pJobCode;
	TypeCode = pTypeCode;
}
Item::~Item()
{
	if (status != nullptr)
		delete status;
}
const char* Item::GetName()
{
	return ItemName;
}
STATUS* Item::GetStatus()
{
	return status;
}
const int Item::GetPrice()
{
	return price;
}
const int Item::GetJobCode()
{
	return JobCode;
}
const int Item::GetTypeCode()
{
	return TypeCode;
}
