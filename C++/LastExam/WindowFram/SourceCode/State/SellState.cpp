#include "SellState.h"
#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"

void CSellState::ButtonProcess(WPARAM _wParam)
{
	int wparam = LOWORD(_wParam);
	if (wparam == ID_BUTTON1 || wparam == ID_BUTTON2)
	{
		if (wparam == ID_BUTTON1)	// 아이템 판매
		{
			char str[100];
			GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->GetText(str, 100);
			if (GetSystem()->SellItemToStore(str))
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("아이템 판매에 성공했습니다."), TEXT(""), NULL);
				GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->ResetControl();
			}
			else
			{
				MessageBox(GetInst(CWindowFrame)->GethWnd(), TEXT("아이템 판매에 실패했습니다."), TEXT(""), NULL);
			}
			char Gold[50];
			wsprintf(Gold, "판매\n보유골드 : %d", GetSystem()->GetUserMoney());
			GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT(Gold));
			GetInst(CWindowFrame)->RemoveAllData(ID_LIST2);
			GetInst(CWindowFrame)->InsertCharItemData(GetSystem()->GetNowCharacter());
		}
		else if (wparam == ID_BUTTON2)	// 돌아가기
		{
			GetInst(CWindowFrame)->ResetText();
			GetInst(CWindowFrame)->ResetVisable();
			GetSystem()->SetNowState(GetSystem()->GetState(STATE::STORE_STATE));
		}
	}

}
void CSellState::InitializeProcess()
{
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetAlignment(Alignment::Center);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetAlignment(Alignment::Right);

	GetInst(CWindowFrame)->GetListBox(ID_LIST2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetVisable(TRUE);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetVisable(TRUE);


	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetPosition(10, 10, 465, 25);
	GetInst(CWindowFrame)->GetListBox(ID_LIST2)->SetPosition(10, 40, 465, 290);
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetPosition(10, 335, 110, 25);
	GetInst(CWindowFrame)->GetEditControl(ID_EDIT1)->SetPosition(130, 335, 345, 25);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetPosition(10, 370, 230, 80);
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetPosition(245, 370, 230, 80);

	char str[100];
	wsprintf(str, "판매\n보유골드 : %d", GetSystem()->GetUserMoney());
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC1)->SetText(TEXT("아이템 판매"));
	GetInst(CWindowFrame)->GetStaticText(ID_STATIC2)->SetText(TEXT("판매할 아이템 : "));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON1)->SetCaption(TEXT(str));
	GetInst(CWindowFrame)->GetButton(ID_BUTTON2)->SetCaption(TEXT("돌아가기"));
}

CSellState::CSellState(CLoginSystem* _game) :CGameState(_game)
{
}
CSellState::~CSellState()
{
}

