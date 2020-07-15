#include "StoreState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

CStoreState::CStoreState(CLoginSystem* _game) :CGameState(_game)
{
}
CStoreState::~CStoreState()
{
}

void CStoreState::TimerProcess()
{
	
}
void CStoreState::ClickProcess()
{
	
}
void CStoreState::InitializeProcess()
{
	GETWINDOWINST->GetListBox(ID_LIST1)->SetVisable(FALSE);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(FALSE);

	GETWINDOWINST->GetButton(ID_BUTTON2)->SetPosition(10, 370, 150, 80);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetCaption(TEXT("아이템구입"));

	GETWINDOWINST->GetButton(ID_BUTTON3)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetPosition(170, 370, 150, 80);
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetCaption(TEXT("아이템판매"));


	GETWINDOWINST->GetButton(ID_BUTTON4)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON4)->SetPosition(330, 370, 150, 80);
	GETWINDOWINST->GetButton(ID_BUTTON4)->SetCaption(TEXT("돌아가기"));
}

void CStoreState::ButtonProcess(WPARAM _wParam)
{
	switch (LOWORD(_wParam))
	{
	case ID_BUTTON4:
		GetSystem()->SetNowState(GetSystem()->GetUserMenuState());
		break;
	}
	
}
