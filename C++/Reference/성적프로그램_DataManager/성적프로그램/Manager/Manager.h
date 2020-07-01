#ifndef CMANAGER_H
#define CMANAGER_H
#include "..//Main//Global.h"
#include "DataBaseManager\DataBaseManager.h"


class CManager
{
protected:
	static CDataBaseManager*  DataManager;

public:
	CManager();
	virtual ~CManager();

	virtual void Input()=0;
	virtual void Display()=0;		
	virtual void Search() = 0;
};
#endif