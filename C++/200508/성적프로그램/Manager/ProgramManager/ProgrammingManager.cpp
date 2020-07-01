#include "ProgrammingManager.h"
const char* CProgrammingManager::mSubjectName[] = { "C++2", "C#", "API2" };

CProgrammingManager::CProgrammingManager()
{
	
}

CProgrammingManager::~CProgrammingManager()
{
	
}

bool CProgrammingManager::Fillter()
{
	mStudent = mDBMng->Pass();
	if (!strncmp(mStudent->GetId(), "20032", 5))
		return true;
	return false;
}

void CProgrammingManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];
	int  score;

	cout << "�̸�:";
	cin >> name;

	sprintf(id, "20%s%03d", PROGRAM_CODE, mStuCount+1);

	CStudent* ptr = new CStudent(name, id);

	for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
	{
		cout << mSubjectName[i] << ":";
		cin >> score;
		ptr->SetSubject(score, i);
	}

	mStuCount++;
	mStudent = ptr;
	mDBMng->Save(mStudent);

}

void CProgrammingManager::Display()
{	
	mDBMng->ResetCount();
	int count = 0;
	while (count < mStuCount)
	{
		if (Fillter())
		{
			count++;
			cout << "�̸�:" << mStudent->GetName() << endl;
			cout << "�й�:" << mStudent->GetId() << endl;
			for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
			{
				cout << mSubjectName[i] << ":";
				cout << mStudent->GetSubject(i) << endl;
			}
				
			mStudent->CalculateGrade();

			cout << "����:";
			cout << mStudent->GetGrade() << endl;
		}
	}
	
}

void CProgrammingManager::Search()
{
	char id[IDSIZE];	
	cout << "�й�:";
	cin >> id;

	mDBMng->ResetCount();
	int count = 0;
	while (count < mStuCount)
	{
		if (Fillter())
		{
			count++;
			if (!strcmp(mStudent->GetId(), id))
			{
				cout << "�̸�:" << mStudent->GetName() << endl;
				cout << "�й�:" << mStudent->GetId() << endl;
				for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
				{
					cout << mSubjectName[i] << ":";
					cout << mStudent->GetSubject(i) << endl;
				}

				mStudent->CalculateGrade();

				cout << "����:";
				cout << mStudent->GetGrade() << endl;
			}
		}
	}
}
