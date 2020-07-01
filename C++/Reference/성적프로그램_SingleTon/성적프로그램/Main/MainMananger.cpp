#include "MainManager.h"

CMainManager*	CMainManager::mPthis = nullptr;

void CMainManager::Create()
{
	if (!mPthis)
	{
		mPthis = new CMainManager();
	}

	CProgrammingManager::Create();
	CGraphicManager::Create();
	CDesignManager::Create();
	CDataBaseManager::Create();
}

CMainManager* CMainManager::GetInstance()
{
	return mPthis;
}

void CMainManager::Destroy()
{
	CProgrammingManager::Destroy();
	CGraphicManager::Destroy();
	CDesignManager::Destroy();
	CDataBaseManager::Destroy();

	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}

	
}
CMainManager::CMainManager()
{
	
}

void CMainManager::Initialize()
{
	CProgrammingManager::GetInstance()->Initialize();
	CGraphicManager::GetInstance()->Initialize();
	CDesignManager::GetInstance()->Initialize();
	CDataBaseManager::GetInstance()->Initialize();
}


CMainManager::~CMainManager()
{
	

}

int CMainManager::SelectMainMenu()
{
	int select;

	while (1)
	{
		cout << "<성적프로그램>" << endl;
		cout << "1.성적입력" << endl;
		cout << "2.삭제" << endl;
		cout << "3.성적출력" << endl;
		cout << "4.성적조회" << endl;
		cout << "5.종료" << endl;	
		cout << "선택:";

		cin >> select;
		rewind(stdin);
		if (select < INPUT || select > EXIT)
		{
			cout << "잘못 입력했습니다." << endl;
			continue;
		}
		break;
	}

	return select;

}

CManager*	CMainManager::MajorSelect(const char* _title)
{
	int select;

	while (1)
	{
		cout << _title << endl;
		cout << "(프로그래밍:1, 그래픽:2, 기획:3)" << endl;
		cout << "선택:";
		int select;
		cin >> select;

		switch (select)
		{
		case PROGRAMMING:
			return  CProgrammingManager::GetInstance();
			break;
		case GRAPHIC:
			return CGraphicManager::GetInstance();
			break;
		case DESIGN:
			return CDesignManager::GetInstance();
			break;
		default:
			cout << "잘못 입력했습니다." << endl;
			continue;
		}
		break;
	}
}

void CMainManager::Run()
{
	
	CManager* manager = nullptr;

	while (1)
	{
		int select=SelectMainMenu();
		
		switch (select)
		{
		case INPUT:	
			manager = MajorSelect("<<성적입력>>");
			manager->Input();
			break;
		case DELETE:
			manager = MajorSelect("<<성적입력>>");
			manager->Delete();
			break;
		case SHOWDATA:
			manager = MajorSelect("<<성적출력>>");
			manager->Display();
			break;
		case SEARCHDATA:
			manager->Search();
			break;
		case EXIT:
			return;
			break;	
		default:
			cout << "잘못 입력했습니다 다시 입력하세요 " << endl;		
		}
	}
}