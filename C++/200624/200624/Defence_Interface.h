#pragma once
#include "Global.h"
class DefenceBehavior
{
public:
	virtual void Defence() = 0;
};

class Block :public DefenceBehavior
{
public:
	void Defence()
	{
		cout << "Block!" << endl;
	}
};

class Dodge : public DefenceBehavior
{
public:
	void Defence()
	{
		cout << "Dodge!" << endl;
	}
};

class Parrying : public DefenceBehavior
{
public:
	void Defence()
	{
		cout << "Parrying!" << endl;
	}
};