#ifndef _CDRAGFREELINE_H
#define _CDRAGFREELINE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragFreeLineDrawing:public CDragDrawing
{
	static CDragFreeLineDrawing*	mPthis;
	
	CPenAttribute*					mPen;
	
	
	CDragFreeLineDrawing()
	{
		mPen = new CPenAttribute(COLOR::RED, PENSIZE::POINT1);
	}
	~CDragFreeLineDrawing()
	{
		delete mPen;
	}

public:
	static void Create();
	static CDragFreeLineDrawing* GetInstance();
	static void Destroy();

	void ReleaseAttribute(HDC _hdc) override;
	
	void SelectAttribute(HDC _hdc) override;

	void SetAttribute(COLOR, PENSIZE) override;

	void DragDrawing(CBackBit*, int) override;

};
#endif