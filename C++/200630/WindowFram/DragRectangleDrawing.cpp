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

	if (mouse->GetClick())
	{
		if (_drawmode == REVERSE)
		{
			HDC hdc = _bit->GetBitmapDC();
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			SetROP2(hdc, R2_NOT);
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetOldX(), mouse->GetOldy());
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			DeleteObject(SelectObject(hdc, hOldBrush));
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			DeleteObject(SelectObject(hdc, hOldBrush));
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
	}

}