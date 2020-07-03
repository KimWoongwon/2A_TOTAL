#ifndef _CWINDOWFRAME_H
#define _CWINDOWFRAME_H
#include "Global.h"
#include "Menu.h"
#include "DragCircleDrawing.h"
#include "DragFreeLineDrawing.h"
#include "DragLineDrawing.h"
#include "DragRectangleDrawing.h"


class CWindowFrame
{
	static CWindowFrame* mPthis;

	HWND				mhWnd;	
	HINSTANCE			mhInstance;	
	CMenu*				mMenu[4];
	CBackBit*			mBackbit;

	CWindowFrame(HINSTANCE _hInstance)
	{
		mhWnd = nullptr;
		mhInstance = _hInstance;
		memset(mMenu, 0, sizeof(mMenu));
		mBackbit = nullptr;
	}
	~CWindowFrame(){}

public:
	static CWindowFrame* Create(HINSTANCE _hinstance);
	static CWindowFrame* GetInstance();
	static void Destroy();

	static LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam);

	void Run();
	void Initialize();
	void BuildWindow();
};
#endif
