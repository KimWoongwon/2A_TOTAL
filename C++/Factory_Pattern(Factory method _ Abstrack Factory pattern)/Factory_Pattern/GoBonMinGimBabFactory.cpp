#include "GoBongMinGimBabFactory.h"

CGoBongMinGimBabFactory::CGoBongMinGimBabFactory()
{

}
CGoBongMinGimBabFactory::~CGoBongMinGimBabFactory()
{

}

const char* CGoBongMinGimBabFactory::CreateGim()
{
	return "����";
}
const char* CGoBongMinGimBabFactory::CreateRice()
{
	return "���ֽ�";
}
const char* CGoBongMinGimBabFactory::CreateIngredient(const char* _kind)
{
	if (!strcmp(_kind, "ġ��"))
	{
		return "ũ�� ġ��, �ܹ���, ��";
	}
	else if (!strcmp(_kind, "��ä"))
	{
		return "������ī, ����, �ܹ���";
	}

	return nullptr;

}