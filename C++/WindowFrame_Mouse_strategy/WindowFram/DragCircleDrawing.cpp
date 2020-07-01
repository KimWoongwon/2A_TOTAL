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

	if (mouse->GetClick())
	{
		if (_drawmode == REVERSE)
		{
			HDC hdc = _bit->GetBitmapDC();
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			SetROP2(hdc, R2_NOT);
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetOldX(), mouse->GetOldy());
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			DeleteObject(SelectObject(hdc, hOldBrush));
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			DeleteObject(SelectObject(hdc, hOldBrush));
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
	}

}