#pragma once

#include "Global.h"
#include "IngredientFactory.h"

class CGimBabHeavenFactory :public CIngredientFactory
{
public:
	CGimBabHeavenFactory();
	~CGimBabHeavenFactory();

	virtual const char* CreateGim();
	virtual const char* CreateRice();
	virtual const char* CreateIngredient(const char*);
};
