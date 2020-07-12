#include "GameLogic.h"
#include "MINI_GAME.h"
#include "Mouse.h"

#pragma region Title_Realize
Title* Title::Instance = nullptr;

void Title::Create(MINI_GAME* mMainSence)
{

	if (Instance == nullptr)
		Instance = new Title();
	Instance->mMainSence = mMainSence;
	Instance->BackGround = Instance->mMainSence->GetBGImg();
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
	GameStart::GetInstance()->Reset();
	mMainSence->logic = LOGICS::START;
	mMainSence->SetFlag(TRUE);
	mMainSence->SetState(GameStart::GetInstance());
}
void Title::reset()
{
	BGposX = -mMainSence->GetRt().right;
}
#pragma endregion

#pragma region GameStart_Realize
GameStart* GameStart::Instance = nullptr;

void GameStart::Create(MINI_GAME* mMainSence)
{
	if (Instance == nullptr)
		Instance = new GameStart();
	srand(time(NULL));
	Instance->mMainSence = mMainSence;
	Instance->Gametime = 10;
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
	Ellipse(hdc, CirclePos.x, CirclePos.y, CirclePos.x + radius * 2, CirclePos.y + radius * 2);
}

void GameStart::OnTimer()
{
	if (Gametime < 0)
	{
		count = 0;
		CircleCount = 0;
	}
	/*Instance->CirclePos.x = 100 + rand() % (mMainSence->GetRt().right - 200);
	Instance->CirclePos.y = 100 + rand() % (mMainSence->GetRt().bottom - 200);
	Instance->radius = 20 + rand() % 30;*/
	if (count++ >= 10)
	{
		char temp[20];
		wsprintf(temp, "Time : %d", Gametime--);
		SetWindowText(mMainSence->GetHWND(), temp);
		count = 0;
	}

	if (CircleCount++ >= 5)
	{
		Instance->CirclePos.x = 100 + rand() % (mMainSence->GetRt().right - 200);
		Instance->CirclePos.y = 100 + rand() % (mMainSence->GetRt().bottom - 200);
		Instance->radius = 20 + rand() % 30;
		CircleCount = 0;
	}
	

	
}
void GameStart::ChangeState()
{
	if (Gametime > 0)
	{
		Reset();
		return;
	}
	mMainSence->logic = LOGICS::END;
	mMainSence->SetFlag(FALSE);
	mMainSence->SetState(GameEnd::GetInstance());
}

void GameStart::Reset()
{
	mMainSence->Score = 0;
	Gametime = 10;
}
#pragma endregion

//#pragma region Reset_Realize
//Reset* Reset::Instance = nullptr;
//
//void Reset::Create(MINI_GAME* mMainSence)
//{
//	if (Instance == nullptr)
//		Instance = new Reset();
//	Instance->mMainSence = mMainSence;
//}
//void Reset::Destory()
//{
//	if (Instance != nullptr)
//		delete Instance;
//}
//Reset* Reset::GetInstance()
//{
//
//	return Instance;
//}
//void Reset::OnPaint(HDC hdc)
//{
//
//}
//void Reset::OnTimer()
//{
//
//}
//void Reset::ChangeState()
//{
//	mMainSence->SetState(GameStart::GetInstance());
//}
//#pragma endregion

#pragma region GameEnd_Realize
GameEnd* GameEnd::Instance = nullptr;

void GameEnd::Create(MINI_GAME* mMainSence)
{
	if (Instance == nullptr)
		Instance = new GameEnd();
	Instance->mMainSence = mMainSence;
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
	char temp[20];
	wsprintf(temp, "Score : %d", mMainSence->Score);
	TextOut(hdc, mMainSence->GetRt().right / 2, mMainSence->GetRt().bottom / 2, "Game Over", lstrlen("Game Over"));
	TextOut(hdc, mMainSence->GetRt().right / 2, mMainSence->GetRt().bottom / 2 + 20, temp, lstrlen(temp));
}
void GameEnd::OnTimer()
{

}
void GameEnd::ChangeState()
{
	Title::GetInstance()->reset();
	mMainSence->logic = LOGICS::TITLE;
	mMainSence->SetFlag(FALSE);
	mMainSence->SetState(Title::GetInstance());
}
#pragma endregion

