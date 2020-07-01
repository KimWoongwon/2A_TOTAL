#ifndef CDESIGN_MANAGER_H
#define CDESIGN_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"

#define DESIGN_CODE "031"

class CDesignManager: public CManager
{
private:
	static char*			mSubjectName[];	
	static CDesignManager*	mPthis;

	CDesignManager();
	~CDesignManager();


public:

	static void Create();
	static CDesignManager* GetInstance();
	static void Destroy();

	void Initialize();

	void Input();
	void Delete();
	void Display();
	void Search();

};
#endif