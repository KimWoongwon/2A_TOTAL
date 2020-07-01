#ifndef CGRAPHIC_MANAGER_H
#define CGRAPHIC_MANAGER_H
#include "../../Student/Student.h"
#include "../Manager.h"

#define GRAPHIC_CODE "033"

class CGraphicManager : public CManager
{
private:
	static char*				mSubjectName[];
	static CGraphicManager*		mPthis;
	CGraphicManager();
	~CGraphicManager();

public:

	static void Create();
	static CGraphicManager* GetInstance();
	static void Destroy();

	void Initialize();

	void Input();
	void Delete();
	void Display();
	void Search();

	void CalculateGrade();

};
#endif