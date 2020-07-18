#include "User.h"

CUser::CUser(const char* _id, const char* _pw)
{
	
	strcpy_s(mId, sizeof(mId), _id);
	strcpy_s(mPw, sizeof(mPw), _pw);
	mLoginState = false;
	money = 10000;

	CharList = new CCharacterManager(mId);
	CharList->Initialize();
}

CUser::~CUser()
{
	delete CharList;
}

const char* CUser::GetId()
{
	return mId;
}

const char* CUser::GetPw()
{
	return mPw;
}

int CUser::GetMoney()
{
	return money;
}
void CUser::SetMoney(int _money)
{
	money = _money;
}

bool CUser::GetLoginState()
{
	return mLoginState;
}
Character* CUser::GetChar(const char* _str)
{
	Character* temp = nullptr;
	int count = CharList->GetCount();
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (CharList->GetData(&temp))
			if (!strcmp(temp->GetName(), _str))
			{
				flag = true;
				break;
			}
	}
	CharList->GetDataEnd();

	if (flag)
		return temp;
	else
		return nullptr;
}

CCharacterManager* CUser::GetCharList()
{
	return CharList;
}

int CUser::GetCount()
{
	return CharList->GetCount();
}

void CUser::SetLogin()
{
	mLoginState = true;
}

void CUser::SetLogout()
{
	mLoginState = false;
}

void CUser::InsertCharacter(Character* p_char)
{
	CharList->Input(p_char);
}

bool CUser::RemoveCharacter(const char* p_name)
{
	Character* temp = nullptr;
	int count = CharList->GetCount();
	bool flag = false;

	for (int i = 0; i < count; i++)
	{
		if(CharList->GetData(&temp))
		if (!strcmp(temp->GetName(), p_name))
		{
			flag = true;
			break;
		}
	}
	CharList->GetDataEnd();
	if (flag)
	{
		CharList->Delete(temp);
		return true;
	}
	else
		return false;
}
