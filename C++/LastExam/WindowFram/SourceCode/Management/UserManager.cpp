#include "UserManager.h"
IMPLEMENT_SINGLETON(CUserManager)
CUserManager::CUserManager()
{
	mUserList = new CLinkedList<CUser*>;
	mData = nullptr;
	UserListCount = 0;
}
CUserManager::~CUserManager()
{
	delete mUserList;
}
void CUserManager::Initialize() // ���Ͽ��� �������� ��������
{
	ifstream File;
	File.open("UserList.txt");
	
	char temparr[256];
	char* id;
	char* pw;
	CUser* tempUser = nullptr;
	if (File.is_open())
	{
		while (!File.eof())
		{
			File.getline(temparr, 256);
			if (!strcmp(temparr, ""))
				break;

			id = strtok(temparr, "|");
			pw = strtok(NULL, "|");

			tempUser = new CUser(id, pw);
			mUserList->Insert(tempUser);
			UserListCount++;
		}
	}
	File.close();
}
void CUserManager::SaveInfo(CUser* user)	// ���Ͽ� �������� �����ϱ�
{
	ofstream File;
	File.open("UserList.txt");
	string temp;

	CNode<CUser*>* ptr = mUserList->GetmHead();
	if (File.is_open())
	{
		do
		{
			ptr = ptr->GetmNext();
			if (ptr->GetmData() == nullptr)
				break;
			temp += user->GetId();
			temp += "|";
			temp += user->GetPw();
			temp += "\n";

			File.write(temp.c_str(), temp.size());
			temp = "";

		} while (ptr->GetmNext() != NULL);

	}
	

	File.write(temp.c_str(), temp.size());
	File.close();
}
bool CUserManager::Input(CUser* user)	// �ش� ������ ����Ʈ�� �߰��մϴ�.
{
	mUserList->Insert(user);
	UserListCount++;
	SaveInfo(user);
	return true;
}

bool CUserManager::Delete(CUser* user)	// �ش� ������ ������ �����մϴ�.
{
	bool result = false;

	result = mUserList->Delete(user);
	if (result)
		UserListCount--;

	return result;
}

bool CUserManager::GetData(CUser** _user)
{
	
	if (!mData)	// �ʱ��϶� = nullptr�϶�
	{
		mData = mUserList->GetmHead()->GetmNext();
	}
	else		// �ʱⰡ �ƴҶ� ���� ���� ����
	{
		mData = mData->GetmNext();
	}

	if (mData)	// ��尡 nullptr�� �ƴϸ� ������ ��ȯ
	{
		*_user = mData->GetmData();
		return true;
	}

	return false;
}

void CUserManager::GetDataEnd()	// ��尡 nullptr�̸� �ʱⰪ�Դϴ�.
{
	mData = nullptr;
}

int	 CUserManager::GetCount()
{
	return UserListCount;
}
