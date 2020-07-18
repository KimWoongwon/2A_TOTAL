#include "TitleState.h"
#include "LoginSystem.h" 
#include "../Windows/WindowFrame.h"

void CTitleState::ButtonProcess(WPARAM _wParam)
{
	// 화면 전환시 사용했던 컨트롤 뿐만 아니라 모든 컨트롤을 비활성화 하고 
	// 세부적으로 필요한 내용들을 추가해서 구현했다.
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 || wparam == ID_BUTTON3)
	{
		int result = 1;
		if (wparam == ID_BUTTON1)	// 로그인
		{
			char mID[20];
			char mPW[20];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(mID, 20);
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->GetText(mPW, 20);

			result = GetSystem()->Login(mID, mPW);

			if (result == 1)
			{
				GetInst(CWindowFrame)->ResetText();
				GetInst(CWindowFrame)->ResetVisable();
				GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
			}
			
			else if (result == -1)
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("아이디가 일치하지 않습니다."), TEXT("실패"), NULL);
			else if(result == 0)
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("비밀번호가 일치하지 않습니다."), TEXT("실패"), NULL);
		}
		else if (wparam == ID_BUTTON2)	// 회원가입
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::SIGNUP_STATE));
		}
		else if(wparam == ID_BUTTON3)	// 종료
			SendMessage(GetInst(CWindowFrame)->GethWnd(), WM_DESTROY, NULL, NULL);

	}	
}
// 기본적으로 모든 상태에서 사용할 컨트롤 클래스들을 재설정 한다.
void CTitleState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Right);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetAlignment(Alignment::Right);

	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetVisable(TRUE);

	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(240,20,150,25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT2)->SetPosition(240,50,150,25);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(190,20,50,25);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(190,50,50,25);

	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(400, 20, 80, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(400, 50, 80, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetPosition(400, 90, 80, 25);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("ID : "));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("PW : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("로그인"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("회원가입"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetCaption(TEXT("종료"));

}

CTitleState::CTitleState(CLoginSystem* _game) :CGameState(_game)
{
}

CTitleState::~CTitleState()
{
}
