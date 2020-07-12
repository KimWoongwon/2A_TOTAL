#pragma once
#include "Global.h"
class Player
{
private:
	POINT Position;						// ��ġ��
	POINT OffsetPosition;				// �ʱ� ��ġ��
	HBITMAP Img;						// �÷��̾��̹���
	SIZE ImgSize;						// �̹��� ������

	float MoveSpeed = 5.0f;				// �̵� �ӵ�
	float RotateSpeed = 3.0f;			// ȸ�� �ӵ� (���� ������)
	float Angle = 0.0f;					// ���� ȸ���� ����

	xMove Xmove = xMove::XNONE;			// -1 : Left /  0 : Stop / 1 : Right
	yMove Ymove = yMove::YNONE;			// -1 : Up /  0 : Stop / 1 : Down
	Rotate rotate = Rotate::RNONE;		// -1 : LeftRotate /  0 : Stop / 1 : RightRotate
	int ShootCount = 0;					// �Ѿ��� � �i����

	int HP = 10;						// HP
public:
	// �������Դϴ�.
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

	// ���� �б��������Դϴ�.
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
	// �����������Դϴ�.
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

	// �÷��̾��� ȸ�� �� �̵��� ���� �Լ��Դϴ�.
	void PlayerMove()
	{
		Position.x += MoveSpeed * Xmove;
		Position.y += MoveSpeed * Ymove;

		Angle += RotateSpeed * rotate;
		if (abs((int)Angle) >= 360)
			Angle = 3.0f;
	}
	
};

