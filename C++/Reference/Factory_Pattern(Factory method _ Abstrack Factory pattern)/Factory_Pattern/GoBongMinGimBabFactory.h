#pragma once
#include "Global.h"
#include "IngredientFactory.h"

class CGoBongMinGimBabFactory:public CIngredientFactory
{
public:
	CGoBongMinGimBabFactory();
	~CGoBongMinGimBabFactory();

	virtual const char* CreateGim();
	virtual const char* CreateRice();
	virtual const char* CreateIngredient(const char*);

};
