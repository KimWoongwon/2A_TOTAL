#pragma once
#include "Global.h"
#include "Student.h"
class Management
{
private:
	Student* list[MAXSTUDENT];
	int cur;
public:
	Management();
	~Management();
	bool Insert();
	bool Search();

	void Display(int i);
	void Display_All();
	void Display_Menu();
	
	void Run();
	
};

