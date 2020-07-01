#include "GraphicManager.h"
const char* CGraphicManager::mSubjectName[] = { "2D", "3D", "�����" };

CGraphicManager::CGraphicManager()
{
	

}

CGraphicManager::~CGraphicManager()
{

	
}

bool CGraphicManager::Fillter()
{
	mStudent = mDBMng->Pass();
	if (!strncmp(mStudent->GetId(), "20033", 5))
		return true;
	return false;
}

void CGraphicManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];
	int  score;

	cout << "�̸�:";
	cin >> name;

	sprintf(id, "20%s%03d", GRAPHIC_CODE, mStuCount + 1);

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

void CGraphicManager::Display()
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

void CGraphicManager::Search()
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
