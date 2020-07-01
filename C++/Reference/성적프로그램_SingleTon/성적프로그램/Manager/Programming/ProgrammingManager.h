#ifndef CPROGRAMMING_MANAGER_H
#define CPROGRAMMING_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"

#define PROGRAM_CODE "032"

class CProgrammingManager :public CManager
{
private:
	static char*					mSubjectName[];	
	static CProgrammingManager*		mPthis;
	CProgrammingManager();
	~CProgrammingManager();

public:
	static void Create();
	static CProgrammingManager* GetInstance();
	static void Destroy();

	void Initialize();

	void Input();
	void Delete();
	void Display();
	void Search();
	
};
#endif