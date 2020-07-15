#include "LoginSystem.h"

CLoginSystem* CLoginSystem::mPthis = nullptr;
CLoginSystem::CLoginSystem()
{	
	mMatchCount = 0;
	mTitleState = new CTitleState(this);
	mUserMenuState = new CUserMenuState(this);
	mStoreState = new CStoreState(this);
	mCreateState = new CCreateState(this);
	mSignupState = new CSignupState(this);

	mResultState = new CResultPlayState(this);		
	
	mNowState = nullptr;
}

CLoginSystem::~CLoginSystem()
{	
	delete mTitleState;
	delete mUserMenuState;
	delete mStoreState;
	delete mCreateState;
	delete mSignupState;

	delete mResultState;	
}

CLoginSystem* CLoginSystem::Create()
{
	if (!mPthis)
	{
		mPthis = new CLoginSystem();
	}
	return mPthis;
}

CLoginSystem* CLoginSystem::GetInstance()
{
	return mPthis;
}

void CLoginSystem::Destroy()
{	
	if (mPthis)
	{
		delete mPthis;
		mPthis = NULL;
	}
}


void CLoginSystem::TimerProcess()
{
	mNowState->TimerProcess();
}
void CLoginSystem::ClickProcess()
{
	mNowState->ClickProcess();
}
void CLoginSystem::InitializeProcess()
{
	SetNowState(mTitleState);
}
void CLoginSystem::ButtonProcess(WPARAM _wParam)
{
	mNowState->ButtonProcess(_wParam);
}


CGameState* CLoginSystem::GetTitleState()
{
	return mTitleState;
}
CGameState* CLoginSystem::GetUserMenuState()
{
	return mUserMenuState;
}
CGameState* CLoginSystem::GetStoreState()
{
	return mStoreState;
}
CGameState* CLoginSystem::GetCreateState()
{
	return mCreateState;
}
CGameState* CLoginSystem::GetSignupState()
{
	return mSignupState;
}



int	CLoginSystem::GetMatchCount()
{
	return mMatchCount;
}

void CLoginSystem::InCreMentMatchCount()
{
	mMatchCount++;
}
void CLoginSystem::ClearMatchCount()
{
	mMatchCount = 0;
}
void CLoginSystem::SetNowState(CGameState* _state)
{
	mNowState = _state;
	mNowState->InitializeProcess();
}