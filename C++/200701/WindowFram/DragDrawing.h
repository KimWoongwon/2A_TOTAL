#ifndef _CDRAGDRAWING_H
#define _CDRAGDRAWING_H
#include "Global.h"
#include "Mouse.h"
#include "BackBit.h"

class CDragDrawing
{
protected:
	int mStartp_x;
	int mStartp_y;

	int PenSize;
	COLORREF PenRGB;
public:
	CDragDrawing() { PenRGB = RGB(0, 0, 0); PenSize = 1;}
	int GetStartp_x() {return mStartp_x;}
	int GetStartp_y() {return mStartp_y;}
	int GetPenSize() { return PenSize; }
	COLORREF GetPenRGB() { return PenRGB; }

	void SetStartp_x(int _x){ mStartp_x=_x;}
	void SetStartp_y(int _y){ mStartp_y=_y;}

	virtual void SetAreaRGB(int select) {}
	virtual void SetPenSize(int select) = 0;
	virtual void SetPenRGB(int select) = 0;
	virtual void DragDrawing(CBackBit* _bit, int _drawmode)=0;

};

#endif