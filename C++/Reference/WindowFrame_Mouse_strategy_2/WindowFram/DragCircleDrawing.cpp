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

void CDragCircleDrawing::ReleaseAttribute(HDC _hdc)
{
	mPen->ReleaseAttribute(_hdc);
	mBrush->ReleaseAttribute(_hdc);
}
void CDragCircleDrawing::SelectAttribute(HDC _hdc)
{
	mPen->SelectAttribute(_hdc);
	mBrush->SelectAttribute(_hdc);
}

void CDragCircleDrawing::SetAttribute(COLOR _color, PENSIZE _size)
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

void CDragCircleDrawing::DragDrawing(CBackBit* _bit, int _drawmode)
{

	CMouse* mouse = CMouse::GetInstance();

	if (mouse->GetClick())
	{
		if (_drawmode == REVERSE)
		{
			HDC hdc = _bit->GetBitmapDC();
			//HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			SetROP2(hdc, R2_XORPEN);
			this->SelectAttribute(hdc);
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetOldX(), mouse->GetOldy());
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			//DeleteObject(SelectObject(hdc, hOldBrush));
			this->ReleaseAttribute(hdc);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
		else
		{
			HDC hdc = _bit->GetBitmapDC();
			//HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
			this->SelectAttribute(hdc);
			Ellipse(hdc, mStartp_x, mStartp_y, mouse->GetX(), mouse->Gety());
			//DeleteObject(SelectObject(hdc, hOldBrush));
			this->ReleaseAttribute(hdc);
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(mouse->GetHWnd(), NULL, false);
		}
	}

}