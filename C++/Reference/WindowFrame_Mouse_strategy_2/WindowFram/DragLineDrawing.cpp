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

void CDragLineDrawing::ReleaseAttribute(HDC _hdc)
{
	mPen->ReleaseAttribute(_hdc);
	
}
void CDragLineDrawing::SelectAttribute(HDC _hdc)
{
	mPen->SelectAttribute(_hdc);
	
}

void CDragLineDrawing::SetAttribute(COLOR _color, PENSIZE _size)
{
	if (_color == COLOR::NODATA)
	{
		mPen->SetPoint(_size);
		return;
	}

	if (_size == PENSIZE::NODATA)
	{
		mPen->SetColor(_color);
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
			SetROP2(hdc, R2_XORPEN);
			this->SelectAttribute(hdc);
			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetOldX(), mouse->GetOldy());

			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetX(), mouse->Gety());
			this->ReleaseAttribute(hdc);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			this->SelectAttribute(hdc);
			MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
			LineTo(hdc, mouse->GetX(), mouse->Gety());
			this->ReleaseAttribute(hdc);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);

		}
	}


}