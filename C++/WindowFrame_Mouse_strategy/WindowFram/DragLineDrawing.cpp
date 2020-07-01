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

	if (mouse->GetClick())
	{
		if (_drawmode == REVERSE)
		{

			HDC hdc = _bit->GetBitmapDC();
			SetROP2(hdc, R2_NOT);
			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetOldX(), mouse->GetOldy());

			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetX(), mouse->Gety());
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetX(), mouse->Gety());
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);

		}
	}


}