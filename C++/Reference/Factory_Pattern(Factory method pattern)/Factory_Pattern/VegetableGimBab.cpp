#include "VegetableGimBab.h"

CVegetableGimBab::CVegetableGimBab(const char* _name, int _price):CGimBab(_name, _price)
{
}
CVegetableGimBab::~CVegetableGimBab()
{
}
void CVegetableGimBab::Prepare()
{
	cout << "±èÀ» ±ò°í ¹äÀ» ¿Ã·Á Æð´Ï´Ù....." << endl;
}

void CVegetableGimBab::IngredientSet()
{
	cout << "´Ü¹«Áö, ÇÜ, ´ç±Ù, ¿¬±ÙÀ» ¿Ã¸³´Ï´Ù......" << endl;
}

void CVegetableGimBab::Roll()
{
	cout << "±è¹äÀ» ³³ÀÛÇÏ°Ô ¸»¾Æ ´­·¯ÁÝ´Ï´Ù...." << endl;
}

void CVegetableGimBab::Cut()
{
	cout << "±è¹äÀ» 1.5¼¾Æ¼ Å©±â·Î ½ç´Ï´Ù....." << endl;
}