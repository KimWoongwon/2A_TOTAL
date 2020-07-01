
#include "MainManager.h"

int main()
{
	CMainManager* mainprocess = new CMainManager();
	mainprocess->Initialize();
	mainprocess->Run();
	delete mainprocess;
	return 0;
}