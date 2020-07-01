#include "DesignManager.h"
char* CDesignManager::mSubjectName[] = {"���ӱ�ȹ����", "���ӽó�����", "����������"};

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

	cout << "�̸�:";
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
		
		cout << "�̸�:" << stu->GetName() << endl;
		cout << "�й�:" << stu->GetId() << endl;

		for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
		{
			cout << mSubjectName[j] << ":";
			cout << stu->GetSubject(j) << endl;
		}

		stu->CalculateGrade();
		
		cout << "����:";
		cout << stu->GetGrade() << endl;	
			
	}

	DataManager->GetDataEnd();

}

void CDesignManager::Search()
{
	char id[IDSIZE];
	cout << "�й�:";
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
			
			cout << "�̸�:" << stu->GetName() << endl;
			cout << "�й�:" << stu->GetId() << endl;

			for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
			{
				cout << mSubjectName[j] << ":";
				cout << stu->GetSubject(j) << endl;
			}

			stu->CalculateGrade();

			cout << "����:";
			cout << stu->GetGrade() << endl;
			break;
		}

	}

	DataManager->GetDataEnd();
}
