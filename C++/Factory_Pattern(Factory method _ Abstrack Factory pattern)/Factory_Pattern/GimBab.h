#ifndef _CGIMBAB_H
#define _CGIMBAB_H
#include "Global.h"
#include "IngredientFactory.h"

class CGimBab
{
protected:

	char mName[255];
	int  mPrice;

	char mGim[255];
	char mRice[255];
	char mIngredient[255];

	CIngredientFactory* mFactory;

public:
	CGimBab(const char*, int, CIngredientFactory*);
	virtual ~CGimBab();

	const char* GetName();
	void SetName(const char*);

	int GetPrice();
	void SetPrice(int _money);

	virtual void Prepare()=0;
	virtual void IngredientSet()=0;
	virtual void Roll()=0;
	virtual void Cut()=0;

};
#endif