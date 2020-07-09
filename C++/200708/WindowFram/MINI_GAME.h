#pragma once
#include "Global.h"
#include "WindowFrame.h"
#include "GameLogic.h"
class MINI_GAME
{
private:
	GameLogic* state;

	HWND hWnd;
	HINSTANCE mhInstance;
	CBackBit* mBackBit;
	RECT rt;
public:
	MINI_GAME(HWND hWnd, HINSTANCE inst, CBackBit* pBackBit);
	~MINI_GAME();

	void SetState(GameLogic* _state);
	
	void OnPaint(HDC);
	void OnTimer();

	HWND GetHWND();
	HINSTANCE GetInst();
	CBackBit* GetBackBit();
	RECT GetRt();

	void PushedButton();

};

