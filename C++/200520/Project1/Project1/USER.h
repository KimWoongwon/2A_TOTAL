#ifndef USER_H
#define USER_H

#include "LinkedList.h"
class USER
{
private:
	char m_ID[10];
	char m_PW[10];
	bool m_login;
	CLinkedList<char*>* HaveCode;
public:
	USER(const char*, const char*);
	~USER();

	const char* GetID();
	const char* GetPW();

	void SetID(const char*);
	void SetPW(const char*);

	void SetLogin();
	void SetLogout();

	bool GetLoginState();

	void InsertItem(const char*, int);
	void RemoveItem(const char*, int);


};
#endif // USER_H



