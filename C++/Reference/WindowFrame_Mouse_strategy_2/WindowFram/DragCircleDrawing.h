#ifndef _CDRAGCIRCLE_H
#define _CDRAGCIRCLE_H

#include "Global.h"
#include "DragDrawing.h"


class CDragCircleDrawing:public CDragDrawing
{
	static CDragCircleDrawing*	mPthis;

	CPenAttribute*			mPen;
	CBrushAttribute*		mBrush;

	CDragCircleDrawing()
	{
		mPen = new CPenAttribute(COLOR::RED, PENSIZE::POINT1);
		mBrush = new CBrushAttribute(COLOR::RED);
	}

	~CDragCircleDrawing()
	{
		delete mPen;
		delete mBrush;
	}

public:
	static void Create();
	static CDragCircleDrawing* GetInstance();
	static void Destroy();

	void ReleaseAttribute(HDC _hdc) override;
	
	void SelectAttribute(HDC _hdc) override;

	void SetAttribute(COLOR, PENSIZE) override;

	void DragDrawing(CBackBit*, int) override;

};
#endif