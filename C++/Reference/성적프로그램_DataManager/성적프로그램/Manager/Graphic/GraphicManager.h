#ifndef CGRAPHIC_MANAGER_H
#define CGRAPHIC_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"

#define GRAPHIC_CODE "033"

class CGraphicManager : public CManager
{
private:
	static char*			mSubjectName[];

public:
	CGraphicManager();
	~CGraphicManager();

	virtual void Input();
	virtual void Display();
	virtual void Search();

	//void CalculateGrade();

};
#endif