#include "../State/LoginSystem.h" 
#include "WindowFrame.h"


CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame();
	}

	mPthis->mhInstance=_hinstance;	

	return mPthis;
}

CWindowFrame* CWindowFrame::GetInstance()
{	
	return mPthis;
}

void CWindowFrame::Destroy()
{
	if(mPthis)
	{
		delete mPthis;
		mPthis=NULL;
	}
}

LRESULT CALLBACK CWindowFrame::WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;		

	CLoginSystem* game = CLoginSystem::GetInstance();
	
	switch (iMessage)
	{
	case WM_CREATE:
		MoveWindow(hWnd, 200, 200, 500, 500, TRUE);
		return 0;		
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = 500;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = 500;
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 500;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 500;
		return 0;
	case WM_COMMAND:
		game->ButtonProcess(wParam);
		return 0;
	case WM_DESTROY:		
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void CWindowFrame::Run(MSG _Message)
{
	TranslateMessage(&_Message);
	DispatchMessage(&_Message);
}

void CWindowFrame::Initialize()
{
	mPthis->BuildWindow();

	Text01 = new CStaticText(190, 20, 50, 25, ID_STATIC1, TEXT("ID : "));
	IdEdit = new CEditControl(240, 20, 150, 25, ID_EDIT1);
	Text02 = new CStaticText(190, 50, 50, 25, ID_STATIC2, TEXT("PW : "));
	PwEdit = new CEditControl(240, 50, 150, 25, ID_EDIT2);

	CharacterList = new CListBox(10, 10, 380, 360, ID_LIST1);
	MakeColumn(ID_LIST1);
	ShowInvantory = new CListBox(10, 10, 380, 360, ID_LIST2);
	MakeColumn(ID_LIST2);

	Region = new CGroupBox(TEXT("종족"),10, 10, 10, 10, ID_GROUP1);
	Class = new CGroupBox(TEXT("직업"), 10, 10, 10, 10, ID_GROUP2);

	RegionSelect[0] = new CRadioButton(TEXT("인간"), 0, 0, 100, 20, ID_RADIO1, FALSE);
	RegionSelect[1] = new CRadioButton(TEXT("오크"), 0, 0, 100, 20, ID_RADIO2, FALSE);
	RegionSelect[2] = new CRadioButton(TEXT("엘프"), 0, 0, 100, 20, ID_RADIO3, TRUE);
	CheckRadioButton(mhWnd, ID_RADIO1, ID_RADIO3, ID_RADIO1);

	ClassSelect[0] = new CRadioButton(TEXT("전사"), 0, 0, 100, 20, ID_RADIO4, FALSE);
	ClassSelect[1] = new CRadioButton(TEXT("궁수"), 0, 0, 100, 20, ID_RADIO5, FALSE);
	ClassSelect[2] = new CRadioButton(TEXT("마법사"), 0, 0, 100, 20, ID_RADIO6, TRUE);
	CheckRadioButton(mhWnd, ID_RADIO4, ID_RADIO6, ID_RADIO4);

	mButton[0] = new CPushButton(400, 20, 80, 25, ID_BUTTON1);
	mButton[1] = new CPushButton(400, 50, 80, 25, ID_BUTTON2);
	mButton[2] = new CPushButton(400, 90, 80, 25, ID_BUTTON3);
	mButton[3] = new CPushButton(400, 130, 80, 25, ID_BUTTON4);
	mButton[4] = new CPushButton(400, 170, 80, 25, ID_BUTTON5);

	RECT crt;
	GetClientRect(CWindowFrame::GetInstance()->GethWnd(), &crt);
}

void CWindowFrame::BuildWindow()
{	
	WNDCLASS WndClass;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=CWindowFrame::GetInstance()->mhInstance;
	WndClass.lpfnWndProc=CWindowFrame::GetInstance()->WndProc;
	WndClass.lpszClassName=TEXT("exam");
	WndClass.lpszMenuName=nullptr;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}

HWND CWindowFrame::GethWnd()
{
	return mhWnd;
}
HINSTANCE CWindowFrame::GetInstanceHandle()
{
	return mhInstance;
}

CWindowFrame::CWindowFrame()
{
	IdEdit = nullptr;
	PwEdit = nullptr;
	Text01 = nullptr;
	Text02 = nullptr;

	Region = nullptr;
	Class = nullptr;

	CharacterList = nullptr;
	ShowInvantory = nullptr;

	for (int i = 0; i < 5; i++)
		mButton[i] = nullptr;

	for (int i = 0; i < 3; i++)
	{
		RegionSelect[i] = nullptr;
		ClassSelect[i] = nullptr;
	}


}
CWindowFrame::~CWindowFrame()
{

	if (IdEdit != nullptr)
		delete IdEdit;

	if (PwEdit != nullptr)
		delete PwEdit;

	if (Text01 != nullptr)
		delete Text01;

	if (Text02 != nullptr)
		delete Text02;

	if (Region != nullptr)
		delete Region;

	if (Class != nullptr)
		delete Class;

	if (CharacterList != nullptr)
		delete CharacterList;

	if (ShowInvantory != nullptr)
		delete ShowInvantory;

	for (int i = 0; i < 5; i++)
	{
		if (mButton[i] != nullptr)
			delete mButton[i];
	}

	for (int i = 0; i < 3; i++)
	{
		if (RegionSelect[i] != nullptr)
			RegionSelect[i] = nullptr;
		if (ClassSelect[i] != nullptr)
			ClassSelect[i] = nullptr;
	}
}

void CWindowFrame::ResetText()
{
	Text01->ResetControl();
	Text02->ResetControl();
	IdEdit->ResetControl();
	PwEdit->ResetControl();
}

void CWindowFrame::ResetVisable()
{
	Text01->SetVisable(FALSE);
	Text02->SetVisable(FALSE);

	IdEdit->SetVisable(FALSE);
	PwEdit->SetVisable(FALSE);

	CharacterList->SetVisable(FALSE);
	ShowInvantory->SetVisable(FALSE);
	Region->SetVisable(FALSE);
	Class->SetVisable(FALSE);

	for (int i = 0; i < 3; i++)
	{
		RegionSelect[i]->SetVisable(FALSE);
		ClassSelect[i]->SetVisable(FALSE);
	}

	for (int i = 0; i < 5; i++)
	{
		mButton[i]->SetVisable(FALSE);
	}
	
}


CPushButton* CWindowFrame::GetButton(int ID)
{
	switch (ID)
	{
	case ID_BUTTON1:
		return mButton[0];
	case ID_BUTTON2:
		return mButton[1];
	case ID_BUTTON3:
		return mButton[2];
	case ID_BUTTON4:
		return mButton[3];
	case ID_BUTTON5:
		return mButton[4];
	}
	return nullptr;
}

CEditControl* CWindowFrame::GetEditControl(int ID)
{
	switch (ID)
	{
	case ID_EDIT1:
		return IdEdit;
	case ID_EDIT2:
		return PwEdit;
	}
	return  nullptr;
}
CStaticText* CWindowFrame::GetStaticText(int ID)
{
	switch (ID)
	{
	case ID_STATIC1:
		return Text01;
	case ID_STATIC2:
		return Text02;
	}
	return nullptr;
}

CListBox* CWindowFrame::GetListBox(int ID)
{
	switch (ID)
	{
	case ID_LIST1:
		return CharacterList;
	case ID_LIST2:
		return ShowInvantory;
	}
	
}

CRadioButton* CWindowFrame::GetRadioButton(int ID)
{
	switch (ID)
	{
	case ID_RADIO1:
		return RegionSelect[0];
	case ID_RADIO2:
		return RegionSelect[1];
	case ID_RADIO3:
		return RegionSelect[2];
	case ID_RADIO4:
		return ClassSelect[0];
	case ID_RADIO5:
		return ClassSelect[1];
	case ID_RADIO6:
		return ClassSelect[2];
	}
	return nullptr;
}

CGroupBox* CWindowFrame::GetGroupBox(int ID)
{
	switch (ID)
	{
	case ID_GROUP1:
		return Region;
	case ID_GROUP2:
		return Class;
	}
	return nullptr;
}

void CWindowFrame::InsertCharData(Character* _char)
{
	LVITEM item;
	HWND hList = GetDlgItem(mhWnd, ID_LIST1);

	char str[20];
	int idx;
	idx = ListView_GetItemCount(hList); // 행번호를 가져오는 함수

	item.mask = LVIF_TEXT;
	item.iItem = idx;
	item.iSubItem = 0;
	item.pszText = _char->GetName();
	ListView_InsertItem(hList, &item);
	ListView_SetItemText(hList, idx, 1, _char->GetRegion());
	ListView_SetItemText(hList, idx, 2, _char->GetClass());
	_itoa_s(_char->GetStatus()->Hp, str, 10);
	ListView_SetItemText(hList, idx, 3, str);
	_itoa_s(_char->GetStatus()->Mp, str, 10);
	ListView_SetItemText(hList, idx, 4, str);
	_itoa_s(_char->GetStatus()->ATK, str, 10);
	ListView_SetItemText(hList, idx, 5, str);
	_itoa_s(_char->GetStatus()->DEF, str, 10);
	ListView_SetItemText(hList, idx, 6, str);
}

void CWindowFrame::InsertCharItemData(Character* pChar)
{
	LVITEM item;
	HWND hList = GetDlgItem(mhWnd, ID_LIST2);

	char str[20];
	int idx;

	if (pChar->GetWeapon() == nullptr)
	{
		idx = ListView_GetItemCount(hList); // 행번호를 가져오는 함수
		item.mask = LVIF_TEXT;
		item.iItem = idx;
		item.iSubItem = 0;
		item.pszText = "착용정보 없음";
		ListView_InsertItem(hList, &item);
		ListView_SetItemText(hList, idx, 1, "");
		ListView_SetItemText(hList, idx, 2, "");
		ListView_SetItemText(hList, idx, 3, "");
		ListView_SetItemText(hList, idx, 4, "");
		ListView_SetItemText(hList, idx, 5, "");
		ListView_SetItemText(hList, idx, 6, "");
	}
	else
	{
		idx = ListView_GetItemCount(hList); // 행번호를 가져오는 함수
		item.mask = LVIF_TEXT;
		item.iItem = idx;
		item.iSubItem = 0;
		item.pszText = pChar->GetWeapon()->GetName();
		ListView_InsertItem(hList, &item);
		ListView_SetItemText(hList, idx, 1, "착용중 / 무기");
		_itoa_s(pChar->GetWeapon()->GetPrice(), str, 10);
		ListView_SetItemText(hList, idx, 2, str);
		_itoa_s(pChar->GetWeapon()->GetStatus()->Hp, str, 10);
		ListView_SetItemText(hList, idx, 3, str);
		_itoa_s(pChar->GetWeapon()->GetStatus()->Mp, str, 10);
		ListView_SetItemText(hList, idx, 4, str);
		_itoa_s(pChar->GetWeapon()->GetStatus()->ATK, str, 10);
		ListView_SetItemText(hList, idx, 5, str);
		_itoa_s(pChar->GetWeapon()->GetStatus()->DEF, str, 10);
		ListView_SetItemText(hList, idx, 6, str);
	}
	
	if (pChar->GetArmor() == nullptr)
	{
		idx = ListView_GetItemCount(hList); // 행번호를 가져오는 함수
		item.mask = LVIF_TEXT;
		item.iItem = idx;
		item.iSubItem = 0;
		item.pszText = "착용정보 없음";
		ListView_InsertItem(hList, &item);
		ListView_SetItemText(hList, idx, 1, "");
		ListView_SetItemText(hList, idx, 2, "");
		ListView_SetItemText(hList, idx, 3, "");
		ListView_SetItemText(hList, idx, 4, "");
		ListView_SetItemText(hList, idx, 5, "");
		ListView_SetItemText(hList, idx, 6, "");
	}
	else
	{
		idx = ListView_GetItemCount(hList);
		item.mask = LVIF_TEXT;
		item.iItem = idx;
		item.iSubItem = 0;
		item.pszText = pChar->GetArmor()->GetName();
		ListView_InsertItem(hList, &item);
		ListView_SetItemText(hList, idx, 1, "착용중 / 방어구");
		_itoa_s(pChar->GetArmor()->GetPrice(), str, 10);
		ListView_SetItemText(hList, idx, 2, str);
		_itoa_s(pChar->GetArmor()->GetStatus()->Hp, str, 10);
		ListView_SetItemText(hList, idx, 3, str);
		_itoa_s(pChar->GetArmor()->GetStatus()->Mp, str, 10);
		ListView_SetItemText(hList, idx, 4, str);
		_itoa_s(pChar->GetArmor()->GetStatus()->ATK, str, 10);
		ListView_SetItemText(hList, idx, 5, str);
		_itoa_s(pChar->GetArmor()->GetStatus()->DEF, str, 10);
		ListView_SetItemText(hList, idx, 6, str);
	}
	

	int count = pChar->GetInventory()->GetCount();
	Item* temp = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (pChar->GetInventory()->GetData(&temp))
		{
			idx = ListView_GetItemCount(hList);
			item.mask = LVIF_TEXT;
			item.iItem = idx;
			item.iSubItem = 0;
			item.pszText = temp->GetName();
			ListView_InsertItem(hList, &item);
			if (temp->GetTypeCode() == ITEMTYPE::WEAPONE)
				ListView_SetItemText(hList, idx, 1, "무기");
			if (temp->GetTypeCode() == ITEMTYPE::ARMOR)
				ListView_SetItemText(hList, idx, 1, "방어구");
			_itoa_s(temp->GetPrice(), str, 10);
			ListView_SetItemText(hList, idx, 2, str);
			_itoa_s(temp->GetStatus()->Hp, str, 10);
			ListView_SetItemText(hList, idx, 3, str);
			_itoa_s(temp->GetStatus()->Mp, str, 10);
			ListView_SetItemText(hList, idx, 4, str);
			_itoa_s(temp->GetStatus()->ATK, str, 10);
			ListView_SetItemText(hList, idx, 5, str);
			_itoa_s(temp->GetStatus()->DEF, str, 10);
			ListView_SetItemText(hList, idx, 6, str);
		}
	}
	pChar->GetInventory()->GetDataEnd();
}

void CWindowFrame::InsertStoreData(CLASS _cls, ITEMTYPE _type)
{
	LVITEM item;
	HWND hList = GetDlgItem(mhWnd, ID_LIST2);

	char str[20];
	int idx;
	int count = GetInst(ItemDataBase)->GetCount();
	Item* temp = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (GetInst(ItemDataBase)->GetData(&temp))
		{
			if (temp->GetClassCode() == _cls && temp->GetTypeCode() == _type)
			{
				idx = ListView_GetItemCount(hList);
				item.mask = LVIF_TEXT;
				item.iItem = idx;
				item.iSubItem = 0;
				item.pszText = temp->GetName();
				ListView_InsertItem(hList, &item);
				if(temp->GetTypeCode() == ITEMTYPE::WEAPONE)
					ListView_SetItemText(hList, idx, 1, "무기");
				if (temp->GetTypeCode() == ITEMTYPE::ARMOR)
					ListView_SetItemText(hList, idx, 1, "방어구");

				_itoa_s(temp->GetPrice(), str, 10);
				ListView_SetItemText(hList, idx, 2, str);
				_itoa_s(temp->GetStatus()->Hp, str, 10);
				ListView_SetItemText(hList, idx, 3, str);
				_itoa_s(temp->GetStatus()->Mp, str, 10);
				ListView_SetItemText(hList, idx, 4, str);
				_itoa_s(temp->GetStatus()->ATK, str, 10);
				ListView_SetItemText(hList, idx, 5, str);
				_itoa_s(temp->GetStatus()->DEF, str, 10);
				ListView_SetItemText(hList, idx, 6, str);
			}
		}
	}
	GetInst(ItemDataBase)->GetDataEnd();
}

void CWindowFrame::RemoveAllData(int ID)
{
	HWND hList = GetDlgItem(mhWnd, ID);
	ListView_DeleteAllItems(hList);
}

void CWindowFrame::MakeColumn(int ID) // 컬럼 생성 함수
{
	char* name[7] = {};
	int size[7] = { 70,50,50,50,50,50,50 };
	int idx = 7;
	if (ID == ID_LIST1)
	{
		name[0] = (char*)"닉네임";
		name[1] = (char*)"종족";
		name[2] = (char*)"직업";
		name[3] = (char*)"체력";
		name[4] = (char*)"마력";
		name[5] = (char*)"공격력";
		name[6] = (char*)"방어력";
	}
	else if(ID == ID_LIST2)
	{
		name[0] = (char*)"이름";
		name[1] = (char*)"분류";
		name[2] = (char*)"가격";
		name[3] = (char*)"체력";
		name[4] = (char*)"마력";
		name[5] = (char*)"공격력";
		name[6] = (char*)"방어력";
		size[0] = 90;
	}
	LVCOLUMN lvCol = { 0, }; // LV = ListView의 약자
	int i;
	HWND hList = GetDlgItem(mhWnd, ID);
	// LVCF = List View Column Format
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; // 컬럼의 항목을 내가 지정해주겠다고 미리 정해주는 부분
	lvCol.fmt = LVCFMT_LEFT; // 각 컬럼의 포멧 (왼쪽 정렬)

	for (i = 0; i < idx; i++)
	{
		lvCol.cx = size[i]; // 각 컬럼의 좌우 크기 (픽셀단위)
		lvCol.pszText = name[i]; // 각 컬럼의 이름 (텍스트)
		lvCol.iSubItem = i; // 각 칼럼의 인덱스값 (열 번호)

		// 셋팅한 lvCol 을 LVM_INSERTCOLUMN을 이용해 넣어주는 부분
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}
