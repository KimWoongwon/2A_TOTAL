#pragma once
#include "Global.h"
class Enemy
{
private:
	POINT Position;				// ��ġ��
	POINT Increase = { 0,0 };	// ������

	EnemyType enemyType;		// ���� ����
	bool EnemyAnimation = false;// �̹����� ����

	HBITMAP Img;				// ������ ���� �̹���
	SIZE ImgSize;				// �̹����� ������

	float Angle = 0.0f;			// ������ ȸ�� ����

	bool Hit = false;			// ���Ͱ� �浹�ߴ��� ����
	bool Visable = false;		// ���Ͱ� �� ����� ����

public:
	// �����Լ��� ������, �б�������, ����������, Position�� ������Ű�� �����Լ��� �����Ǿ����ϴ�.
	Enemy(POINT pos, HBITMAP img, EnemyType number)
	{
		Position = pos;
		Img = img;
		enemyType = number;

		BITMAP bit;
		GetObject(Img, sizeof(BITMAP), &bit);
		ImgSize.cx = bit.bmWidth;
		ImgSize.cy = bit.bmHeight;

		Hit = false;
		Visable = false;
	}
	~Enemy()
	{
	}
	void Move()
	{
		Position.x += Increase.x;
		Position.y += Increase.y;
	}
	void Reset()
	{
		Increase = { 0,0 };
		Visable = false;
	}

	void SetPos(int px, int py) { Position.x = px;	Position.y = py; }
	void SetImage(HBITMAP pVal) { Img = pVal; }
	void SetIncrease(POINT pVal) { Increase = pVal; }
	void SetAnimaitionState(bool pVal) { EnemyAnimation = pVal; }
	void SetAngle(float pVal) { Angle = pVal; }
	void SetVisable(bool pVal) { Visable = pVal; }
	void SetHit(bool pVal) { Hit = pVal; }

	POINT GetPos() { return Position; }
	HBITMAP GetImage() { return Img; }
	EnemyType GetEnemyType() { return enemyType; }
	bool GetAnimaitionState() { return EnemyAnimation; }
	float GetAngle() { return Angle; }
	bool IsVisable() { return Visable; }
	bool IsHit() { return Hit; }
	int GetWidth() { return ImgSize.cx; }
	int GetHeight() { return ImgSize.cy; }

	RECT GetRect()
	{
		RECT temp;
		SetRect(&temp, Position.x, Position.y, Position.x + ImgSize.cx, Position.y + ImgSize.cy);
		return temp;
	}

};