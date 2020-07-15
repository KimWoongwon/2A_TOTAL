#pragma once

#include "../Global.h"
#include "TitleState.h"
#include "SignupState.h"
#include "UserMenuState.h"
#include "StoreState.h"
#include "CreateState.h"

class CLoginSystem
{	

	static CLoginSystem*	mPthis;

	CGameState*		mNowState;
	
	CTitleState*		mTitleState;
	CSignupState*		mSignupState;
	CUserMenuState*		mUserMenuState;
	CStoreState*		mStoreState;
	CCreateState*		mCreateState;

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

	void SetNowState(CGameState*);
};

