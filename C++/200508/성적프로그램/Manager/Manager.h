#ifndef CMANAGER_H
#define CMANAGER_H
#include "../Main/Global.h"
#include "../Student/Student.h"
#include "../Manager/DBManager/DBManager.h"
//#include "DBManager/DBManager.cpp"
class CManager
{
protected:
	DBManager*					mDBMng;
	CStudent*					mStudent;
	int							mStuCount;

public:
	CManager();
	virtual ~CManager();	

	virtual void Input() = 0;
	virtual void Display()=0;
	virtual void Search()=0;
};
#endif