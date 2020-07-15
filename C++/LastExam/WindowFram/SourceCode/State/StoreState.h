#pragma once
#include "GameState.h"

class CStoreState :public CGameState
{	

public:
	CStoreState(CLoginSystem* _game);
	~CStoreState();

	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};

