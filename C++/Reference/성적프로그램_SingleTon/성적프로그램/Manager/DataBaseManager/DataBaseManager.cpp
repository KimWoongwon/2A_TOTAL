#include "DataBaseManager.h"
CDataBaseManager* CDataBaseManager::mPthis = nullptr;

CDataBaseManager::CDataBaseManager()
{
	mDesignLst = nullptr;
	mProgramLst = nullptr;
	mGraphicLst = nullptr;
	mData = nullptr;

	mDesignCount = 0;
	mGraphicCount = 0;
	mProgramCount = 0;
}

void CDataBaseManager::Initialize()
{
	mDesignLst = new CLinkedList<CStudent*>();
	mProgramLst = new CLinkedList<CStudent*>();
	mGraphicLst = new CLinkedList<CStudent*>();
	
}

CDataBaseManager::~CDataBaseManager()
{
	delete mDesignLst;
	delete mProgramLst;
	delete mGraphicLst;
}



void CDataBaseManager::Create()
{
	if (!mPthis)
	{
		mPthis = new CDataBaseManager();
	}
}

CDataBaseManager* CDataBaseManager::GetInstance()
{
	return mPthis;
}

void CDataBaseManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

bool CDataBaseManager::Input(CStudent* _stu, int _code)
{
	switch (_code)
	{
	case PROGRAMMING:
		mProgramLst->Insert(_stu);
		mProgramCount++;
		break;
	case DESIGN:
		mDesignLst->Insert(_stu);
		mDesignCount++;
		break;
	case GRAPHIC:
		mGraphicLst->Insert(_stu);
		mGraphicCount++;
		break;
	}

	return true;
}

bool CDataBaseManager::Delete(CStudent* _stu, int _code)
{
	bool result = false;

	switch (_code)
	{
	case PROGRAMMING:
		result = mProgramLst->Delete(_stu);
		if (result)
		{
			mProgramCount--;
		}

		break;
	case DESIGN:
		result = mDesignLst->Delete(_stu);
		if (result)
		{
			mDesignCount--;
		}

		break;
	case GRAPHIC:
		result = mGraphicLst->Delete(_stu);
		if (result)
		{
			mGraphicCount--;
		}

		break;
	}

	return result;
}

bool CDataBaseManager::GetData(CStudent** _stu, int _code)
{

	if (!mData)
	{
		switch (_code)
		{
		case PROGRAMMING:
			mData = mProgramLst->GetmHead()->GetmNext();
			break;
		case DESIGN:
			mData = mDesignLst->GetmHead()->GetmNext();
			break;
		case GRAPHIC:
			mData = mGraphicLst->GetmHead()->GetmNext();
			break;
		}
	}
	else
	{
		mData = mData->GetmNext();
	}

	if (mData)
	{
		*_stu = mData->GetmData();
		return true;
	}

	return false;
}

void CDataBaseManager::GetDataEnd()
{
	mData = nullptr;
}

int	 CDataBaseManager::GetCount(int _code)
{
	switch (_code)
	{
	case PROGRAMMING:
		return mProgramCount;

	case DESIGN:
		return mDesignCount;

	case GRAPHIC:
		return mGraphicCount;
	}

	return -1;
}