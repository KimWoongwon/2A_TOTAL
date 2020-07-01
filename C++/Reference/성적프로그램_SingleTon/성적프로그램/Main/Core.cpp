
#include "MainManager.h"

int main()
{
	CMainManager::Create();
	CMainManager::GetInstance()->Initialize();
	CMainManager::GetInstance()->Run();
	CMainManager::Destroy();
	return 0;
}