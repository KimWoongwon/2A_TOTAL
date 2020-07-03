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

void CDragRectangleDrawing::ReleaseAttribute(HDC _hdc)
{
	mPen->ReleaseAttribute(_hdc);
	mBrush->ReleaseAttribute(_hdc);
}
void CDragRectangleDrawing::SelectAttribute(HDC _hdc)
{
	mPen->SelectAttribute(_hdc);
	mBrush->SelectAttribute(_hdc);
}

void CDragRectangleDrawing::SetAttribute(COLOR _color, PENSIZE _size)
{
	switch (_size)
	{
	case PENSIZE::NO_PEN:
		mBrush->SetColor(_color);
		break;
	case PENSIZE::NODATA:
		mPen->SetColor(_color);
		break;
	default:
		mPen->SetPoint(_size);
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
			SetROP2(hdc, R2_XORPEN);
			this->SelectAttribute(hdc);
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetOldX(), mouse->GetOldy());
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			this->ReleaseAttribute(hdc);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			this->SelectAttribute(hdc);
			Rectangle(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			this->ReleaseAttribute(hdc);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
	}

}