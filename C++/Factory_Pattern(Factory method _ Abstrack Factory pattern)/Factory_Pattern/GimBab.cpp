#include "GimBab.h"

CGimBab::CGimBab(const char* _name, int _price, CIngredientFactory* _factory)
{
	strcpy(mName, _name);	
	mPrice = _price;

	mFactory = _factory;

	strcpy(mGim, mFactory->CreateGim());
	strcpy(mRice, mFactory->CreateRice());
}

CGimBab::~CGimBab()
{
	if (mFactory != nullptr)
	{
		delete mFactory;
	}
}

void CGimBab::SetName(const char* _name)
{	
	strcpy(mName, _name);
}


const char* CGimBab::GetName()
{ 
	return mName; 
}

int CGimBab::GetPrice()
{ 
	return mPrice;
}

void CGimBab::SetPrice(int _money)
{
	mPrice = _money; 
}

