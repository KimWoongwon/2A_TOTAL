#include "DesignManager.h"
char* CDesignManager::mSubjectName[] = {"게임기획기초", "게임시나리오", "레벨디자인"};

CDesignManager::CDesignManager()
{
	

}

CDesignManager::~CDesignManager()
{

	
}

void CDesignManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];	
	int  score;

	cout << "이름:";
	cin >> name;
	
	sprintf(id, "20%s%03d", DESIGN_CODE, DataManager->GetCount(DESIGN)+1);

	CStudent* ptr = new CStudent(name, id);

	for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
	{
		cout << mSubjectName[i] << ":";
		cin >> score;
		ptr->SetSubject(score, i);
	}

	DataManager->Input(ptr, DESIGN);
}

void CDesignManager::Display()
{	
	CStudent* stu = nullptr;

	while (1)
	{
		if (!DataManager->GetData(&stu, DESIGN))
		{
			break;
		}
		
		cout << "이름:" << stu->GetName() << endl;
		cout << "학번:" << stu->GetId() << endl;

		for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
		{
			cout << mSubjectName[j] << ":";
			cout << stu->GetSubject(j) << endl;
		}

		stu->CalculateGrade();
		
		cout << "평점:";
		cout << stu->GetGrade() << endl;	
			
	}

	DataManager->GetDataEnd();

}

void CDesignManager::Search()
{
	char id[IDSIZE];
	cout << "학번:";
	cin >> id;

	CStudent* stu = nullptr;

	while (1)
	{
		if (!DataManager->GetData(&stu, DESIGN))
		{
			break;
		}

		if (!strcmp(stu->GetId(), id))
		{
			
			cout << "이름:" << stu->GetName() << endl;
			cout << "학번:" << stu->GetId() << endl;

			for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
			{
				cout << mSubjectName[j] << ":";
				cout << stu->GetSubject(j) << endl;
			}

			stu->CalculateGrade();

			cout << "평점:";
			cout << stu->GetGrade() << endl;
			break;
		}

	}

	DataManager->GetDataEnd();
}
