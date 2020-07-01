#include "BackBlt.h"
#include "DragDrawing.h"

BackBlt* BackBlt::Instance = nullptr;

BackBlt::BackBlt()
{

}
BackBlt::~BackBlt()
{
}

void BackBlt::Create()
{
	if (Instance == nullptr)
		Instance = new BackBlt();
}
void BackBlt::Destory()
{
	if (Instance != nullptr)
		delete Instance;
}
BackBlt* BackBlt::GetInstance()
{
	return Instance;
}

void BackBlt::MakeDC(HWND hWnd,HDC mainhdc)
{
	
	GetClientRect(hWnd, &rect);
	BACKDC = CreateCompatibleDC(mainhdc);
	backBitmap = CreateCompatibleBitmap(mainhdc, rect.right, rect.bottom);
	OldBitmap = (HBITMAP)SelectObject(BACKDC, backBitmap);
	PatBlt(BACKDC, 0, 0, rect.right, rect.bottom, WHITENESS);

	DrawBackDC(hWnd, BACKDC);
	BitBlt(mainhdc, 0, 0, rect.right, rect.bottom, BACKDC, 0, 0, SRCCOPY);
	SelectObject(BACKDC, OldBitmap);
	DeleteDC(BACKDC);
	DeleteObject(backBitmap);
}

HDC BackBlt::ReturnDC()
{
	return MemDC;
}



void BackBlt::DrawBackDC(HWND hWnd,HDC mainhdc)
{
	DragDrawing* drawing = DragDrawing::GetInstance();
	BITMAP Bitmap_;
	HBITMAP OldBitmap;
	MemDC = CreateCompatibleDC(BACKDC);
	OldBitmap = (HBITMAP)SelectObject(MemDC, BACKDC);
	drawing->DrawObject(MemDC);
	//TransparentBlt(BACKDC, x, y, BitmapX, BitmapY, MemoryDC, 0, 0, BitmapX, BitmapY, RGB(255, 255, 255));
	BitBlt(BACKDC, 0, 0, rect.right, rect.bottom, MemDC, 0, 0, SRCCOPY);
	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}