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

	cout << "<�������α׷�>" << endl;
	cout << "1.�����Է�" << endl;
	cout << "2.�������" << endl;
	cout << "3.������ȸ" << endl;
	cout << "4.����" << endl;
	cout << "����:";
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
			cout << "�߸� �Է��߽��ϴ� �ٽ� �Է��ϼ��� " << endl;
		}
	}
}

CManager* CMainManager::MajorSelect()
{
	while (1)
	{
		cout << "(���α׷���:1, �׷���:2, ��ȹ:3)" << endl;
		cout << "����:";
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
			cout << "�߸� �Է��߽��ϴ�." << endl;
			continue;
		}

		break;
	}

	return nullptr;

}