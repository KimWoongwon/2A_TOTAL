#ifndef _CDRAGRECTANGLE_H
#define _CDRAGRECTANGLE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragRectangleDrawing :public CDragDrawing
{
	static CDragRectangleDrawing*	mPthis;

	CPenAttribute*			mPen;
	CBrushAttribute*		mBrush;


	CDragRectangleDrawing()
	{
		mPen = new CPenAttribute(COLOR::RED, PENSIZE::POINT1);
		mBrush = new CBrushAttribute(COLOR::RED);
	}

	~CDragRectangleDrawing()
	{
		delete mPen;
		delete mBrush;
	}

public:
	static void Create();
	static CDragRectangleDrawing* GetInstance();
	static void Destroy();

	void ReleaseAttribute(HDC _hdc) override;

	void SelectAttribute(HDC _hdc) override;

	void SetAttribute(COLOR, PENSIZE) override;

	void DragDrawing(CBackBit*, int) override;
	
};
#endif