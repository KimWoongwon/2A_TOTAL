#pragma once
#include "Global.h"
struct Bullet
{
public:
	POINT Position;
	POINT Increase;
	HBITMAP Img;
	int Width;
	int Height;
	float Angle;
	bool isShoot;

	Bullet(POINT pos, HBITMAP hBitmap)
	{
		Position = pos;
		Img = hBitmap;
		isShoot = false;
		Angle = 0.0f;

		BITMAP bit;
		GetObject(Img, sizeof(BITMAP), &bit);
		Width = bit.bmWidth;
		Height = bit.bmHeight;

		Increase = { 0,0 };
	}

	void BulletMove()
	{
		Position.x += Increase.x;
		Position.y += Increase.y;
	}
	
};
