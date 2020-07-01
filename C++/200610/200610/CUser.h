#ifndef CUSER_H
#define CUSER_H

#include "Global.h"
#include "Character.h"
class CUser
{
private:
	char mId[10];
	char mPw[10];
	Character* CharList[MAX_CHARACTER];
	int CharCount;
	bool mLoginState;

public:
	CUser(const char*, const char*);
	~CUser();

	const char* GetId();
	const char* GetPw();
	bool  GetLoginState();
	Character* GetChar(int );
	int GetCount();

	bool SetId(const char*);
	bool SetPw(const char*);
	void SetLogin();
	void SetLogout();
	
	void InsertCharacter(Character*);
	void RemoveCharacter(const char*);
	void DisplayCharacterInfo(bool);
};

#endif