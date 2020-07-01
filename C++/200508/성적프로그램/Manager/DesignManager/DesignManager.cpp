#include "DesignManager.h"
const char* CDesignManager::mSubjectName[] = {"게임기획기초", "게임시나리오", "레벨디자인"};

CDesignManager::CDesignManager()
{
	

}

CDesignManager::~CDesignManager()
{

	
}

bool CDesignManager::Fillter()
{
	mStudent = mDBMng->Pass();
	if (!strncmp(mStudent->GetId(), "20031", 5))
		return true;
	return false;
}

void CDesignManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];
	int  score;

	cout << "이름:";
	cin >> name;

	sprintf(id, "20%s%03d", DESIGN_CODE, mStuCount + 1);

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

void CDesignManager::Display()
{

	mDBMng->ResetCount();
	int count = 0;
	while (count < mStuCount)
	{
		if (Fillter())
		{
			count++;
			cout << "이름:" << mStudent->GetName() << endl;
			cout << "학번:" << mStudent->GetId() << endl;
			for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
			{
				cout << mSubjectName[i] << ":";
				cout << mStudent->GetSubject(i) << endl;
			}

			mStudent->CalculateGrade();

			cout << "평점:";
			cout << mStudent->GetGrade() << endl;
		}
	}
}

void CDesignManager::Search()
{
	char id[IDSIZE];
	cout << "학번:";
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
				cout << "이름:" << mStudent->GetName() << endl;
				cout << "학번:" << mStudent->GetId() << endl;
				for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
				{
					cout << mSubjectName[i] << ":";
					cout << mStudent->GetSubject(i) << endl;
				}

				mStudent->CalculateGrade();

				cout << "평점:";
				cout << mStudent->GetGrade() << endl;
			}
		}
	}
}
