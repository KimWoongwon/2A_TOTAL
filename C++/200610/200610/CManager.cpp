#include "CManager.h"
#include "HumanFactory.h"
#include "OrcFactory.h"
#include "ElfFactory.h"
CManager::CManager()
{
	memset(mUserLst, 0, sizeof(mUserLst));
	mUserCount = 0;

}

CManager::~CManager()
{
	for (int i = 0; i < mUserCount; i++)
	{
		if (mUserLst[i] != nullptr)
		{
			delete mUserLst[i];
			mUserLst[i] = nullptr;
		}
	}
}

void CManager::Run()
{
	
	while (1)
	{
		bool endflag = false;		

		int select = MainMenu();
		system("cls");
		int select2 = 0;
		switch (select)
		{
		case JOIN:
			Join();
			break;
		case LOGIN:
			if (Login())
			{
				while (mNowUser->GetLoginState())
				{
					select = LoginMenu();
					system("cls");
					CharacterFactory* FactorySelect = nullptr;
					switch (select)
					{
					case CREATE:
						select2 = CharMenu();
						switch (select2)
						{
						case HUM:
							FactorySelect = new HumanFactory();
							break;
						case ORC:
							FactorySelect = new OrcFactory();
							break;
						case ELF:
							FactorySelect = new ElfFactory();
							break;
						}
						mNowUser->InsertCharacter(FactorySelect->SettingCharacter());
						delete FactorySelect;
						FactorySelect = nullptr;
						system("cls");
						break;
					case DESTROY:
						mNowUser->DisplayCharacterInfo();
						char tempname[20];
						cout << "삭제할 캐릭터 이름 : ";
						cin >> tempname;
						mNowUser->RemoveCharacter(tempname);
						_getch();
						system("cls");
						break;
					case DISPLAY:
						mNowUser->DisplayCharacterInfo();
						_getch();
						system("cls");
						break;
					case LOGOUT:
						mNowUser->SetLogout();
						break;
					case DROP:
						Drop();
						break;
					}
				}
			}			
			break;
		case EXIT:
			endflag = true;
			break;
		default:
			cout << "잘못입력했습니다" << endl;
			_getch();
			system("cls");
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
		if (strcmp(mUserLst[i]->GetId(), id) == 0)
		{
			flag = true;
			break;
		}
	}

	if (flag)
	{
		cout << "이미 존재하는 아이디입니다" << endl;
		_getch();
		system("cls");
		return false;
	}

	cout << "PW:";
	cin >> pw;

	mUserLst[mUserCount++] = new CUser(id, pw);

	cout << "회원가입 완료" << endl;
	_getch();
	system("cls");
	return true;

}

bool CManager::Login()
{
	char id[10];
	char pw[10];


	cout << "ID:";
	cin >> id;

	CUser* ptr = nullptr;

	for (int i = 0; i < mUserCount; i++)
	{
		if (strcmp(mUserLst[i]->GetId(), id) == 0)
		{
			ptr = mUserLst[i];
			break;
		}
	}

	if (ptr==nullptr)
	{
		cout << "없는 아이디입니다" << endl;
		_getch();
		system("cls");
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
		_getch();
		system("cls");
		return false;
	}
	system("cls");
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
		cout << "1.캐릭터생성" << endl;
		cout << "2.캐릭터삭제" << endl;
		cout << "3.캐릭터출력" << endl;
		cout << "4.로그아웃" << endl;
		cout << "5.회원탈퇴" << endl;	
		cout << "선택:";

		
		cin >> select;

		if (select<1 || select>4)
		{
			cout << "잘못입력했습니다" << endl;
			continue;
		}
		break;
	}

	return select;
	
}

CHAR_MENU CManager::CharMenu()
{
	CHAR_MENU select;

	while (1)
	{
		cout << "<메뉴>" << endl;
		cout << "1.인간" << endl;
		cout << "2.오크" << endl;
		cout << "3.엘프" << endl;
		cout << "선택:";

		cin >> select;

		if (select < 1 || select>3)
		{
			cout << "잘못입력했습니다" << endl;
			continue;
		}
		break;
	}
	cout << "------------------------" << endl;
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
		if (mUserLst[i] == mNowUser)
		{
			delete mUserLst[i];
			for (int j = i; j < mUserCount - 1; j++)
			{
				mUserLst[j] = mUserLst[j + 1];
			}
			mUserLst[mUserCount - 1] = nullptr;
			break;
		}
	}

	mUserCount--;

}