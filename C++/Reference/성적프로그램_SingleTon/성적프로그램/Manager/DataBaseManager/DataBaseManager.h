#ifndef _CDATABASEMANAGER_H
#define _CDATABASEMANAGER_H
#include "..//../Main/Global.h"
#include "../../Datastructure/LinkedList.h"
#include "../../Student/Student.h"

class CDataBaseManager
{
	static CDataBaseManager* mPthis;

	CLinkedList<CStudent*>* mDesignLst;
	int							mDesignCount;

	CLinkedList<CStudent*>* mGraphicLst;
	int							mGraphicCount;

	CLinkedList<CStudent*>* mProgramLst;
	int							mProgramCount;

	CNode<CStudent*>* mData;

	CDataBaseManager();
	~CDataBaseManager();

public:	

	static void Create();
	static CDataBaseManager* GetInstance();
	static void Destroy();

	void Initialize();
	bool Input(CStudent*, int);
	bool Delete(CStudent*, int);
	bool GetData(CStudent**, int);
	void GetDataEnd();
	int	 GetCount(int);
};
#endif
