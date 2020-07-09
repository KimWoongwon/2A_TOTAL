#pragma once
#include "Global.h"
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
};

class GameStart : public GameLogic
{
private:
	static GameStart* Instance;

	MINI_GAME* mMainSence;
	GameStart() {}
	~GameStart() {}
public:
	static void Create(MINI_GAME* mMainSence);
	static void Destory();
	static GameStart* GetInstance();

	void OnPaint(HDC hdc);
	void OnTimer();

	void ChangeState();
};

class StartWaiting : public GameLogic
{
private:
	static StartWaiting* Instance;

	MINI_GAME* mMainSence;
	StartWaiting() {}
	~StartWaiting() {}
public:
	static void Create(MINI_GAME* mMainSence);
	static void Destory();
	static StartWaiting* GetInstance();

	void OnPaint(HDC hdc);
	void OnTimer();

	void ChangeState();
};

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