#pragma once
#include "Global.h"
#include <math.h>
class MINI_GAME;

class GameLogic
{
	
public:
	virtual void ChangeState() = 0;
	virtual void OnPaint(HDC) = 0;
	virtual void OnTimer() = 0;
};

class Title : public GameLogic
{
private:
	static Title* Instance;

	
	int BGposX = 0;
	int BGmoveSpeed = 50;
	HBITMAP BackGround;
	MINI_GAME* mMainSence;
	Title() {}
	~Title() {}
public:
	static void Create(MINI_GAME* mMainSence);
	static void Destory();
	static Title* GetInstance();

	void OnPaint(HDC hdc);
	void OnTimer();

	void ChangeState();
	void reset();
	

};

class GameStart : public GameLogic
{
private:
	static GameStart* Instance;

	
	int Gametime;
	//POINT CirclePos = { 0,0 };
	
	int count = 0;
	int CircleCount = 0;

	MINI_GAME* mMainSence;
	GameStart() {}
	~GameStart() {}
public:
	POINT CirclePos = { 0,0 };
	int radius = 0;
	static void Create(MINI_GAME* mMainSence);
	static void Destory();
	static GameStart* GetInstance();

	void OnPaint(HDC hdc);
	void OnTimer();

	void ChangeState();
	void Reset();
};

//class Reset : public GameLogic
//{
//private:
//	static Reset* Instance;
//	
//
//	MINI_GAME* mMainSence;
//	Reset() { }
//	~Reset() {}
//public:
//	static void Create(MINI_GAME* mMainSence);
//	static void Destory();
//	static Reset* GetInstance();
//
//	void OnPaint(HDC hdc);
//	void OnTimer();
//
//	void ChangeState();
//};

class GameEnd : public GameLogic
{
private:
	static GameEnd* Instance;

	

	MINI_GAME* mMainSence;
	GameEnd() {}
	~GameEnd() {}
public:
	static void Create(MINI_GAME* mMainSence);
	static void Destory();
	static GameEnd* GetInstance();

	void OnPaint(HDC hdc);
	void OnTimer();

	void ChangeState();
};