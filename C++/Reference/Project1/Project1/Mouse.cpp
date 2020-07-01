#include "Mouse.h"
Mouse* Mouse::Instance = nullptr;
void Mouse::Create()
{
	if (Instance == nullptr)
		Instance = new Mouse();
}
void Mouse::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
Mouse* Mouse::GetInstance()
{
	if (Instance != nullptr)
		return Instance;
}

void Mouse::Initalize()
{
	NowPos.x = 0;
	NowPos.y = 0;
	PrePos.x = 0;
	PrePos.y = 0;
	handle = NULL;
	isClicked = false;
	resetFlag = true;
}
void Mouse::SetMousePos(LPARAM lParam, HWND Nhwnd)
{
	if (resetFlag)
	{
		PrePos.x = NowPos.x = LOWORD(lParam);
		PrePos.y = NowPos.y = HIWORD(lParam);
		resetFlag = false;
		return;
	}

	PrePos.x = NowPos.x;
	PrePos.y = NowPos.y;
	NowPos.x = LOWORD(lParam);
	NowPos.y = HIWORD(lParam);

}
void Mouse::PosReset()
{
	resetFlag = true;
}
void Mouse::SetClicked(bool pbool)
{
	isClicked = pbool;
}

POINT Mouse::GetNowPos()
{
	return NowPos;
}
POINT Mouse::GetPrePos()
{
	return PrePos;
}
bool Mouse::GetClicked()
{
	return isClicked;
}