#pragma once
#include "Global.h"
class BackBlt
{
private:
	static BackBlt* Instance;

	HDC BACKDC;
	HDC MemDC;

	HBITMAP backBitmap;
	HBITMAP OldBitmap;
	RECT rect;
	BackBlt();
	~BackBlt();
public:
	static void Create();
	static void Destory();
	static BackBlt* GetInstance();

	void MakeDC(HWND,HDC);
	HDC ReturnDC();

	void DrawBackDC(HWND,HDC);

};

