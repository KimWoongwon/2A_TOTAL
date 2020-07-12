#pragma once
#include "Global.h"
class Enemy
{
private:
	POINT Position;				// 위치값
	POINT Increase = { 0,0 };	// 증가값

	EnemyType enemyType;		// 몬스터 종류
	bool EnemyAnimation = false;// 이미지의 상태

	HBITMAP Img;				// 몬스터의 현재 이미지
	SIZE ImgSize;				// 이미지의 사이즈

	float Angle = 0.0f;			// 몬스터의 회전 각도

	bool Hit = false;			// 몬스터가 충돌했는지 여부
	bool Visable = false;		// 몬스터가 젠 됬는지 여부

public:
	// 각종함수는 생성자, 읽기접근자, 쓰기접근자, Position을 증가시키기 위한함수로 구성되었습니다.
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