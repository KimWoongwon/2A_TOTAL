#ifndef CMANAGER_H
#define CMANAGER_H
#include "..//Main//Global.h"
#include "DataBaseManager\DataBaseManager.h"


class CManager
{

public:
	CManager(){}
	~CManager(){}

	virtual void Input()=0;
	virtual void Delete() = 0;
	virtual void Display()=0;		
	virtual void Search() = 0;
};
#endif