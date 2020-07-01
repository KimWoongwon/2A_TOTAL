#include "DragCircleDrawing.h"
CDragCircleDrawing* CDragCircleDrawing::mPthis = nullptr;

void CDragCircleDrawing::Create()
{
	if (!mPthis)
	{
		mPthis = new CDragCircleDrawing();
	}

}
CDragCircleDrawing* CDragCircleDrawing::GetInstance()
{
	return mPthis;
}
void CDragCircleDrawing::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

void CDragCircleDrawing::DragDrawing(CBackBit* _bit, int _drawmode)
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
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetOldX(), mouse->GetOldy());
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
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
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			SelectObject(hdc, OldBrush);
			DeleteObject(NewBrush);
			SelectObject(hdc, Oldpen);
			DeleteObject(Newpen);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
	}

}
void CDragCircleDrawing::SetAreaRGB(int select)
{
	switch (select)
	{
	case ID_CA_RED:
		AreaRGB = RGB(255, 0, 0);
		break;
	case ID_CA_BLUE:
		AreaRGB = RGB(0, 0, 255);
		break;
	case ID_CA_GREEN:
		AreaRGB = RGB(0, 255, 0);
		break;
	case ID_CA_DEFAULT:
		AreaRGB = RGB(255, 255, 255);
		break;
	}
}
void CDragCircleDrawing::SetPenRGB(int select)
{
	switch (select)
	{
	case ID_CL_RED:
		PenRGB = RGB(255, 0, 0);
		break;
	case ID_CL_BLUE:
		PenRGB = RGB(0, 0, 255);
		break;
	case ID_CL_GREEN:
		PenRGB = RGB(0, 255, 0);
		break;
	case ID_CL_DEFAULT:
		PenRGB = RGB(0, 0, 0);
		break;
	}
}
void CDragCircleDrawing::SetPenSize(int select)
{
	switch (select)
	{
	case ID_CW_3:
		PenSize = 3;
		break;
	case ID_CW_5:
		PenSize = 5;
		break;
	case ID_CW_10:
		PenSize = 10;
		break;
	case ID_CW_DEFAULT:
		PenSize = 1;
		break;
	}
}