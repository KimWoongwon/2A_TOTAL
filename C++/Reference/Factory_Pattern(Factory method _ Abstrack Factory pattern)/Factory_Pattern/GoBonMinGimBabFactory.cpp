#include "GoBongMinGimBabFactory.h"

CGoBongMinGimBabFactory::CGoBongMinGimBabFactory()
{

}
CGoBongMinGimBabFactory::~CGoBongMinGimBabFactory()
{

}

const char* CGoBongMinGimBabFactory::CreateGim()
{
	return "돌김";
}
const char* CGoBongMinGimBabFactory::CreateRice()
{
	return "여주쌀";
}
const char* CGoBongMinGimBabFactory::CreateIngredient(const char* _kind)
{
	if (!strcmp(_kind, "치즈"))
	{
		return "크림 치즈, 단무지, 햄";
	}
	else if (!strcmp(_kind, "야채"))
	{
		return "파프리카, 케일, 단무지";
	}

	return nullptr;

}