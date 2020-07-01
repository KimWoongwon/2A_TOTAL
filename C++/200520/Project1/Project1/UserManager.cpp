#include "UserManager.h"
UserManager* UserManager::Instance = nullptr;
UserManager::UserManager()
{
	memset(m_UserList, 0, sizeof(m_UserList));
	m_UserCount = 0;

}

UserManager::~UserManager()
{
	for (int i = 0; i < m_UserCount; i++)
	{
		if (m_UserList[i] != nullptr)
		{
			delete m_UserList[i];
			m_UserList[i] = nullptr;
		}
	}
}
void UserManager::Create()
{
	if (!Instance)
	{
		Instance = new UserManager();
	}
}
void UserManager::Destroy()
{
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
UserManager* UserManager::GetInstance()
{
	return Instance;
}
USER* UserManager::GetNowUser()
{
	return m_NowUser;
}
void UserManager::Join()
{
	char id[10];
	char pw[10];

	cout << "ID:";
	cin >> id;

	bool flag = false;
	for (int i = 0; i < m_UserCount; i++)
	{
		if (strcmp(m_UserList[i]->GetID(), id) == 0)
		{
			flag = true;
			break;
		}
	}

	if (flag)
	{
		cout << "이미 존재하는 아이디입니다" << endl;
		return;
	}

	cout << "PW:";
	cin >> pw;

	m_UserList[m_UserCount++] = new USER(id, pw);

	return;

}

bool UserManager::LoginSystem()
{
	char id[10];
	char pw[10];


	cout << "ID:";
	cin >> id;

	USER* ptr = nullptr;

	for (int i = 0; i < m_UserCount; i++)
	{
		if (strcmp(m_UserList[i]->GetID(), id) == 0)
		{
			ptr = m_UserList[i];
			break;
		}
	}

	if (ptr == nullptr)
	{
		cout << "없는 아이디입니다" << endl;
		return false;
	}

	cout << "PW:";
	cin >> pw;

	if (strcmp(ptr->GetPW(), pw) == 0)
	{
		m_NowUser = ptr;
		m_NowUser->SetLogin();
	}
	else
	{
		cout << "패스워드가 틀렸습니다" << endl;
		return false;
	}

	return true;

}

void UserManager::Logout()
{
	m_NowUser->SetLogout();
}

void UserManager::Drop()
{
	for (int i = 0; i < m_UserCount; i++)
	{
		if (m_UserList[i] == m_NowUser)
		{
			delete m_UserList[i];
			for (int j = i; j < m_UserCount - 1; j++)
			{
				m_UserList[j] = m_UserList[j + 1];
			}
			m_UserList[m_UserCount - 1] = nullptr;
			break;
		}
	}

	m_UserCount--;

}