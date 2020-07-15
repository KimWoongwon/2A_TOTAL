#pragma once
#include "GameState.h"

class CUserMenuState :	public CGameState
{
public:
	CUserMenuState(CLoginSystem*);
	~CUserMenuState();

	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};

