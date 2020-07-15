#include "UserMenuState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CUserMenuState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 
		|| wparam == ID_BUTTON3 || wparam == ID_BUTTON4)
	{
		GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(FALSE);
		GETWINDOWINST->GetListBox(ID_LIST1)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON3)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON4)->SetVisable(FALSE);
		
		if (wparam == ID_BUTTON1)
			GetSystem()->SetNowState(GetSystem()->GetTitleState());
		else if (wparam == ID_BUTTON2)
			GetSystem()->SetNowState(GetSystem()->GetCreateState());
		else if (wparam == ID_BUTTON3)
		{
			// CharacterDelete
		}
		else if (wparam == ID_BUTTON4)
			GetSystem()->SetNowState(GetSystem()->GetStoreState());
	}
}

void CUserMenuState::InitializeProcess()
{
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);

	GETWINDOWINST->GetListBox(ID_LIST1)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON4)->SetVisable(TRUE);

	GETWINDOWINST->GetListBox(ID_LIST1)->SetPosition(10, 40, 380, 330);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 380, 25);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetPosition(400, 20, 80, 25);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetPosition(10, 370, 150, 80);
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetPosition(170, 370, 150, 80);
	GETWINDOWINST->GetButton(ID_BUTTON4)->SetPosition(330, 370, 150, 80);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetText(TEXT("캐릭터 목록"));
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetCaption(TEXT("로그아웃"));
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetCaption(TEXT("캐릭터생성"));
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetCaption(TEXT("캐릭터삭제"));
	GETWINDOWINST->GetButton(ID_BUTTON4)->SetCaption(TEXT("상점 이동"));
}

CUserMenuState::CUserMenuState(CLoginSystem* _game) :CGameState(_game)
{

}

CUserMenuState::~CUserMenuState()
{

}

void CUserMenuState::TimerProcess()
{

}

void CUserMenuState::ClickProcess()
{

}




