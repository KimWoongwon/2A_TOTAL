#include "VegetableGimBab.h"

CVegetableGimBab::CVegetableGimBab(const char* _name, int _price, CIngredientFactory* _factory):CGimBab(_name, _price, _factory)
{
	strcpy(mIngredient, mFactory->CreateIngredient("¾ßÃ¤"));
}
CVegetableGimBab::~CVegetableGimBab()
{
	
}
void CVegetableGimBab::Prepare()
{
	cout << CGimBab::mGim << "À» ±ò°í " << CGimBab::mRice << "¹äÀ» ¿Ã·Á Æð´Ï´Ù....." << endl;
}

void CVegetableGimBab::IngredientSet()
{
	cout << CGimBab::mIngredient << "¸¦ ¿Ã¸³´Ï´Ù......" << endl;
}

void CVegetableGimBab::Roll()
{
	cout << "±è¹äÀ» ³³ÀÛÇÏ°Ô ¸»¾Æ ´­·¯ÁÝ´Ï´Ù...." << endl;
}

void CVegetableGimBab::Cut()
{
	cout << "±è¹äÀ» 1.5¼¾Æ¼ Å©±â·Î ½ç´Ï´Ù....." << endl;
}