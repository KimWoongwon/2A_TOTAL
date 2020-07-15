#include "CreateState.h"
#include "LoginSystem.h"

void CCreateState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		GETWINDOWINST->ResetText();

		GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(FALSE);
		GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(FALSE);
		GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(FALSE);
		
		if (wparam == ID_BUTTON1)
			GetSystem()->SetNowState(GetSystem()->GetUserMenuState());
		else if (wparam == ID_BUTTON2)
			GetSystem()->SetNowState(GetSystem()->GetUserMenuState());
	}

}
void CCreateState::InitializeProcess()
{
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(TRUE);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 50, 25);
	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetPosition(60, 10, 150, 25);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetPosition(400, 10, 80, 80);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetPosition(400, 100, 80, 80);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetText(TEXT("닉네임"));
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetCaption(TEXT("생성"));
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetCaption(TEXT("취소"));
}
CCreateState::CCreateState(CLoginSystem* _game) :CGameState(_game)
{
}
CCreateState::~CCreateState()
{
}

void CCreateState::TimerProcess()
{

}
void CCreateState::ClickProcess()
{

}


