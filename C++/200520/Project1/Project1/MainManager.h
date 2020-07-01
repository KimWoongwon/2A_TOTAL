#ifndef MAINMANAGER_H
#define MAINMANAGER_H
#include "Global.h"
class MainManager
{
private:
	static MainManager* Instance;

	MainManager();
	~MainManager();
public:
	static void Create();
	static void Destroy();
	static MainManager* GetInstance();

	void Run();
	MAIN_MENU MainMenu();
	LOGIN_MENU LoginMenu();
};


#endif // !MAINMANAGER_H

