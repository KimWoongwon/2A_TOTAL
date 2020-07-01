#include "DragFreeLineDrawing.h"
CDragFreeLineDrawing* CDragFreeLineDrawing::mPthis = nullptr;

void CDragFreeLineDrawing::Create()
{
	if (!mPthis)
	{
		mPthis = new CDragFreeLineDrawing();
	}

}
CDragFreeLineDrawing* CDragFreeLineDrawing::GetInstance()
{
	return mPthis;
}
void CDragFreeLineDrawing::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

void CDragFreeLineDrawing::DragDrawing(CBackBit* _bit, int _drawmode)
{
	CMouse* mouse = CMouse::GetInstance();
	HPEN Newpen, Oldpen;
	if (mouse->GetClick())
	{

		HDC hdc = _bit->GetBitmapDC();
		Newpen = CreatePen(PS_SOLID, PenSize, PenRGB);
		Oldpen = (HPEN)SelectObject(hdc, Newpen);
		MoveToEx(hdc, mouse->GetOldX(), mouse->GetOldy(), NULL);
		LineTo(hdc, mouse->GetX(), mouse->Gety());
		SelectObject(hdc, Oldpen);
		DeleteObject(Newpen);
		_bit->DeleteBitmapDC(hdc);
		InvalidateRect(mouse->GetHWnd(), NULL, false);
	}

}
void CDragFreeLineDrawing::SetPenRGB(int select)
{
	switch (select)
	{
	case ID_FL_RED:
		PenRGB = RGB(255, 0, 0);
		break;
	case ID_FL_BLUE:
		PenRGB = RGB(0, 0, 255);
		break;
	case ID_FL_GREEN:
		PenRGB = RGB(0, 255, 0);
		break;
	case ID_FL_DEFAULT:
		PenRGB = RGB(0, 0, 0);
		break;
	}
}
void CDragFreeLineDrawing::SetPenSize(int select)
{
	switch (select)
	{
	case ID_FW_3:
		PenSize = 3;
		break;
	case ID_FW_5:
		PenSize = 5;
		break;
	case ID_FW_10:
		PenSize = 10;
		break;
	case ID_FW_DEFAULT:
		PenSize = 1;
		break;
	}
}