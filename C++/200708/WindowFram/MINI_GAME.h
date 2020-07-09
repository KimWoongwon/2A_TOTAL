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
	HBITMAP BackGroundImg;
	bool InvalFlag = FALSE;
	

	CBackBit* mBackBit;
	RECT rt;
public:
	LOGICS logic = LOGICS::TITLE;
	int Score = 0;
	MINI_GAME(HWND hWnd, HINSTANCE inst, HBITMAP hBitmap, CBackBit* pBackBit);
	~MINI_GAME();

	void SetState(GameLogic* _state);
	void SetFlag(bool);

	void OnPaint(HDC);
	void OnTimer();

	HWND GetHWND();
	HINSTANCE GetInst();
	HBITMAP GetBGImg();

	CBackBit* GetBackBit();
	RECT GetRt();
	bool GetInval() { return InvalFlag; }

	void PushedButton(HWND);

};

