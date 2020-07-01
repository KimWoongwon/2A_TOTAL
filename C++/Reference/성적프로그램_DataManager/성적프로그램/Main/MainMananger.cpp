#include "MainManager.h"
CMainManager::CMainManager()
{
	mDesignMng = nullptr;
	mGraphicMng = nullptr;
	mProgramMng = nullptr;
}

void CMainManager::Initialize()
{
	mDesignMng = new CDesignManager();
	mGraphicMng = new CGraphicManager();
	mProgramMng = new CProgrammingManager();
}


CMainManager::~CMainManager()
{
	if (mDesignMng != nullptr)
	{
		delete mDesignMng;
	}

	if (mGraphicMng != nullptr)
	{
		delete mGraphicMng;
	}

	if (mProgramMng != nullptr)
	{
		delete mProgramMng;
	}

}

int CMainManager::ShowMenu()
{
	int select;

	cout << "<성적프로그램>" << endl;
	cout << "1.성적입력" << endl;
	cout << "2.성적출력" << endl;
	cout << "3.성적조회" << endl;
	cout << "4.종료" << endl;
	cout << "선택:";
	cin >> select;

	return select;

}

void CMainManager::Run()
{
	int select;

	Initialize();

	while (1)
	{
		select = ShowMenu();

		if (select == EXIT)
		{
			break;
		}

		CManager* manager = MajorSelect();
		switch (select)
		{
		case INPUT:
			manager->Input();
			break;
		case SHOWDATA:
			manager->Display();
			break;
		case SEARCHDATA:
			manager->Search();
			break;
		default:
			cout << "잘못 입력했습니다 다시 입력하세요 " << endl;
		}
	}
}

CManager* CMainManager::MajorSelect()
{
	while (1)
	{
		cout << "(프로그래밍:1, 그래픽:2, 기획:3)" << endl;
		cout << "선택:";
		int sel;
		cin >> sel;


		switch (sel)
		{
		case PROGRAMMING:
			return mProgramMng;
			break;
		case GRAPHIC:
			return mGraphicMng;
			break;
		case DESIGN:
			return mDesignMng;
			break;
		default:
			cout << "잘못 입력했습니다." << endl;
			continue;
		}

		break;
	}

	return nullptr;

}