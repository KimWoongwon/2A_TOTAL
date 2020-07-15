#include "ResultPlayState.h"
#include "LoginSystem.h"

CResultPlayState::CResultPlayState(CLoginSystem* _game) : CGameState(_game)
{

}


CResultPlayState::~CResultPlayState()
{
}

void CResultPlayState::TimerProcess()
{

}
void CResultPlayState::ClickProcess()
{

}
void CResultPlayState::InitializeProcess()
{	
	TCHAR  Result_Str[128];
	CWindowFrame::GetInstance()->GetButton(ID_BUTTON1)->SetCaption(TEXT("처음으로"));

	wsprintf(Result_Str, TEXT("성공 :%d "), GetSystem()->GetMatchCount());
	HDC hdc = CWindowFrame::GetInstance()->GetBackbit()->GetBitmapDC();
	TextOut(hdc, 300, 300, Result_Str, lstrlen(Result_Str));
	CWindowFrame::GetInstance()->GetBackbit()->DeleteBitmapDC(hdc);
	//InvalidateRect(CMouse::GetInstance()->GetHWnd(), NULL, false);
}

void CResultPlayState::ButtonProcess(WPARAM _wParam)
{
	switch (LOWORD(_wParam))
	{
	case ID_BUTTON1:
		GetSystem()->SetNowState(GetSystem()->GetTitleState());
		break;
	}
	
}
