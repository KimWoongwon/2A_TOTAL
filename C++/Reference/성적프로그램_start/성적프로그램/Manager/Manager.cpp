#include "Manager.h"


char* CManager::mSubjectName[] = { "C++2", "C#", "API2" };

CManager::CManager()
{
	for (int i = 0; i < MAXSTUDENT; i++)
	{
		mStuLst[i] = nullptr;
	}

	mCount = 0;
}

CManager::~CManager()
{
	for (int i = 0; i < mCount; i++)
	{
		delete mStuLst[i];
	}

}

void CManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];	
	int  score;


	cout << "<�����Է�>" << endl;

	cout << "�̸�:";
	cin >> name;
	cout << "�й�:";
	cin >> id;

	mStuLst[mCount] = new CStudent(name, id);
	for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
	{
		cout << mSubjectName[i] << ":";
		cin >> score;
		mStuLst[mCount]->SetSubject(score, i);
	}
	mStuLst[mCount]->CalculateGrade();
	mCount++;

}

void CManager::ShowData()
{
	for (int i = 0; i < mCount; i++)
	{
		cout << "�̸�:" << mStuLst[i]->GetName() << endl;
		cout << "�й�:" << mStuLst[i]->GetId() << endl;
		for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
		{
			cout << mSubjectName[j] << ":" << mStuLst[i]->GetSubject(j) << endl;
		}
		cout << "����:" << mStuLst[i]->GetGrade() << endl;
	}
}

void CManager::SearchData()
{	
	char id[IDSIZE];
	bool flag = false;

	cout << "<�������>" << endl;
	cout << "�й�:";
	cin >> id;

	for (int i = 0; i < mCount; i++)
	{
		if (!strcmp(mStuLst[i]->GetId(), id))
		{
			cout << "�̸�:" << mStuLst[i]->GetName() << endl;
			cout << "�й�:" << mStuLst[i]->GetId() << endl;
			for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
			{
				cout << mSubjectName[j] << ":" << mStuLst[i]->GetSubject(j) << endl;
			}
			cout << "����:" << mStuLst[i]->GetGrade() << endl;
			flag = true;
			break;
		}
	}



	if (!flag)
	{
		cout << "���� �й��Դϴ�" << endl;
	}



}

void CManager::ShowMenu()
{
	cout << "<�������α׷�>" << endl;
	cout << "1.�����Է�" << endl;
	cout << "2.������ȸ" << endl;
	cout << "3.�������" << endl;
	cout << "4.����" << endl;
	cout << "����:";
}

void CManager::Run()
{
	int select;
	while (1)
	{ 
		ShowMenu();
		cin >> select;

		switch (select)
		{
		case INPUT:
			Input();
			break;
		case SEARCH:
			SearchData();
			break;
		case SHOWDATA:
			ShowData();
			break;
		case EXIT:
			return;			
		default:
			cout << "�߸� �Է��߽��ϴ� �ٽ� �Է��ϼ��� " << endl;			
		}
	}
	

}