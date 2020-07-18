#include "SignupState.h"
#include "LoginSystem.h" 
#include "../Windows/WindowFrame.h"

void CSignupState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		if (wparam == ID_BUTTON1)	// 확인
		{
			char mID[20];
			char mPW[20];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(mID, 20);
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->GetText(mPW, 20);
			/*GetWindowText(GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetHandle(), mID, 20);
			GetWindowText(GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->GetHandle(), mPW, 20);*/
			if (GetSystem()->Signup(mID, mPW))
			{
				GetInst(CWindowFrame)->ResetText();
				GetInst(CWindowFrame)->ResetVisable();
				GetSystem()->SetNowState(GetSystem()->GetState(STATE::TITLE_STATE));
			}
			else
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("중복된 아이디 입니다."), TEXT("실패!"), NULL);
		}
		else if (wparam == ID_BUTTON2)	// 돌아가기
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::TITLE_STATE));
		}
			
	}

}
void CSignupState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);

	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(240, 20, 150, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->SetPosition(240, 50, 150, 25);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(150, 20, 90, 25);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(150, 50, 90, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(400, 20, 80, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(400, 50, 80, 25);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("사용할 ID : "));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("사용할 PW : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("확인"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("돌아가기"));

}

CSignupState::CSignupState(CLoginSystem* _game) :CGameState(_game)
{
}

CSignupState::~CSignupState()
{
}
