#include "MINI_GAME.h"

MINI_GAME::MINI_GAME(HWND hWnd, HINSTANCE inst, CBackBit* pBackBit)
{
	Title::Create(this);
	StartWaiting::Create(this);
	GameStart::Create(this);
	GameEnd::Create(this);

	state = Title::GetInstance();
	this->hWnd = hWnd;
	mhInstance = inst;

	mBackBit = pBackBit;

	GetClientRect(hWnd, &rt);
}
MINI_GAME::~MINI_GAME()
{
	Title::Destory();
	StartWaiting::Destory();
	GameStart::Destory();
	GameEnd::Destory();
}

void MINI_GAME::SetState(GameLogic* _state)
{
	state = _state;
}

void MINI_GAME::OnPaint(HDC hdc)
{
	state->OnPaint(hdc);
}

void MINI_GAME::OnTimer()
{
	state->OnTimer();
}

HWND MINI_GAME::GetHWND()
{
	return hWnd;
}
HINSTANCE MINI_GAME::GetInst()
{
	return mhInstance;
}
CBackBit* MINI_GAME::GetBackBit()
{
	return mBackBit;
}
RECT MINI_GAME::GetRt()
{
	return rt;
}

void MINI_GAME::PushedButton()
{
	state->ChangeState(this);
}