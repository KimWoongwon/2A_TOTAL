#include "SignupState.h"
#include "LoginSystem.h" 


void CSignupState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		GETWINDOWINST->ResetText();

		GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(FALSE);
		GETWINDOWINST->GetEditControl(ID_EDIT2)->SetVisable(FALSE);
		GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(FALSE);
		GETWINDOWINST->GetStaticText(ID_STATIC2)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(FALSE);
		
		if(wparam == ID_BUTTON1)
			GetSystem()->SetNowState(GetSystem()->GetTitleState());
		else if(wparam == ID_BUTTON2)
			GetSystem()->SetNowState(GetSystem()->GetTitleState());
	}

}
void CSignupState::InitializeProcess()
{
	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GETWINDOWINST->GetEditControl(ID_EDIT2)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(TRUE);

	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetPosition(240, 20, 150, 25);
	GETWINDOWINST->GetEditControl(ID_EDIT2)->SetPosition(240, 50, 150, 25);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetPosition(150, 20, 90, 25);
	GETWINDOWINST->GetStaticText(ID_STATIC2)->SetPosition(150, 50, 90, 25);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetPosition(400, 20, 80, 25);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetPosition(400, 50, 80, 25);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetText(TEXT("사용할 ID : "));
	GETWINDOWINST->GetStaticText(ID_STATIC2)->SetText(TEXT("사용할 PW : "));
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetCaption(TEXT("확인"));
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetCaption(TEXT("돌아가기"));

}

void CSignupState::TimerProcess()
{
}

CSignupState::CSignupState(CLoginSystem* _game) :CGameState(_game)
{
}

CSignupState::~CSignupState()
{
}
void CSignupState::ClickProcess()
{
	//GetSystem()->SetNowState(GetSystem()->GetPlayState());
}