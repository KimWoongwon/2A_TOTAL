#include "GameLogic.h"
#include "MINI_GAME.h"

Title* Title::Instance = nullptr;

void Title::Create(MINI_GAME* mMainSence)
{
	
	if (Instance == nullptr)
		Instance = new Title();
	Instance->mMainSence = mMainSence;
	Instance->BackGround = LoadBitmap(mMainSence->GetInst(), MAKEINTRESOURCE(IDB_BITMAP1));
	Instance->BGposX = -mMainSence->GetRt().right;
}
void Title::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
Title* Title::GetInstance()
{
	return Instance;
}
void Title::OnPaint(HDC hdc)
{
	mMainSence->GetBackBit()->BitmapDraw(BGposX, 0, BackGround);
	mMainSence->GetBackBit()->SCreanDraw(hdc, 0, 50);
	mMainSence->GetBackBit()->ClearBitMap();
}
void Title::OnTimer()
{
	BGposX += BGmoveSpeed;
	if (BGposX >= 100)
		BGmoveSpeed = 0;
}
void Title::ChangeState()
{
	mMainSence->SetState(GameStart::GetInstance());
}

StartWaiting* StartWaiting::Instance = nullptr;

void StartWaiting::Create(MINI_GAME* mMainSence)
{
	if (Instance == nullptr)
		Instance = new StartWaiting();
	Instance->mMainSence = mMainSence;
}
void StartWaiting::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
StartWaiting* StartWaiting::GetInstance()
{

	return Instance;
}
void StartWaiting::OnPaint(HDC hdc)
{

}
void StartWaiting::OnTimer()
{

}
void StartWaiting::ChangeState()
{
	mMainSence->SetState(GameStart::GetInstance());
}

GameStart* GameStart::Instance = nullptr;

void GameStart::Create(MINI_GAME* mMainSence)
{
	if (Instance == nullptr)
		Instance = new GameStart();
}
void GameStart::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
GameStart* GameStart::GetInstance()
{
	return Instance;
}
void GameStart::OnPaint(HDC hdc)
{

}
void GameStart::OnTimer()
{

}
void GameStart::ChangeState()
{
	mMainSence->SetState(GameEnd::GetInstance());
}

GameEnd* GameEnd::Instance = nullptr;

void GameEnd::Create(MINI_GAME* mMainSence)
{
	if (Instance == nullptr)
		Instance = new GameEnd();
}
void GameEnd::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
GameEnd* GameEnd::GetInstance()
{
	return Instance;
}
void GameEnd::OnPaint(HDC hdc)
{

}
void GameEnd::OnTimer()
{

}
void GameEnd::ChangeState()
{

}