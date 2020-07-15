#include "CreateState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CCreateState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(FALSE);
		GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(FALSE);
		GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(FALSE);
		GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(FALSE);
		GETWINDOWINST->GetGroupBox(ID_GROUP1)->SetVisable(FALSE);
		GETWINDOWINST->GetGroupBox(ID_GROUP2)->SetVisable(FALSE);
		GETWINDOWINST->GetRadioButton(ID_RADIO1)->SetVisable(FALSE);
		GETWINDOWINST->GetRadioButton(ID_RADIO2)->SetVisable(FALSE);
		GETWINDOWINST->GetRadioButton(ID_RADIO3)->SetVisable(FALSE);
		GETWINDOWINST->GetRadioButton(ID_RADIO4)->SetVisable(FALSE);
		GETWINDOWINST->GetRadioButton(ID_RADIO5)->SetVisable(FALSE);
		GETWINDOWINST->GetRadioButton(ID_RADIO6)->SetVisable(FALSE);
		
		if (wparam == ID_BUTTON1)
		{
			GetSystem()->SetNowState(GetSystem()->GetUserMenuState());
		}
		else if (wparam == ID_BUTTON2)
			GetSystem()->SetNowState(GetSystem()->GetUserMenuState());

		GETWINDOWINST->ResetText();
	}

}
void CCreateState::InitializeProcess()
{
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);

	GETWINDOWINST->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GETWINDOWINST->GetGroupBox(ID_GROUP1)->SetVisable(TRUE);
	GETWINDOWINST->GetGroupBox(ID_GROUP2)->SetVisable(TRUE);
	GETWINDOWINST->GetRadioButton(ID_RADIO1)->SetVisable(TRUE);
	GETWINDOWINST->GetRadioButton(ID_RADIO2)->SetVisable(TRUE);
	GETWINDOWINST->GetRadioButton(ID_RADIO3)->SetVisable(TRUE);
	GETWINDOWINST->GetRadioButton(ID_RADIO4)->SetVisable(TRUE);
	GETWINDOWINST->GetRadioButton(ID_RADIO5)->SetVisable(TRUE);
	GETWINDOWINST->GetRadioButton(ID_RADIO6)->SetVisable(TRUE);
	
	GETWINDOWINST->GetButton(ID_BUTTON1)->SetPosition(400, 10, 80, 80);
	GETWINDOWINST->GetButton(ID_BUTTON2)->SetPosition(400, 100, 80, 80);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 60, 25);
	GETWINDOWINST->GetEditControl(ID_EDIT1)->SetPosition(80, 10, 150, 25);

	GETWINDOWINST->GetGroupBox(ID_GROUP1)->SetPosition(15, 45, 90, 125);
	GETWINDOWINST->GetRadioButton(ID_RADIO1)->SetPosition(20,65,80,30);
	GETWINDOWINST->GetRadioButton(ID_RADIO2)->SetPosition(20,95,80,30);
	GETWINDOWINST->GetRadioButton(ID_RADIO3)->SetPosition(20,125,80,30);

	GETWINDOWINST->GetGroupBox(ID_GROUP2)->SetPosition(115, 45, 90, 125);
	GETWINDOWINST->GetRadioButton(ID_RADIO4)->SetPosition(120,65,80,30);
	GETWINDOWINST->GetRadioButton(ID_RADIO5)->SetPosition(120,95,80,30);
	GETWINDOWINST->GetRadioButton(ID_RADIO6)->SetPosition(120,125,80,30);

	GETWINDOWINST->GetStaticText(ID_STATIC1)->SetText(TEXT("닉네임 : "));
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


