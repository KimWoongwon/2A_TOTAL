#pragma once
#include "GameState.h"

class CResultPlayState :
	public CGameState
{
public:
	CResultPlayState(CLoginSystem* _game);
	~CResultPlayState();

	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};

