#include "MainManager.h"
#include "BookManager.h"
#include "UserManager.h"
MainManager* MainManager::Instance = nullptr;
MainManager::MainManager()
{

}
MainManager::~MainManager()
{

}
void MainManager::Create()
{
	if (!Instance)
	{
		Instance = new MainManager();
	}
	UserManager::Create();
	BookManager::Create();
}
void MainManager::Destroy()
{
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
	UserManager::Destroy();
	BookManager::Destroy();
}
MainManager* MainManager::GetInstance()
{
	return Instance;
}
void MainManager::Run()
{
	BookManager::GetInstance()->Initialize();
	while (1)
	{
		bool endflag = false;

		int select = MainMenu();

		switch (select)
		{
		case JOIN:
			UserManager::GetInstance()->Join();
			break;
		case LOGIN:
			if (UserManager::GetInstance()->LoginSystem())
			{
				while (UserManager::GetInstance()->GetNowUser()->GetLoginState())
				{
					select = LoginMenu();
					switch (select)
					{
					case SEARCH:
						BookManager::GetInstance()->Search();
						break;
					case RENT:
						BookManager::GetInstance()->RentBook();
						break;
					case RETURN:
						BookManager::GetInstance()->ReturnBook();
						break;
					case LOGOUT:
						UserManager::GetInstance()->Logout();
						break;
					case DROP:
						UserManager::GetInstance()->Drop();
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
			continue;
		}

		if (endflag)
		{
			break;
		}
	}


}
MAIN_MENU MainManager::MainMenu()
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

LOGIN_MENU MainManager::LoginMenu()
{
	LOGIN_MENU select;

	while (1)
	{
		cout << "<메뉴>" << endl;
		cout << "1.도서검색" << endl;
		cout << "2.도서대여" << endl;
		cout << "3.도서반납" << endl;
		cout << "4.로그아웃" << endl;
		cout << "5.회원탈퇴" << endl;
		cout << "선택:";


		cin >> select;

		if (select < 1 || select>5)
		{
			cout << "잘못입력했습니다" << endl;
			continue;
		}
		break;
	}

	return select;

}