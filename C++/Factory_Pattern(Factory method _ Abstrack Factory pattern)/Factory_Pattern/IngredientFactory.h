#pragma once
#include "Global.h"

class CIngredientFactory
{
public:
	CIngredientFactory() {}
	~CIngredientFactory() {}

	virtual const char* CreateGim() = 0;
	virtual const char* CreateRice() = 0;
	virtual const char* CreateIngredient(const char*) = 0;

};