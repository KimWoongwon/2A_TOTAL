#ifndef _TOOLS_H
#define _TOOLS_H
#include "Global.h"

class Tool		// 가장 기본이 되는 추상클래스 인터페이스 라고 생각해도 된다. (Abstract Factory)
{
public:
	virtual ~Tool() {}		// 소멸자를 가상함수화 해서 Tool로 관리 할때 다른 클래스의 소멸자가 호출된다.
	virtual void Use() = 0; // Tool의 기능이 다 다르기때문에 각자 함수로 재구성 한다.
};
// 기능을 추가한 클래스
class Pen : public Tool 
{
public:
	Pen() 	{ cout << "Create Pen" << endl; }	// 생성시점을 알려주기 위해 
	~Pen() { cout << "Destroy Pen" << endl; }	// 삭제시점을 알려주기 위해

	void Use()	// Pen의 기능을 보여주는 함수이면서 Tool.Use와 같이 접근하기 때문에 가상함수화 해서 다형성을 보여준다?
	{ 
		cout << "Use Pen : ";
		Writing();
	}
	void Writing() { cout << "Writing..." << endl; }
};

// 주석 위와 동일
class Pencil : public Tool
{
public:
	Pencil()  { cout << "Create Pencil" << endl; }
	~Pencil() { cout << "Destroy Pencil" << endl; }

	void Use()
	{
		cout << "Use Pencil : ";
		Drawing();
	}
	void Drawing() { cout << "Drawing..." << endl; }
};

class Glue : public Tool
{
public:
	Glue()	{ cout << "Create Glue" << endl;  }
	~Glue() { cout << "Destroy Glue" << endl; }

	void Use()
	{
		cout << "Use Glue : ";
		Sticking();
	}
	void Sticking() { cout << "Sticking..." << endl; }
};
class Scissors : public Tool
{
public:
	Scissors()	{ cout << "Create Scissors" << endl;  }
	~Scissors() { cout << "Destroy Scissors" << endl; }

	void Use()
	{
		cout << "Use Scissors : ";
		Cutting();
	}
	void Cutting() { cout << "Cutting..." << endl; }
};


#endif // !_TOOLS_H

