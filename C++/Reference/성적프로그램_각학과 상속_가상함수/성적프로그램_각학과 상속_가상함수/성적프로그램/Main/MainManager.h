#ifndef CMAIN_H
#define CMAIN_H
#include "Global.h"
#include "../Manager/DesignManager/DesignManager.h"
#include "../Manager/GraphicManager/GraphicManager.h"
#include "../Manager/ProgramManager/ProgrammingManager.h"

class CMainManager
{
private:
	CDesignManager*				mDesignMng;
	CGraphicManager*			mGraphicMng;
	CProgrammingManager*		mProgramMng;	
	
public:
	CMainManager();	
	~CMainManager();

	void			Initialize();
	int				ShowMenu();
	CManager*		MajorSelect();

	void			Run();

};
#endif