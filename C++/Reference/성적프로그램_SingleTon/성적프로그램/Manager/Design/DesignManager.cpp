#include "DesignManager.h"
char* CDesignManager::mSubjectName[] = {"���ӱ�ȹ����", "���ӽó�����", "����������"};

CDesignManager*	CDesignManager::mPthis = nullptr;

void CDesignManager::Create()
{
	if (!mPthis)
	{
		mPthis = new CDesignManager();
	}
}

CDesignManager* CDesignManager::GetInstance()
{
	return mPthis;
}

void CDesignManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

void CDesignManager::Initialize()
{

}

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

	sprintf(id, "20%s%03d", DESIGN_CODE, CDataBaseManager::GetInstance()->GetCount(DESIGN) + 1);

	CStudent* ptr = new CStudent(name, id);

	for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
	{
		cout << mSubjectName[i] << ":";
		cin >> score;
		ptr->SetSubject(score, i);
	}

	CDataBaseManager::GetInstance()->Input(ptr, DESIGN);
}
void CDesignManager::Delete()
{
	char id[IDSIZE];

	cout << "id:";
	cin >> id;

	CStudent* ptr = nullptr;

	while (1)
	{
		if (!CDataBaseManager::GetInstance()->GetData(&ptr, DESIGN))
			break;
		if (!strcmp(ptr->GetId(), id))
		{
			CDataBaseManager::GetInstance()->Delete(ptr, DESIGN);
			break;
		}
	}

	

}

void CDesignManager::Display()
{	
	CStudent* stu = nullptr;

	while (1)
	{
		if (!CDataBaseManager::GetInstance()->GetData(&stu, DESIGN))
		{
			break;
		}

		CStudent* design_stu = (CStudent*)stu;
		cout << "�̸�:" << design_stu->GetName() << endl;
		cout << "�й�:" << design_stu->GetId() << endl;

		for (int j = 0; j < sizeof(mSubjectName) / sizeof(char*); j++)
		{
			cout << mSubjectName[j] << ":";
			cout << design_stu->GetSubject(j) << endl;
		}

		design_stu->CalculateGrade();
		
		cout << "����:";
		cout << design_stu->GetGrade() << endl;	
			
	}

	CDataBaseManager::GetInstance()->GetDataEnd();

}

void CDesignManager::Search()
{
	char id[IDSIZE];
	cout << "�й�:";
	cin >> id;

	CStudent* stu = nullptr;

	while (1)
	{
		if (!CDataBaseManager::GetInstance()->GetData(&stu, DESIGN))
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

	CDataBaseManager::GetInstance()->GetDataEnd();
}
