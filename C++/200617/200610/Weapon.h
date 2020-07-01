#pragma once
#include "Item.h"

#define CODE_WEAPON 1
class Weapon : public Item
{
private:
public:
	Weapon(const char*,STATUS*, int, int);
	~Weapon();

	virtual void OnItem(Character*);
	virtual void OffItem(Character*);
};

