#pragma once
#include "Item.h"
#define CODE_ARMOR 2
class Armor : public Item
{
private:
public:
	Armor(const char*, STATUS*, int, int);
	~Armor();

	virtual void OnItem(Character*);
	virtual void OffItem(Character*);
};

