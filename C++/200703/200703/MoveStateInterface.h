#pragma once
#include "Global.h"

class Character;

class MoveState
{
public:
	virtual void CharacterMove(Character* character) = 0;
};

class Idle : public MoveState
{
private:
	static Idle* instance;

	Idle(){}
	~Idle(){}
public:
	static void Create();
	static void Destory();
	static Idle* GetInstace();
	void CharacterMove(Character* character);
};

class Walking : public MoveState
{
private:
	static Walking* instance;

	Walking() {}
	~Walking() {}
public:
	static void Create();
	static void Destory();
	static Walking* GetInstace();
	void CharacterMove(Character* character);
};

class Run : public MoveState
{
private:
	static Run* instance;

	Run() {}
	~Run() {}
public:
	static void Create();
	static void Destory();
	static Run* GetInstace();
	void CharacterMove(Character* character);
};

class Rolling : public MoveState
{
private:
	static Rolling* instance;

	Rolling() {}
	~Rolling() {}
public:
	static void Create();
	static void Destory();
	static Rolling* GetInstace();
	void CharacterMove(Character* character);
};