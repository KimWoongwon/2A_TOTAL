#include "MINI_GAME.h"

MINI_GAME::MINI_GAME(HWND phWnd, HINSTANCE inst, HBITMAP hBitmap, CBackBit* pBackBit)
{
	hWnd = phWnd;
	mhInstance = inst;
	BackGroundImg = hBitmap;
	mBackBit = pBackBit;

	GetClientRect(hWnd, &rt);

	Title::Create(this);
	//Reset::Create(this);
	GameStart::Create(this);
	GameEnd::Create(this);
	state = Title::GetInstance();

}
MINI_GAME::~MINI_GAME()
{
	delete mBackBit;
	Title::Destory();
	//Reset::Destory();
	GameStart::Destory();
	GameEnd::Destory();
}

void MINI_GAME::SetState(GameLogic* _state)
{
	state = _state;
}
void MINI_GAME::SetFlag(bool flag)
{
	InvalFlag = flag;
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
HBITMAP MINI_GAME::GetBGImg()
{
	return BackGroundImg;
}

CBackBit* MINI_GAME::GetBackBit()
{
	return mBackBit;
}
RECT MINI_GAME::GetRt()
{
	return rt;
}

void MINI_GAME::PushedButton(HWND phWnd)
{
	state->ChangeState();
}