#include "GraphicManager.h"
char* CGraphicManager::mSubjectName[] = { "2D", "3D", "드로잉" };

CGraphicManager*	CGraphicManager::mPthis = nullptr;

void CGraphicManager::Create()
{
	if (!mPthis)
	{
		mPthis = new CGraphicManager();
	}
}

CGraphicManager* CGraphicManager::GetInstance()
{
	return mPthis;
}

void CGraphicManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}
CGraphicManager::CGraphicManager()
{
	

}

CGraphicManager::~CGraphicManager()
{

	
}

void CGraphicManager::Initialize()
{

}

void CGraphicManager::Input()
{
	char name[NAMESIZE];
	char id[IDSIZE];
	int  score;

	cout << "이름:";
	cin >> name;

	sprintf(id, "20%s%03d", GRAPHIC_CODE, CDataBaseManager::GetInstance()->GetCount(GRAPHIC) + 1);

	CStudent* ptr = new CStudent(name, id);

	for (int i = 0; i < sizeof(mSubjectName) / sizeof(char*); i++)
	{
		cout << mSubjectName[i] << ":";
		cin >> score;
		ptr->SetSubject(score, i);
	}

	CDataBaseManager::GetInstance()->Input(ptr, GRAPHIC);

}
void CGraphicManager::Delete()
{
	char name[NAMESIZE];
	char id[IDSIZE];
	int  score;

	cout << "이름:";
	cin >> name;

	CStudent* ptr = nullptr;

	while (1)
	{
		if (!CDataBaseManager::GetInstance()->GetData(&ptr, DESIGN))
			break;
		if (!strcmp(ptr->GetName(), name))
		{
			CDataBaseManager::GetInstance()->Delete(ptr, DESIGN);
			break;
		}
	}

	

}


void CGraphicManager::Display()
{
	CStudent* stu = nullptr;

	while (1)
	{
		if (!CDataBaseManager::GetInstance()->GetData(&stu, GRAPHIC))
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

	CDataBaseManager::GetInstance()->GetDataEnd();


}

void CGraphicManager::Search()
{
	char id[IDSIZE];
	cout << "학번:";
	cin >> id;

	CStudent* stu = nullptr;

	while (1)
	{
		if (!CDataBaseManager::GetInstance()->GetData(&stu, GRAPHIC))
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

	CDataBaseManager::GetInstance()->GetDataEnd();
}
