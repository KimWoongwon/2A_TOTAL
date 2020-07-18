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
void CUserManager::Initialize() // 파일에서 유저정보 가져오기
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
void CUserManager::SaveInfo(CUser* user)	// 파일에 유저정보 저장하기
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
bool CUserManager::Input(CUser* user)	// 해당 유저를 리스트에 추가합니다.
{
	mUserList->Insert(user);
	UserListCount++;
	SaveInfo(user);
	return true;
}

bool CUserManager::Delete(CUser* user)	// 해당 유저의 정보를 삭제합니다.
{
	bool result = false;

	result = mUserList->Delete(user);
	if (result)
		UserListCount--;

	return result;
}

bool CUserManager::GetData(CUser** _user)
{
	
	if (!mData)	// 초기일때 = nullptr일때
	{
		mData = mUserList->GetmHead()->GetmNext();
	}
	else		// 초기가 아닐때 다음 노드로 설정
	{
		mData = mData->GetmNext();
	}

	if (mData)	// 노드가 nullptr이 아니면 데이터 반환
	{
		*_user = mData->GetmData();
		return true;
	}

	return false;
}

void CUserManager::GetDataEnd()	// 노드가 nullptr이면 초기값입니다.
{
	mData = nullptr;
}

int	 CUserManager::GetCount()
{
	return UserListCount;
}
