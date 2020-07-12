#pragma once
#include "Global.h"
class Player
{
private:
	POINT Position;						// 위치값
	POINT OffsetPosition;				// 초기 위치값
	HBITMAP Img;						// 플레이어이미지
	SIZE ImgSize;						// 이미지 사이즈

	float MoveSpeed = 5.0f;				// 이동 속도
	float RotateSpeed = 3.0f;			// 회전 속도 (각도 증가값)
	float Angle = 0.0f;					// 현재 회전한 각도

	xMove Xmove = xMove::XNONE;			// -1 : Left /  0 : Stop / 1 : Right
	yMove Ymove = yMove::YNONE;			// -1 : Up /  0 : Stop / 1 : Down
	Rotate rotate = Rotate::RNONE;		// -1 : LeftRotate /  0 : Stop / 1 : RightRotate
	int ShootCount = 0;					// 총알을 몇개 쐇는지

	int HP = 10;						// HP
public:
	// 생성자입니다.
	Player(RECT rect, HBITMAP hBitmap)
	{
		Img = hBitmap;

		BITMAP bit;
		GetObject(Img, sizeof(BITMAP), &bit);
		ImgSize.cx = bit.bmWidth;
		ImgSize.cy = bit.bmHeight;

		Position.x = (rect.right - ImgSize.cx * 1.5f) / 2;
		Position.y = (rect.bottom - ImgSize.cy * 1.5f) / 2;
		//Position.y = 550;
		OffsetPosition = Position;
	}

	// 각종 읽기접근자입니다.
	POINT GetPos() { return Position; }
	POINT GetCenterPos() 
	{
		POINT temp;
		temp = { Position.x + ImgSize.cx / 2, Position.y + ImgSize.cy / 2 };
		return temp;
	}
	HBITMAP GetImage() { return Img; }
	RECT GetRect()
	{
		RECT temp;
		SetRect(&temp, Position.x, Position.y, Position.x + ImgSize.cx * 1.5f, Position.y + ImgSize.cy * 1.5f);
		return temp;
	}
	float GetAngle() { return Angle; }
	int GetCount() { return ShootCount; }
	int GetWidth() { return ImgSize.cx; }
	int GetHeight() { return ImgSize.cy; }
	int GetHP() { return HP; }
	// 쓰기접근자입니다.
	void SetPos(POINT pPos) { Position = pPos; }
	void SetXmove(xMove pVal) { Xmove = pVal; }
	void SetYmove(yMove pVal) { Ymove = pVal; }
	void SetRotate(Rotate pVal) { rotate = pVal; }
	void SetCount(int pVal) { ShootCount = pVal; }
	void SetHP(int pVal) { HP = pVal; }
	
	void loseHP() { --HP; }

	void ResetPos()
	{
		Position = OffsetPosition;
	}

	// 플레이어의 회전 및 이동을 위한 함수입니다.
	void PlayerMove()
	{
		Position.x += MoveSpeed * Xmove;
		Position.y += MoveSpeed * Ymove;

		Angle += RotateSpeed * rotate;
		if (abs((int)Angle) >= 360)
			Angle = 3.0f;
	}
	
};

