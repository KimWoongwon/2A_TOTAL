#include "DragDrawing.h"
#include "Mouse.h"
#include "Menu.h"
#include "resource.h"
DragDrawing* DragDrawing::Instance = nullptr;

DragDrawing::DragDrawing()
{

}
DragDrawing::~DragDrawing()
{

}

void DragDrawing::Create()
{
	if (Instance == nullptr)
		Instance = new DragDrawing();
}
void DragDrawing::Initialize(HWND p_hWnd)
{
	DragDrawing::GetInstance()->Id = 0;
	DragDrawing::GetInstance()->hWnd = p_hWnd;
}
void DragDrawing::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
DragDrawing* DragDrawing::GetInstance()
{
	return Instance;
}

void DragDrawing::SetHWND(HWND p_hwnd)
{
	this->hWnd = p_hwnd;
}
void DragDrawing::SetOldPos(LPARAM lParam)
{
	this->OldPos.x = LOWORD(lParam);
	this->OldPos.y = HIWORD(lParam);
}
void DragDrawing::SetID(int p_id)
{
	this->Id = p_id;
}

HWND DragDrawing::GetHWND()
{
	return this->hWnd;
}
int DragDrawing::GetID()
{
	return this->Id;
}

void DragDrawing::DrawObject(HDC hdc)
{
	CMouse* mouse = CMouse::GetInstance();
	switch (Id)
	{
	case ID_FREE:
		MoveToEx(hdc, mouse->GetOldX(), mouse->GetOldy(), NULL);
		LineTo(hdc, mouse->GetX(), mouse->Gety());
		break;
	case ID_LINE:
		if (mouse->GetClick())
		{
			SetROP2(hdc, R2_NOT);
			MoveToEx(hdc, OldPos.x, OldPos.y, NULL);
			LineTo(hdc, mouse->GetOldX(), mouse->GetOldy());
		}
		MoveToEx(hdc, OldPos.x, OldPos.y, NULL);
		LineTo(hdc, mouse->GetX(), mouse->Gety());
		break;
	case ID_RECTANGLE:
		if (mouse->GetClick())
		{
			SetROP2(hdc, R2_NOT);
			Rectangle(hdc, OldPos.x, OldPos.y, mouse->GetOldX(), mouse->GetOldy());
		}
		Rectangle(hdc, OldPos.x, OldPos.y, mouse->GetX(), mouse->Gety());
		break;
	case ID_CIRCLE:
		if (mouse->GetClick())
		{
			SetROP2(hdc, R2_XORPEN);
			Ellipse(hdc, OldPos.x, OldPos.y, mouse->GetOldX(), mouse->GetOldy());
		}
		Ellipse(hdc, OldPos.x, OldPos.y, mouse->GetX(), mouse->Gety());
		break;
	}
}