#ifndef CMANAGER_H
#define CMANAGER_H
#include "..//Main//Global.h"
#include "../Student/Student.h"

class CManager
{
private:
	static char*	mSubjectName[];
	CStudent*		mStuLst[MAXSTUDENT];
	int				mCount;


public:
	CManager();
	~CManager();

	void Input();
	void ShowData();
	void SearchData();
	void ShowMenu();
	void Run();
};
#endif