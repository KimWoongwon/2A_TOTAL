#pragma once
#include "../Global.h"

class CBackBit
{
	HBITMAP		mHbit;
	HWND		mHWnd;
	int			mHeight;
	int			mWidth;

public:
	CBackBit(HWND  _hwnd, int _width, int _height);
	~CBackBit();

	bool SetHeight(int _height);
	bool SetWidth(int _width);
	void SetHbit(HBITMAP _hbit){ mHbit=_hbit;}
	void SethWnd(HWND _hwnd){mHWnd=_hwnd;}

	HBITMAP GetBitMap() const {return mHbit;}
	HWND   GetHWnd() const{return mHWnd;}
	int    GetHeight() const {return mHeight;}
	int    GetWidth()  const {return mWidth;}
	HDC	   GetBitmapDC() const;
	void   DeleteBitmapDC(HDC _dc);
	
	void SCreanDraw(HDC _hdc, int _x, int _y);
	void BitmapDraw(int _x, int _y, HBITMAP _hbit);
	void ClearBitMap();

};
