#pragma once
#include "Global.h"
struct Bullet	// 총알 구조체입니다.
{
public:
	POINT Position;	// 위치값
	POINT Increase;	// 증가값
	HBITMAP Img;	// 이미지
	int Width;		// 이미지 폭
	int Height;		// 이미지 높이
	float Angle;	// 어느방향으로 날아갈지 플레이어의 회전값에 의한 변수입니다.
	bool isShoot;	// 현재 이객체가 발사되었는지 체크하는 함수입니다.

	Bullet(POINT pos, HBITMAP hBitmap , POINT Offset)
	{
		Position = pos;
		Increase = Offset;
		Img = hBitmap;
		isShoot = false;
		Angle = 0.0f;

		BITMAP bit;
		GetObject(Img, sizeof(BITMAP), &bit);
		Width = bit.bmWidth;
		Height = bit.bmHeight;

		//Increase = { 0,0 };
	}

	void BulletMove()
	{
		Position.x += Increase.x;
		Position.y += Increase.y;
	}
	
};
