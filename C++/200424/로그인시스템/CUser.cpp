#include "CUser.h"

CUser::CUser(const char* _id, const char* _pw, int un)
{
	strcpy(mId, _id);
	strcpy(mPw, _pw);
	UserNum = un;
	mLoginState = false;
}

CUser::CUser(const CUser& p_data)
{
	strcpy(mId, p_data.mId);
	strcpy(mPw, p_data.mPw);
	UserNum = p_data.UserNum;
	mLoginState = p_data.mLoginState;
}

CUser::~CUser()
{

}

const char* CUser::GetId()
{
	return mId;
}

const char* CUser::GetPw()
{
	return mPw;
}

bool CUser::GetLoginState()
{
	return mLoginState;
}


bool CUser::SetId(const char* _id)
{
	strcpy(mId, _id);
	return true;
}

bool CUser::SetPw(const char* _pw)
{
	strcpy(mPw, _pw);
	return true;
}

void CUser::SetLogin()
{
	mLoginState = true;
}

void CUser::SetLogout()
{
	mLoginState = false;
}