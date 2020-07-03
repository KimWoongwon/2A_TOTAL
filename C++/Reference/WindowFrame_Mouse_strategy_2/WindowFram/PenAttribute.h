#ifndef _CPENATTRIBUTE_SELECT_H
#define _CPENATTRIBUTE_SELECT_H
#include "Attribute.h"

class CPenAttribute:public CAttribute
{
	HPEN		mHoldPen;
	COLOR		mColor;
	PENSIZE		mPoint;

public:
	CPenAttribute(COLOR _color, PENSIZE _point)
	{
		mHoldPen = nullptr;
		mColor=_color;
		mPoint=_point;
	}
	~CPenAttribute()
	{
		
	}

	void SelectAttribute(HDC _hdc)
	{	
		COLORREF		color;	

		switch(mColor)
		{	
		case COLOR::RED:
			color=RGB(255,0,0);
			break;
	
		case COLOR::BLUE:
			color=RGB(0,0,255);
			break;
	
		case COLOR::GREEN:
			color=RGB(0,255,0);
		}
	

		HPEN hpen=CreatePen(PS_SOLID, (int)mPoint, color);
		mHoldPen=(HPEN)SelectObject(_hdc, hpen);		
	}	

	void SetColor(COLOR _color)
	{
		mColor = _color;
	}

	void SetPoint(PENSIZE _size)
	{
		mPoint = _size;
	}

	void ReleaseAttribute(HDC _hdc)
	{
		DeleteObject(SelectObject(_hdc, mHoldPen));
	}
};

#endif