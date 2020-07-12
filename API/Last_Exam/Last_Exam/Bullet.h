#pragma once
#include "Global.h"
struct Bullet	// �Ѿ� ����ü�Դϴ�.
{
public:
	POINT Position;	// ��ġ��
	POINT Increase;	// ������
	HBITMAP Img;	// �̹���
	int Width;		// �̹��� ��
	int Height;		// �̹��� ����
	float Angle;	// ����������� ���ư��� �÷��̾��� ȸ������ ���� �����Դϴ�.
	bool isShoot;	// ���� �̰�ü�� �߻�Ǿ����� üũ�ϴ� �Լ��Դϴ�.

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
