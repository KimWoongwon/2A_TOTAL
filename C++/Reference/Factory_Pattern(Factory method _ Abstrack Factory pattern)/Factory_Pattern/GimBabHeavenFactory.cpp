#include "GimBabHeavenFactory.h"

CGimBabHeavenFactory::CGimBabHeavenFactory()
{

}
CGimBabHeavenFactory::~CGimBabHeavenFactory()
{

}

const char* CGimBabHeavenFactory::CreateGim()
{
	return "파래김";
}

const char* CGimBabHeavenFactory::CreateRice()
{
	return "이천쌀";
}

const char* CGimBabHeavenFactory::CreateIngredient(const char* _kind)
{
	if (!strcmp(_kind, "치즈"))
	{
		return "모짜렐라 치즈, 단무지, 햄";
	}
	else if (!strcmp(_kind, "야채"))
	{
		return "당근, 깻잎, 단무지, 연근";
	}

	return nullptr;
}

