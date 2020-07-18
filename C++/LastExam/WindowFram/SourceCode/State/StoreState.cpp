#include "StoreState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CStoreState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 || wparam == ID_BUTTON3)
	{
		if (wparam == ID_BUTTON1)	// ������ ����
		{
			char str[20];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 20);

			if (GetSystem()->CharacterSetting(str))
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertStoreData(GetSystem()->GetNowCharacter()->GetClassType(), ITEMTYPE::WEAPONE);
				GetInst(CWindowFrame)->InsertStoreData(GetSystem()->GetNowCharacter()->GetClassType(), ITEMTYPE::ARMOR);

				GetInst(CWindowFrame)->ResetText();
				GetInst(CWindowFrame)->ResetVisable();
				GetSystem()->SetNowState(GetSystem()->GetState(STATE::BUY_STATE));
			}
			else
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("ĳ���Ͱ� �������� �ʽ��ϴ�."), TEXT("����!"), NULL);
			
		}
		else if (wparam == ID_BUTTON2)	// ������ �Ǹ�
		{
			char str[20];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 20);

			if (GetSystem()->CharacterSetting(str))
			{
				// ������ �κ��丮 ���� �Է��ϱ�
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());
				GetInst(CWindowFrame)->ResetText();
				GetInst(CWindowFrame)->ResetVisable();
				GetSystem()->SetNowState(GetSystem()->GetState(STATE::SELL_STATE));
			}
			else
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("ĳ���Ͱ� �������� �ʽ��ϴ�."), TEXT("����!"), NULL);
		}
		else if (wparam == ID_BUTTON3)	// ���ư���
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
		}
	}

}
void CStoreState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetAlignment(Alignment::Right);

	GetInst(CWindowFrame)->GetListBox(ID_LIST1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetVisable(TRUE);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 465, 25);
	GetInst(CWindowFrame)->GetListBox(ID_LIST1)->SetPosition(10, 40, 465, 290);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(10, 335, 100, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(120, 335, 355, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(10, 370, 140, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(175, 370, 140, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetPosition(335, 370, 140, 80);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("������ ����"));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("ĳ���� ���� : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("�����۱���"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("�������Ǹ�"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetCaption(TEXT("���ư���"));
}

CStoreState::CStoreState(CLoginSystem* _game) :CGameState(_game)
{
}
CStoreState::~CStoreState()
{
}
