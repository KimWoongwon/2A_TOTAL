#ifndef CMAIN_H
#define CMAIN_H
#include "Global.h"
#include "../Manager/Design/DesignManager.h"
#include "../Manager/Graphic/GraphicManager.h"
#include "../Manager/Programming/ProgrammingManager.h"

class CMainManager
{
private:
	
	static CMainManager*	mPthis;
	CMainManager();
	~CMainManager();
	
public:
	static void				Create();
	static CMainManager*	GetInstance();
	static void				Destroy();

	void		Initialize();
	int			SelectMainMenu();
	CManager*	MajorSelect(const char*);
	void		Run();

};
#endif