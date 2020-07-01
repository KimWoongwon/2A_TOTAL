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
			cout << "잘못입력했습니다" << endl;
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
		cout << "이미 존재하는 아이디입니다" << endl;
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
		cout << "없는 아이디입니다" << endl;
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
		cout << "패스워드가 틀렸습니다" << endl;
		return false;
	}

	return true;

}

MAIN_MENU CManager::MainMenu()
{
	MAIN_MENU select;	

	while (1)
	{
		cout << "<메뉴>" << endl;
		cout << "1.회원가입" << endl;
		cout << "2.로그인" << endl;
		cout << "3.종료" << endl;
		cout << "선택:";


		cin >> select;

		if (select < JOIN || select>3)
		{
			cout << "잘못입력했습니다" << endl;
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
		cout << "<메뉴>" << endl;
		cout << "1.로그아웃" << endl;
		cout << "2.회원탈퇴" << endl;	
		cout << "선택:";

		
		cin >> select;

		if (select<1 || select>2)
		{
			cout << "잘못입력했습니다" << endl;
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