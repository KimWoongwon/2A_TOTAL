#include "UserMenuState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CUserMenuState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 || wparam == ID_BUTTON3 || wparam == ID_BUTTON4 || wparam == ID_BUTTON5)
	{
		if (wparam == ID_BUTTON1)	// �α׾ƿ�
		{
			GetSystem()->Logout();
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::TITLE_STATE));
		}
		else if (wparam == ID_BUTTON2)	// ĳ���� ����
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::CREATE_STATE));
		}
		else if (wparam == ID_BUTTON3)	// ĳ���� ����
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::DELETE_STATE));
		}
		else if (wparam == ID_BUTTON4)	// ���� �̵�
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::STORE_STATE));
		}
		else if (wparam == ID_BUTTON5)	// �κ��丮
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);
			if (GetSystem()->CharacterSetting(str))
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());

				GetInst(CWindowFrame)->ResetText();
				GetInst(CWindowFrame)->ResetVisable();
				GetSystem()->SetNowState(GetSystem()->GetState(STATE::SHOW_STATE));
			}
			else
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("ĳ���Ͱ� �������� �ʽ��ϴ�."), TEXT("����!"), NULL);

		}
	}
}

void CUserMenuState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetAlignment(Alignment::Right);

	GetInst(CWindowFrame)->GetListBox(ID_LIST1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON5)->SetVisable(TRUE);

	GetInst(CWindowFrame)->GetListBox(ID_LIST1)->SetPosition(10, 40, 465, 290);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 380, 25);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(10, 335, 100, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(120, 335, 355, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(395, 10, 80, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(10, 370, 105, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetPosition(130, 370, 105, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetPosition(250, 370, 105, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON5)->SetPosition(370, 370, 105, 80);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("ĳ���� ���"));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("ĳ���� ���� : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("�α׾ƿ�"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("ĳ���ͻ���"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetCaption(TEXT("ĳ���ͻ���"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetCaption(TEXT("���� �̵�"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON5)->SetCaption(TEXT("�κ��丮"));
}

CUserMenuState::CUserMenuState(CLoginSystem* _game) :CGameState(_game)
{

}

CUserMenuState::~CUserMenuState()
{

}


