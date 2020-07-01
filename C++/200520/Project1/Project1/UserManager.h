#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "USER.h"
class UserManager
{
private:
	USER* m_UserList[10];
	int	  m_UserCount;

	USER* m_NowUser;

	static UserManager* Instance;
	UserManager();
	~UserManager();
public:
	static void Create();
	static void Destroy();
	static UserManager* GetInstance();

	USER* GetNowUser();
	void Join();
	void Logout();
	void Drop();
	bool LoginSystem();
};
#endif // !USERMANAGER_H



