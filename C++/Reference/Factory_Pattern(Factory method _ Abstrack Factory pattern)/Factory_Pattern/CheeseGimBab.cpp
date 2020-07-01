#include "CheeseGimBab.h"
CCheeseGimBab::CCheeseGimBab(const char* _name, int _price, CIngredientFactory* _factory):CGimBab(_name, _price, _factory)
{
	strcpy(mIngredient, mFactory->CreateIngredient("치즈"));
}

CCheeseGimBab::~CCheeseGimBab()
{

}

void CCheeseGimBab::Prepare()
{
	cout << CGimBab::mGim << "을 깔고 "<< CGimBab::mRice << "밥을 올려 폅니다....." << endl;
}

void CCheeseGimBab::IngredientSet()
{
	cout << CGimBab::mIngredient <<"를 올립니다......" << endl;
}

void CCheeseGimBab::Roll()
{
	cout << "김밥을 동글게 말아 눌러줍니다...." << endl;
}

void CCheeseGimBab::Cut()
{
	cout << "김밥을 2센티 크기로 썹니다....." << endl;
}