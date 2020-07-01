#include "Manager.h"

CDataBaseManager*  CManager::DataManager = nullptr;

CManager::CManager()
{
	DataManager = new CDataBaseManager();
}
CManager::~CManager()
{
	if (DataManager != nullptr)
	{
		delete DataManager;
		DataManager = nullptr;
	}
}