#ifndef _CDRAGRECTANGLE_H
#define _CDRAGRECTANGLE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragRectangleDrawing :public CDragDrawing
{
	static CDragRectangleDrawing*	mPthis;

	CDragRectangleDrawing (){ AreaRGB = RGB(255, 255, 255); }
	~CDragRectangleDrawing(){};

	COLORREF AreaRGB;

public:
	static void Create();
	static CDragRectangleDrawing* GetInstance();
	static void Destroy();

	void SetAreaRGB(int select);
	void SetPenRGB(int select);
	void SetPenSize(int select);
	void DragDrawing(CBackBit* _bit, int _drawmode);
	
};
#endif