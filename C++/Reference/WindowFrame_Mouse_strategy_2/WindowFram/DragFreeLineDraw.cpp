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

void CDragFreeLineDrawing::ReleaseAttribute(HDC _hdc)
{
	mPen->ReleaseAttribute(_hdc);

}
void CDragFreeLineDrawing::SelectAttribute(HDC _hdc)
{
	mPen->SelectAttribute(_hdc);

}

void CDragFreeLineDrawing::SetAttribute(COLOR _color, PENSIZE _size)
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

void CDragFreeLineDrawing::DragDrawing(CBackBit* _bit, int _drawmode)
{
	CMouse* mouse = CMouse::GetInstance();

	if (mouse->GetClick())
	{
		HDC hdc = _bit->GetBitmapDC();
		this->SelectAttribute(hdc);
		MoveToEx(hdc, mouse->GetOldX(), mouse->GetOldy(), NULL);
		LineTo(hdc, mouse->GetX(), mouse->Gety());
		this->ReleaseAttribute(hdc);
		_bit->DeleteBitmapDC(hdc);
		InvalidateRect(mouse->GetHWnd(), NULL, false);
	}

}