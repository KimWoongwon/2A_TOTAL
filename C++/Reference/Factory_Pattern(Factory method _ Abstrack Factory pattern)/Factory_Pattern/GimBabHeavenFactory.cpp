#include "GimBabHeavenFactory.h"

CGimBabHeavenFactory::CGimBabHeavenFactory()
{

}
CGimBabHeavenFactory::~CGimBabHeavenFactory()
{

}

const char* CGimBabHeavenFactory::CreateGim()
{
	return "�ķ���";
}

const char* CGimBabHeavenFactory::CreateRice()
{
	return "��õ��";
}

const char* CGimBabHeavenFactory::CreateIngredient(const char* _kind)
{
	if (!strcmp(_kind, "ġ��"))
	{
		return "��¥���� ġ��, �ܹ���, ��";
	}
	else if (!strcmp(_kind, "��ä"))
	{
		return "���, ����, �ܹ���, ����";
	}

	return nullptr;
}

