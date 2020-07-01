#include "CheeseGimBab.h"
CCheeseGimBab::CCheeseGimBab(const char* _name, int _price, CIngredientFactory* _factory):CGimBab(_name, _price, _factory)
{
	strcpy(mIngredient, mFactory->CreateIngredient("ġ��"));
}

CCheeseGimBab::~CCheeseGimBab()
{

}

void CCheeseGimBab::Prepare()
{
	cout << CGimBab::mGim << "�� ��� "<< CGimBab::mRice << "���� �÷� ��ϴ�....." << endl;
}

void CCheeseGimBab::IngredientSet()
{
	cout << CGimBab::mIngredient <<"�� �ø��ϴ�......" << endl;
}

void CCheeseGimBab::Roll()
{
	cout << "����� ���۰� ���� �����ݴϴ�...." << endl;
}

void CCheeseGimBab::Cut()
{
	cout << "����� 2��Ƽ ũ��� ��ϴ�....." << endl;
}