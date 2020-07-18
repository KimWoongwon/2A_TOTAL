#include "CreateState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"
#include "../Character/Elf/ElfFactory.h"
#include "../Character/Orc/OrcFactory.h"
#include "../Character/Human/HumanFactory.h"

void CCreateState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		if (wparam == ID_BUTTON1)	// 생성
		{
			CharacterFactory* Factory = nullptr;
			CLASS Choice = CLASS::NONE;
			char str[20];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 20);
			if (!strcmp(str, ""))
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("아이디를 입력해 주세요"), TEXT("실패!"), NULL);
			}
			else
			{
				if (GetInst(CWindowFrame)->GetRadioButton(ID_RADIO1)->GetCheckInfo())
					Factory = new HumanFactory();
				else if (GetInst(CWindowFrame)->GetRadioButton(ID_RADIO2)->GetCheckInfo())
					Factory = new OrcFactory();
				else if (GetInst(CWindowFrame)->GetRadioButton(ID_RADIO3)->GetCheckInfo())
					Factory = new ElfFactory();

				if (GetInst(CWindowFrame)->GetRadioButton(ID_RADIO4)->GetCheckInfo())
					Choice = CLASS::WARRIOR;
				else if (GetInst(CWindowFrame)->GetRadioButton(ID_RADIO5)->GetCheckInfo())
					Choice = CLASS::ARCHER;
				else if (GetInst(CWindowFrame)->GetRadioButton(ID_RADIO6)->GetCheckInfo())
					Choice = CLASS::SORCERER;

				if (GetSystem()->CreateCharacter(str, Factory, Choice))
				{
					delete Factory;
					GetInst(CWindowFrame)->ResetText();
					GetInst(CWindowFrame)->ResetVisable();
					GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
				}
				else
				{
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("중복된 닉네임 입니다."), TEXT("실패!"), NULL);
				}
				
			}
		}
		else if (wparam == ID_BUTTON2)	// 취소
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
		}
	}

}
void CCreateState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);

	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetGroupBox(ID_GROUP1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetGroupBox(ID_GROUP2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO3)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO4)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO5)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO6)->SetVisable(TRUE);
	
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(400, 10, 80, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(400, 100, 80, 80);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 60, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(80, 10, 150, 25);

	GetInst(CWindowFrame)->GetGroupBox(ID_GROUP1)->SetPosition(15, 45, 90, 125);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO1)->SetPosition(20,65,80,30);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO2)->SetPosition(20,95,80,30);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO3)->SetPosition(20,125,80,30);

	GetInst(CWindowFrame)->GetGroupBox(ID_GROUP2)->SetPosition(115, 45, 90, 125);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO4)->SetPosition(120,65,80,30);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO5)->SetPosition(120,95,80,30);
	GetInst(CWindowFrame)->GetRadioButton(ID_RADIO6)->SetPosition(120,125,80,30);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("닉네임 : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("생성"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("취소"));
}
CCreateState::CCreateState(CLoginSystem* _game) :CGameState(_game)
{
}
CCreateState::~CCreateState()
{
}



