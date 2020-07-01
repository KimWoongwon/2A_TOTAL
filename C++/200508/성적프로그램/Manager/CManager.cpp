#include "Manager.h"

CManager::CManager()
{
	mDBMng = new DBManager();
	mDBMng->Initialize();
	mStudent = nullptr;
	mStuCount = 0;
}
CManager::~CManager()
{
	delete mDBMng;
	if(mStudent != nullptr)
		delete mStudent;
}