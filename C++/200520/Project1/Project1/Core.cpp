#include "Global.h"
#include "MainManager.h"

void main()
{
	MainManager::Create();
	MainManager::GetInstance()->Run();
	MainManager::Destroy();
}