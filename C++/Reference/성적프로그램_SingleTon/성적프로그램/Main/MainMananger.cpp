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
		cout << "<�������α׷�>" << endl;
		cout << "1.�����Է�" << endl;
		cout << "2.����" << endl;
		cout << "3.�������" << endl;
		cout << "4.������ȸ" << endl;
		cout << "5.����" << endl;	
		cout << "����:";

		cin >> select;
		rewind(stdin);
		if (select < INPUT || select > EXIT)
		{
			cout << "�߸� �Է��߽��ϴ�." << endl;
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
		cout << "(���α׷���:1, �׷���:2, ��ȹ:3)" << endl;
		cout << "����:";
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
			cout << "�߸� �Է��߽��ϴ�." << endl;
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
			manager = MajorSelect("<<�����Է�>>");
			manager->Input();
			break;
		case DELETE:
			manager = MajorSelect("<<�����Է�>>");
			manager->Delete();
			break;
		case SHOWDATA:
			manager = MajorSelect("<<�������>>");
			manager->Display();
			break;
		case SEARCHDATA:
			manager->Search();
			break;
		case EXIT:
			return;
			break;	
		default:
			cout << "�߸� �Է��߽��ϴ� �ٽ� �Է��ϼ��� " << endl;		
		}
	}
}