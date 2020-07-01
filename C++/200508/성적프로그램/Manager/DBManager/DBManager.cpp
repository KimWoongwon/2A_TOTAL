#include "DBManager.h"
#include "LinkedList.cpp"

int DBManager::PassCount = 0;

DBManager::DBManager()
{
	this->list = nullptr;
	TotalCount = 0;
}

DBManager::~DBManager()
{
	if (this->list != nullptr)
		delete this->list;
}

void DBManager::Initialize()
{
	this->list = new CLinkedList<CStudent*>;
}
void DBManager::ResetCount()
{
	PassCount = 0;
}
bool DBManager::Save(CStudent* p_stu)
{
	this->list->Insert(p_stu);
	return true;
}
bool DBManager::Remove(CStudent* p_stu)
{
	this->list->Delete(p_stu);
	return true;
}
CStudent* DBManager::Pass()
{
	CStudent* temp = this->list->GetItem(++PassCount);
	return temp;
}

