#include "SignupState.h"
#include "LoginSystem.h" 
#include "../Windows/WindowFrame.h"

void CSignupState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		if (wparam == ID_BUTTON1)	// Ȯ��
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
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�ߺ��� ���̵� �Դϴ�."), TEXT("����!"), NULL);
		}
		else if (wparam == ID_BUTTON2)	// ���ư���
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

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("����� ID : "));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("����� PW : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("Ȯ��"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("���ư���"));

}

CSignupState::CSignupState(CLoginSystem* _game) :CGameState(_game)
{
}

CSignupState::~CSignupState()
{
}
