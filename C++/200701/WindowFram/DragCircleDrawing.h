#ifndef _CDRAGCIRCLE_H
#define _CDRAGCIRCLE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragCircleDrawing:public CDragDrawing
{
	static CDragCircleDrawing*	mPthis;

	CDragCircleDrawing() { AreaRGB = RGB(255, 255, 255); }
	~CDragCircleDrawing(){};

	COLORREF AreaRGB;
public:
	static void Create();
	static CDragCircleDrawing* GetInstance();
	static void Destroy();

	void SetAreaRGB(int select);
	void SetPenRGB(int select);
	void SetPenSize(int select);
	void DragDrawing(CBackBit* _bit, int _drawmode);

};
#endif