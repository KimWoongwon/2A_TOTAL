#ifndef CGRAPHIC_MANAGER_H
#define CGRAPHIC_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"


#define GRAPHIC_CODE "033"


class CGraphicManager : public CManager
{
private:
	static const char*			mSubjectName[];

public:
	CGraphicManager();
	~CGraphicManager();

	bool Fillter();

	virtual void Input();
	virtual void Display();
	virtual void Search();

};
#endif