#ifndef _CVEGGIEGIMBAB_H
#define _CVEGGIEGIMBAB_H
#include "Global.h"
#include "GimBab.h"

class CVegetableGimBab : public CGimBab
{
private:
	

public:
	CVegetableGimBab(const char* , int , CIngredientFactory*);
	~CVegetableGimBab();

	virtual void Prepare();
	virtual void IngredientSet();
	virtual void Roll();
	virtual void Cut();
};

#endif