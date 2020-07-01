#include "DragLineDrawing.h"
CDragLineDrawing* CDragLineDrawing::mPthis = nullptr;

void CDragLineDrawing::Create()
{
	if (!mPthis)
	{
		mPthis = new CDragLineDrawing();
	}

}
CDragLineDrawing* CDragLineDrawing::GetInstance()
{
	return mPthis;
}
void CDragLineDrawing::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

void CDragLineDrawing::DragDrawing(CBackBit* _bit, int _drawmode)
{
	CMouse* mouse = CMouse::GetInstance();
	HPEN Newpen, Oldpen;
	if (mouse->GetClick())
	{
		if (_drawmode == REVERSE)
		{

			HDC hdc = _bit->GetBitmapDC();
			Newpen = CreatePen(PS_SOLID, PenSize, PenRGB);
			Oldpen = (HPEN)SelectObject(hdc, Newpen);
			SetROP2(hdc, R2_XORPEN);
			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetOldX(), mouse->GetOldy());

			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetX(), mouse->Gety());
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
			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetX(), mouse->Gety());
			SelectObject(hdc, Oldpen);
			DeleteObject(Newpen);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);

		}
	}


}
void CDragLineDrawing::SetPenSize(int select)
{
	switch (select)
	{
	case ID_LW_3:
		PenSize = 3;
		break;
	case ID_LW_5:
		PenSize = 5;
		break;
	case ID_LW_10:
		PenSize = 10;
		break;
	case ID_LW_DEFAULT:
		PenSize = 1;
		break;
	}
}
void CDragLineDrawing::SetPenRGB(int select)
{
	switch (select)
	{
	case ID_LL_RED:
		PenRGB = RGB(255, 0, 0);
		break;
	case ID_LL_BLUE:
		PenRGB = RGB(0, 0, 255);
		break;
	case ID_LL_GREEN:
		PenRGB = RGB(0, 255, 0);
		break;
	case ID_LL_DEFAULT:
		PenRGB = RGB(0, 0, 0);
		break;
	}
}