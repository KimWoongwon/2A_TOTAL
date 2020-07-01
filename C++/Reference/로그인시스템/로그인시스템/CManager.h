#ifndef CMANAGER_H
#define CMANAGER_H

#include "Global.h"
#include "CUser.h"

class CManager
{
private:
	CUser*		mUserLst[10];
	int			mUserCount;

	CUser*		mNowUser;

public:
	CManager();
	~CManager();

	void Run();
	bool Join();
	bool Login();
	LOGIN_MENU LoginMenu();
	MAIN_MENU MainMenu();
	void Logout();
	void Drop();
	
};
#endif

