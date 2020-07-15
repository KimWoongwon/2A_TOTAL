#pragma once
#include "GameState.h"

class CTitleState :	public CGameState
{

public:
	CTitleState(CLoginSystem* _game);
	~CTitleState();

	

	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};

