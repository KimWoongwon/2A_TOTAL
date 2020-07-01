#include "Menu.h"
Menu* Menu::Instance = nullptr;
Menu::Menu()
{

}
Menu::~Menu()
{

}
void Menu::Create()
{
	if (Instance == nullptr)
		Instance = new Menu();
}
void Menu::Initialize(HWND p_hWnd)
{
	//Menu::GetInstance()->SetMyID(0);
	Menu::GetInstance()->SelectID = 0;
	Menu::GetInstance()->hWnd = p_hWnd;
}
void Menu::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
Menu* Menu::GetInstance()
{
	return Instance;
}

// 쓰기 접근 함수
//void Menu::SetMyID(int p_id)
//{
//	this->MyID = p_id;
//}
void Menu::SetSelectID(WPARAM wParam)
{
	this->SelectID = LOWORD(wParam);
}
void Menu::SetHWND(HWND p_hWnd)
{
	this->hWnd = p_hWnd;
}

// 읽기 접근 함수
//int Menu::GetMyID()
//{
//	return this->MyID;
//}
int Menu::GetSelectID()
{
	return this->SelectID;
}
HWND Menu::GetHWND()
{
	return this->hWnd;
}