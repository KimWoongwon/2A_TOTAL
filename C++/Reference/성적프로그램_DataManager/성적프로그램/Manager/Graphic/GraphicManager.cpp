#include "GraphicManager.h"
char* CGraphicManager::mSubjectName[] = { "2D", "3D", "드로잉" };

CGraphicManager::CGraphicManager()
{
	

}

CGraphicManager::~CGraphicManager()
{

	
}

void CGraphicManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];
	int  score;

	cout << "이름:";
	cin >> name;
	
	sprintf(id, "20%s%03d", GRAPHIC_CODE, DataManager->GetCount(GRAPHIC)+1);

	CStudent* ptr = new CStudent(name, id);

	for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
	{
		cout << mSubjectName[i] << ":";
		cin >> score;
		ptr->SetSubject(score, i);
	}

	DataManager->Input(ptr, GRAPHIC);
	
}

void CGraphicManager::Display()
{
	CStudent* stu = nullptr;

	while (1)
	{
		if (!DataManager->GetData(&stu, GRAPHIC))
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

void CGraphicManager::Search()
{
	char id[IDSIZE];
	cout << "학번:";
	cin >> id;

	CStudent* stu = nullptr;

	while (1)
	{
		if (!DataManager->GetData(&stu, GRAPHIC))
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
