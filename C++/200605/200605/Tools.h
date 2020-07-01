#ifndef _TOOLS_H
#define _TOOLS_H
#include "Global.h"

class Tool		// ���� �⺻�� �Ǵ� �߻�Ŭ���� �������̽� ��� �����ص� �ȴ�. (Abstract Factory)
{
public:
	virtual ~Tool() {}		// �Ҹ��ڸ� �����Լ�ȭ �ؼ� Tool�� ���� �Ҷ� �ٸ� Ŭ������ �Ҹ��ڰ� ȣ��ȴ�.
	virtual void Use() = 0; // Tool�� ����� �� �ٸ��⶧���� ���� �Լ��� �籸�� �Ѵ�.
};
// ����� �߰��� Ŭ����
class Pen : public Tool 
{
public:
	Pen() 	{ cout << "Create Pen" << endl; }	// ���������� �˷��ֱ� ���� 
	~Pen() { cout << "Destroy Pen" << endl; }	// ���������� �˷��ֱ� ����

	void Use()	// Pen�� ����� �����ִ� �Լ��̸鼭 Tool.Use�� ���� �����ϱ� ������ �����Լ�ȭ �ؼ� �������� �����ش�?
	{ 
		cout << "Use Pen : ";
		Writing();
	}
	void Writing() { cout << "Writing..." << endl; }
};

// �ּ� ���� ����
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

