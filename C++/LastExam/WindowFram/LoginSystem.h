#pragma once

#include "Global.h"

#include "TitleState.h"
#include "SignupState.h"
#include "UserMenuState.h"
#include "StoreState.h"
#include "CreateState.h"

#include "ResultPlayState.h"


class CLoginSystem
{	

	static CLoginSystem*	mPthis;

	int				mMatchCount;
	CGameState*		mNowState;
	
	CTitleState*		mTitleState;
	CSignupState*		mSignupState;
	CUserMenuState*		mUserMenuState;
	CStoreState*		mStoreState;
	CCreateState*		mCreateState;

	CResultPlayState*	mResultState;

	CLoginSystem();
	~CLoginSystem();

public:

	static CLoginSystem* Create();
	static CLoginSystem* GetInstance();
	static void Destroy();

	void TimerProcess();
	void ClickProcess();
	void InitializeProcess();
	void ButtonProcess(WPARAM);

	CGameState* GetTitleState();
	CGameState* GetUserMenuState();
	CGameState* GetStoreState();
	CGameState* GetCreateState();
	CGameState* GetSignupState();

	
	int			GetMatchCount();

	void InCreMentMatchCount();
	void ClearMatchCount();
	void SetNowState(CGameState*);
};

