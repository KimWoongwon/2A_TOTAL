#include "TitleState.h"
#include "LoginSystem.h" 


void CTitleState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 || wparam == ID_BUTTON3)
	{
		GETWINDOWINST->ResetText();

		GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(FALSE);
		GETWINDOWINST->GetEditControl(ID_EDIT2)->SetVisable(FALSE);
		GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(FALSE);
		GETWINDOWINST->GetStaticText(ID_STATIC2)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON3)->SetVisable(FALSE);

		if (wparam == ID_BUTTON1)
			GetSystem()->SetNowState(GetSystem()->GetUserMenuState());
		else if (wparam == ID_BUTTON2)
			GetSystem()->SetNowState(GetSystem()->GetSignupState());
		else if(wparam == ID_BUTTON3)
			SendMessage(CWindowFrame::GetInstance()->GethWnd(), WM_DESTROY, NULL, NULL);

		
	}	
}
void CTitleState::InitializeProcess()
{
	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GETWINDOWINST->GetEditControl(ID_EDIT2)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetVisable(TRUE);

	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetPosition(240,20,150,25);
	GETWINDOWINST->GetEditControl(ID_EDIT2)->SetPosition(240,50,150,25);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetPosition(190,20,50,25);
	GETWINDOWINST->GetStaticText(ID_STATIC2)->SetPosition(190,50,50,25);

	GETWINDOWINST->GetButton(ID_BUTTON1)->SetPosition(400, 20, 80, 25);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetPosition(400, 50, 80, 25);
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetPosition(400, 90, 80, 25);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetText(TEXT("ID : "));
	GETWINDOWINST->GetStaticText(ID_STATIC2)->SetText(TEXT("PW : "));
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetCaption(TEXT("로그인"));
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetCaption(TEXT("회원가입"));
	GETWINDOWINST->GetButton(ID_BUTTON3)->SetCaption(TEXT("종료"));

}

void CTitleState::TimerProcess()
{
}

CTitleState::CTitleState(CLoginSystem* _game) :CGameState(_game)
{
}

CTitleState::~CTitleState()
{
}
void CTitleState::ClickProcess()
{
	//GetSystem()->SetNowState(GetSystem()->GetPlayState());
}