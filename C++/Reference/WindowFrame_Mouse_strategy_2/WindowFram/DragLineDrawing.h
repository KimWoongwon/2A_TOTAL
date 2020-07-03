#ifndef _CDRAGLINE_H
#define _CDRAGLINE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragLineDrawing:public CDragDrawing
{
	static CDragLineDrawing*	mPthis;

	CPenAttribute*				mPen;
	
	CDragLineDrawing()
	{
		mPen=new CPenAttribute(COLOR::RED, PENSIZE::POINT1);
	}
	~CDragLineDrawing()
	{
		delete mPen;
	}

public:
	static void Create();
	static CDragLineDrawing* GetInstance();
	static void Destroy();
	
	void ReleaseAttribute(HDC _hdc) override;
	
	void SelectAttribute(HDC _hdc) override;

	void SetAttribute(COLOR, PENSIZE) override;

	void DragDrawing(CBackBit*, int) override;
	
};
#endif