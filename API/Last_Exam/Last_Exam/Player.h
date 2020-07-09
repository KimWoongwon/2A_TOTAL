#pragma once
#include "Global.h"
class Player
{
private:
	POINT Position;
	POINT OffsetPosition;
	HBITMAP Img;
	SIZE ImgSize;

	float MoveSpeed = 5.0f;
	float RotateSpeed = 3.0f;
	float Angle = 0.0f;

	xMove Xmove = xMove::XNONE;		// -1 : Left /  0 : Stop / 1 : Right
	yMove Ymove = yMove::YNONE;		// -1 : Up /  0 : Stop / 1 : Down
	Rotate rotate = Rotate::RNONE;		// -1 : LeftRotate /  0 : Stop / 1 : RightRotate
	int ShootCount = 0;
public:
	Player(RECT rect, HBITMAP hBitmap)
	{
		Img = hBitmap;

		BITMAP bit;
		GetObject(Img, sizeof(BITMAP), &bit);
		ImgSize.cx = bit.bmWidth;
		ImgSize.cy = bit.bmHeight;

		Position.x = (rect.right - ImgSize.cx * 1.5f) / 2;
		Position.y = (rect.bottom - ImgSize.cy * 1.5f) / 2;
		OffsetPosition = Position;
	}

	POINT GetPos() { return Position; }
	HBITMAP GetImage() { return Img; }
	RECT GetRect()
	{
		RECT temp;
		SetRect(&temp, Position.x, Position.y, Position.x + ImgSize.cx, Position.y + ImgSize.cy);
		return temp;
	}
	float GetAngle() { return Angle; }
	int GetCount() { return ShootCount; }
	int GetWidth() { return ImgSize.cx; }
	int GetHeight() { return ImgSize.cy; }


	void SetPos(POINT pPos) { Position = pPos; }
	void SetXmove(xMove pVal) { Xmove = pVal; }
	void SetYmove(yMove pVal) { Ymove = pVal; }
	void SetRotate(Rotate pVal) { rotate = pVal; }
	void SetCount(int pVal) { ShootCount = pVal; }

	void ResetPos()
	{
		Position = OffsetPosition;
	}

	void PlayerMove()
	{
		Position.x += MoveSpeed * Xmove;
		Position.y += MoveSpeed * Ymove;

		Angle += RotateSpeed * rotate;
		if (abs((int)Angle) >= 360)
			Angle = 3.0f;
	}
	
};

