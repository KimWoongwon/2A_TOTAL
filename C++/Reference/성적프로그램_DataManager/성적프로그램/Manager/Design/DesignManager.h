#ifndef CDESIGN_MANAGER_H
#define CDESIGN_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"

#define DESIGN_CODE "031"

class CDesignManager: public CManager
{
private:
	static char*			mSubjectName[];	

public:
	CDesignManager();
	~CDesignManager();

	virtual void Input();
	virtual void Display();
	virtual void Search();

};
#endif