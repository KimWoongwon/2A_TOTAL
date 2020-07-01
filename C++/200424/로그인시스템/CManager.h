#ifndef CMANAGER_H
#define CMANAGER_H

#include "CUser.h"
#include "List.h"

class CManager
{
private:
	List<CUser*>* mUserLst;
	CUser*		mNowUser;
	int			mUserCount;

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

