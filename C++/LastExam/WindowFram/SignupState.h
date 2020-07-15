#pragma once
#include "GameState.h"

class CSignupState : public CGameState
{

public:
	CSignupState(CLoginSystem* _game);
	~CSignupState();



	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};

