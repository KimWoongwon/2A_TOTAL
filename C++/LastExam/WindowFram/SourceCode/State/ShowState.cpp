#include "ShowState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CShowState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2 || wparam == ID_BUTTON3 || wparam == ID_BUTTON4)
	{
		if (wparam == ID_BUTTON1)	// 아이템 교체
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);

			if (GetSystem()->ChangeItem(str) != 0)
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("아이템을 변경 했습니다."), TEXT(""), NULL);
			}
			else
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("캐릭터가 존재하지 않습니다."), TEXT("실패!"), NULL);
			}
		}
		else if (wparam == ID_BUTTON2)	// 장착해제
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);

			int result = GetSystem()->OffItem(str);

			if (result > 0)
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());

				if(result == (int)ITEMTYPE::WEAPONE)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("무기를 장착 해제 했습니다."), TEXT(""), NULL);
				else if (result == (int)ITEMTYPE::ARMOR)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("방어구를 장착 해제 했습니다."), TEXT(""), NULL);
			}
			else if(result <= 0)
			{
				if(result == -1)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("장착중인 무기가 없습니다."), TEXT("실패!"), NULL);
				else if (result == -2)
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("장착중인 방어구가 없습니다."), TEXT("실패!"), NULL);
				else
					MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("장착중인 아이템과 일치하지 않습니다."), TEXT("실패!"), NULL);
			}
		}
		else if (wparam == ID_BUTTON3)	// 장착
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);

			int result = GetSystem()->OnItem(str);

			if (result != 0)
			{
				GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
				GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());

				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("아이템을 장착 했습니다."), TEXT(""), NULL);
			}
			else
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("인벤토리에 없거나 장착중인 아이템입니다."), TEXT("실패!"), NULL);
			}
		}
		else if (wparam == ID_BUTTON4)	// 돌아가기
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
	wsprintf(str, "현재 캐릭터 : %s", GetSystem()->GetNowCharacter()->GetName());

	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(str);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("아이템 선택 : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT("아이템교체"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("장착해제"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON3)->SetCaption(TEXT("장착"));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON4)->SetCaption(TEXT("돌아가기"));
}

CShowState::CShowState(CLoginSystem* _game) :CGameState(_game)
{
}
CShowState::~CShowState()
{
}

