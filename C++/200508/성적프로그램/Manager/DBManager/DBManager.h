#pragma once
#include "LinkedList.h"
//#include "DBManager.cpp"
#include "../../Student/Student.h"

class DBManager
{
private:
	CLinkedList<CStudent*>* list;
	int TotalCount;
	static int PassCount;
public:
	DBManager();
	~DBManager();

	void Initialize();
	void ResetCount();
	bool Save(CStudent*);
	bool Remove(CStudent*);
	CStudent* Pass();
	
};

