#pragma once
#include "Global.h"

class Character;

class Item
{
protected:
	char ItemName[50];
	STATUS* status;
	int price;
	int JobCode;
	int TypeCode;
public:
	Item(const char*, STATUS*, int, int, int);
	~Item();

	const char* GetName();
	STATUS* GetStatus();
	const int GetPrice();
	const int GetJobCode();
	const int GetTypeCode();

	virtual void OnItem(Character*) = 0;
	virtual Item* OffItem(Character*) = 0;
};

