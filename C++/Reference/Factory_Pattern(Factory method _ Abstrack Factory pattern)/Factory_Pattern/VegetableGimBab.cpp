#include "VegetableGimBab.h"

CVegetableGimBab::CVegetableGimBab(const char* _name, int _price, CIngredientFactory* _factory):CGimBab(_name, _price, _factory)
{
	strcpy(mIngredient, mFactory->CreateIngredient("��ä"));
}
CVegetableGimBab::~CVegetableGimBab()
{
	
}
void CVegetableGimBab::Prepare()
{
	cout << CGimBab::mGim << "�� ��� " << CGimBab::mRice << "���� �÷� ��ϴ�....." << endl;
}

void CVegetableGimBab::IngredientSet()
{
	cout << CGimBab::mIngredient << "�� �ø��ϴ�......" << endl;
}

void CVegetableGimBab::Roll()
{
	cout << "����� �����ϰ� ���� �����ݴϴ�...." << endl;
}

void CVegetableGimBab::Cut()
{
	cout << "����� 1.5��Ƽ ũ��� ��ϴ�....." << endl;
}