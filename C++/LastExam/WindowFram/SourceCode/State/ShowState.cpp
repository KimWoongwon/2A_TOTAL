#include "ShowState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CShowState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 || wparam == ID_BUTTON3 || wparam == ID_BUTTON4)
	{
		if (wparam == ID_BUTTON1)	// ������ ��ü
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);

			if (GetSystem()->ChangeItem(str) != 0)
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�������� ���� �߽��ϴ�."), TEXT(""), NULL);
			}
			else
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("ĳ���Ͱ� �������� �ʽ��ϴ�."), TEXT("����!"), NULL);
			}
		}
		else if (wparam == ID_BUTTON2)	// ��������
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);

			int result = GetSystem()->OffItem(str);

			if (result > 0)
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());

				if(result == (int)ITEMTYPE::WEAPONE)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("���⸦ ���� ���� �߽��ϴ�."), TEXT(""), NULL);
				else if (result == (int)ITEMTYPE::ARMOR)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("���� ���� ���� �߽��ϴ�."), TEXT(""), NULL);
			}
			else if(result <= 0)
			{
				if(result == -1)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�������� ���Ⱑ �����ϴ�."), TEXT("����!"), NULL);
				else if (result == -2)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�������� ���� �����ϴ�."), TEXT("����!"), NULL);
				else
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�������� �����۰� ��ġ���� �ʽ��ϴ�."), TEXT("����!"), NULL);
			}
		}
		else if (wparam == ID_BUTTON3)	// ����
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);

			int result = GetSystem()->OnItem(str);

			if (result != 0)
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());

				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�������� ���� �߽��ϴ�."), TEXT(""), NULL);
			}
			else
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("�κ��丮�� ���ų� �������� �������Դϴ�."), TEXT("����!"), NULL);
			}
		}
		else if (wparam == ID_BUTTON4)	// ���ư���
		{
			GetInst(CWindowFrame)->RemoveAllData(ID_LIST1);
			GetSystem()->ShowAllCharacter();
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::MENU_STATE));
		}
	}

}
void CShowState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetAlignment(Alignment::Right);

	GetInst(CWindowFrame)->GetListBox(ID_LIST2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetVisable(TRUE);

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 465, 25);
	GetInst(CWindowFrame)->GetListBox(ID_LIST2)->SetPosition(10, 40, 465, 290);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(10, 335, 100, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(120, 335, 355, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(10, 370, 105, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(130, 370, 105, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetPosition(250, 370, 105, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetPosition(370, 370, 105, 80);

	char str[200];
	wsprintf(str, "���� ĳ���� : %s", GetSystem()->GetNowCharacter()->GetName());

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(str);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("������ ���� : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("�����۱�ü"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("��������"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetCaption(TEXT("����"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetCaption(TEXT("���ư���"));
}

CShowState::CShowState(CLoginSystem* _game) :CGameState(_game)
{
}
CShowState::~CShowState()
{
}

