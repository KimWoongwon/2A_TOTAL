#ifndef CPROGRAMMING_MANAGER_H
#define CPROGRAMMING_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"

#define PROGRAM_CODE "032"

class CProgrammingManager :public CManager
{
private:
	static const char*			mSubjectName[];	

public:
	CProgrammingManager();
	~CProgrammingManager();

	virtual void Input();
	virtual void Display();
	virtual void Search();
	
};
#endif