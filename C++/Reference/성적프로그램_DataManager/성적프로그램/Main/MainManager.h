#ifndef CMAIN_H
#define CMAIN_H
#include "Global.h"
#include "../Manager/Design/DesignManager.h"
#include "../Manager/Graphic/GraphicManager.h"
#include "../Manager/Programming/ProgrammingManager.h"

class CMainManager
{
private:
	CDesignManager*			mDesignMng;
	CGraphicManager*		mGraphicMng;
	CProgrammingManager*	mProgramMng;

public:
	CMainManager();
	~CMainManager();

	void			Initialize();
	int				ShowMenu();
	CManager*		MajorSelect();

	void			Run();

};
#endif