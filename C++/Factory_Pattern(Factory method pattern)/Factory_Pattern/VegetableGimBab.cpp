#include "VegetableGimBab.h"

CVegetableGimBab::CVegetableGimBab(const char* _name, int _price):CGimBab(_name, _price)
{
}
CVegetableGimBab::~CVegetableGimBab()
{
}
void CVegetableGimBab::Prepare()
{
	cout << "���� ��� ���� �÷� ��ϴ�....." << endl;
}

void CVegetableGimBab::IngredientSet()
{
	cout << "�ܹ���, ��, ���, ������ �ø��ϴ�......" << endl;
}

void CVegetableGimBab::Roll()
{
	cout << "����� �����ϰ� ���� �����ݴϴ�...." << endl;
}

void CVegetableGimBab::Cut()
{
	cout << "����� 1.5��Ƽ ũ��� ��ϴ�....." << endl;
}