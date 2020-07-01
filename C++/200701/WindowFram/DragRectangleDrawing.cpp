#include "DragRectangleDrawing.h"
CDragRectangleDrawing* CDragRectangleDrawing::mPthis = nullptr;

void CDragRectangleDrawing::Create()
{
	if (!mPthis)
	{
		mPthis = new CDragRectangleDrawing();
	}

}
CDragRectangleDrawing* CDragRectangleDrawing::GetInstance()
{
	return mPthis;
}
void CDragRectangleDrawing::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

void CDragRectangleDrawing::DragDrawing(CBackBit* _bit, int _drawmode)
{
	CMouse* mouse = CMouse::GetInstance();
	HPEN Newpen, Oldpen;
	HBRUSH NewBrush, OldBrush;
	if (mouse->GetClick())
	{
		if (_drawmode == REVERSE)
		{
			HDC hdc = _bit->GetBitmapDC();
			Newpen = CreatePen(PS_SOLID, PenSize, PenRGB);
			Oldpen = (HPEN)SelectObject(hdc, Newpen);
			NewBrush = CreateSolidBrush(AreaRGB);
			OldBrush = (HBRUSH)SelectObject(hdc, NewBrush);
			SetROP2(hdc, R2_XORPEN);
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetOldX(), mouse->GetOldy());
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			SelectObject(hdc, OldBrush);
			DeleteObject(NewBrush);
			SelectObject(hdc, Oldpen);
			DeleteObject(Newpen);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			Newpen = CreatePen(PS_SOLID, PenSize, PenRGB);
			Oldpen = (HPEN)SelectObject(hdc, Newpen);
			NewBrush = CreateSolidBrush(AreaRGB);
			OldBrush = (HBRUSH)SelectObject(hdc, NewBrush);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			SelectObject(hdc, OldBrush);
			DeleteObject(NewBrush);
			SelectObject(hdc, Oldpen);
			DeleteObject(Newpen);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
	}

}
void CDragRectangleDrawing::SetAreaRGB(int select)
{
	switch (select)
	{
	case ID_RA_RED:
		AreaRGB = RGB(255, 0, 0);
		break;
	case ID_RA_BLUE:
		AreaRGB = RGB(0, 0, 255);
		break;
	case ID_RA_GREEN:
		AreaRGB = RGB(0, 255, 0);
		break;
	case ID_RA_DEFAULT:
		AreaRGB = RGB(255, 255, 255);
		break;
	}
}
void CDragRectangleDrawing::SetPenRGB(int select)
{
	switch (select)
	{
	case ID_RL_RED:
		PenRGB = RGB(255, 0, 0);
		break;
	case ID_RL_BLUE:
		PenRGB = RGB(0, 0, 255);
		break;
	case ID_RL_GREEN:
		PenRGB = RGB(0, 255, 0);
		break;
	case ID_RL_DEFAULT:
		PenRGB = RGB(0, 0, 0);
		break;
	}
}
void CDragRectangleDrawing::SetPenSize(int select)
{
	switch (select)
	{
	case ID_RW_3:
		PenSize = 3;
		break;
	case ID_RW_5:
		PenSize = 5;
		break;
	case ID_RW_10:
		PenSize = 10;
		break;
	case ID_RW_DEFAULT:
		PenSize = 1;
		break;
	}
}