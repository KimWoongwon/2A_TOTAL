#ifndef _CDRAGDRAWING_H
#define _CDRAGDRAWING_H
#include "Global.h"
#include "Mouse.h"
#include "BackBit.h"
#include "Attribute.h"
#include "Menu.h"

class CDragDrawing
{
protected:
	int mStartp_x;
	int mStartp_y;
	
	CDragDrawing() 	
	{
		mStartp_x = 0;
		mStartp_y = 0;		
	}

	virtual ~CDragDrawing()
	{
	
	}

public:

	int GetStartp_x() {return mStartp_x;}
	int GetStartp_y() {return mStartp_y;}

	void SetStartp_x(int _x){ mStartp_x=_x;}
	void SetStartp_y(int _y){ mStartp_y=_y;}

	virtual void ReleaseAttribute(HDC _hdc) = 0;

	virtual void SelectAttribute(HDC _hdc) = 0;

	virtual void SetAttribute(COLOR, PENSIZE) = 0;	

	virtual void DragDrawing(CBackBit*, int) =0;
};

#endif