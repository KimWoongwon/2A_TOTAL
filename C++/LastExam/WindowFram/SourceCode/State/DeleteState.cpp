#include "DeleteState.h"
#include "LoginSystem.h" 
#include "../Windows/WindowFrame.h"

void CDeleteState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		if (wparam == ID_BUTTON1)	// Ȯ��
		{
			char charstr[20];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(charstr, 20);
			if(!strcmp(charstr,""))
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�г����� �Է��� �ּ���"), TEXT("����!"), NULL);
			else
			{
				GetSystem()->RemoveCharacter(charstr);

				GetInst(CWindowFrame)->ResetText();
				GetInst(CWindowFrame)->ResetVisable();
				GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
			}
		}
		else if (wparam == ID_BUTTON2)	// ���ư���
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
		}

	}

}
void CDeleteState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetAlignment(Alignment::Right);

	GetInst(CWindowFrame)->GetListBox(ID_LIST1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);


	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 465, 25);
	GetInst(CWindowFrame)->GetListBox(ID_LIST1)->SetPosition(10, 40, 465, 290);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(10, 335, 100, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(120, 335, 355, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(10, 370, 230, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(245, 370, 230, 80);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("ĳ���� ����"));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("������ ĳ���� : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("����"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("���ư���"));

}

CDeleteState::CDeleteState(CLoginSystem* _game) :CGameState(_game)
{
}

CDeleteState::~CDeleteState()
{
}
