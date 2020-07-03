#ifndef _CBRUSHATTRIBUTE_SELECT_H
#define _CBRUSHATTRIBUTE_SELECT_H
#include "Attribute.h"

class CBrushAttribute:public CAttribute
{
	HBRUSH		mHoldBrush;
	COLOR		mColor;

public:
	CBrushAttribute(COLOR _color)
	{
		mColor=_color;
	}

	void SelectAttribute(HDC _hdc)
	{		
		COLORREF color=RGB(0,0,0);
		
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
			break;		
		}

		HBRUSH hbrush=CreateSolidBrush(color);
		mHoldBrush=(HBRUSH)SelectObject(_hdc, hbrush);		
	}

	void SetColor(COLOR _color)
	{
		mColor = _color;
	}	

	void ReleaseAttribute(HDC _hdc)
	{
		DeleteObject(SelectObject(_hdc, mHoldBrush));
	}
};

#endif