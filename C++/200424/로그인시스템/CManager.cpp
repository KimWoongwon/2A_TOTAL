#include "CManager.h"
#include "List.h"
#include "List.cpp"

CManager::CManager()
{
	mUserLst = new List<CUser*>;
	mNowUser = NULL;
	mUserCount = 0;
}

CManager::~CManager()
{
	delete mUserLst;
}

void CManager::Run()
{
	while (1)
	{
		bool endflag = false;		

		int select = MainMenu();

		switch (select)
		{
		case JOIN:
			Join();
			break;
		case LOGIN:
			if (Login())
			{
				select = LoginMenu();

				switch (select)
				{
				case LOGOUT:
					mNowUser->SetLogout();
					break;
				case DROP:
					Drop();
					break;
				}
			}			
			break;
		case EXIT:
			endflag = true;
			break;
		default:
			cout << "�߸��Է��߽��ϴ�" << endl;
			continue;
		}

		if (endflag)
		{
			break;
		}
	}

	
}

bool CManager::Join()
{
	char id[10];
	char pw[10];

	cout << "ID:";
	cin >> id;

	bool flag = false;
	for (int i = 0; i < mUserCount; i++)
	{
		if (strcmp(mUserLst->DataOut(i)->GetId(), id) == 0)
		{
			flag = true;
			break;
		}
	}

	if (flag)
	{
		cout << "�̹� �����ϴ� ���̵��Դϴ�" << endl;
		return false;
	}

	cout << "PW:";
	cin >> pw;
	CUser* temp = new CUser(id, pw, mUserCount);
	mUserLst->Insert(temp);
	mUserCount++;
	return true;

}

bool CManager::Login()
{
	char id[10];
	char pw[10];
	bool check = false;

	cout << "ID:";
	cin >> id;
	
	CUser* ptr = nullptr;
	for (int i = 0; i < mUserCount; i++)
	{
		if (!strcmp(mUserLst->DataOut(i)->GetId(), id))
		{
			check = true;
			ptr = mUserLst->DataOut(i);
			break;
		}
			
	}
	
	if (!check)
	{
		cout << "���� ���̵��Դϴ�" << endl;
		return false;
	}

	cout << "PW:";
	cin >> pw;

	if (strcmp(ptr->GetPw(), pw) == 0)
	{		
		mNowUser = ptr;
		mNowUser->SetLogin();		
	}
	else
	{
		cout << "�н����尡 Ʋ�Ƚ��ϴ�" << endl;
		return false;
	}

	return true;

}

MAIN_MENU CManager::MainMenu()
{
	MAIN_MENU select;	

	while (1)
	{
		cout << "<�޴�>" << endl;
		cout << "1.ȸ������" << endl;
		cout << "2.�α���" << endl;
		cout << "3.����" << endl;
		cout << "����:";


		cin >> select;

		if (select < JOIN || select>3)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			continue;
		}
		break;
	}

	return select;
}

LOGIN_MENU CManager::LoginMenu()
{
	LOGIN_MENU select;

	while (1)
	{		
		cout << "<�޴�>" << endl;
		cout << "1.�α׾ƿ�" << endl;
		cout << "2.ȸ��Ż��" << endl;	
		cout << "����:";

		
		cin >> select;

		if (select<1 || select>2)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			continue;
		}
		break;
	}

	return select;
	
}

void CManager::Logout()
{
	mNowUser->SetLogout();
}

void CManager::Drop()
{
	for (int i = 0; i < mUserCount; i++)
	{
		if (mUserLst->DataOut(i) == mNowUser)
		{
			mUserLst->Delete(mNowUser);
		}
	}
	mUserCount--;
}