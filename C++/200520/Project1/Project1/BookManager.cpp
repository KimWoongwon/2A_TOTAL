#include "BookManager.h"
#include "UserManager.h"

BookManager* BookManager::Instance = nullptr;
BookManager::BookManager()
{
	memset(m_BookList, 0, sizeof(m_BookList));
	m_BookCount = 0;
	
}
BookManager::~BookManager()
{
	for (int i = 0; i < m_BookCount; i++)
	{
		if (m_BookList[i] != nullptr)
		{
			delete m_BookList[i];
			m_BookList[i] = nullptr;
		}
	}
}
void BookManager::Create()
{
	if (!Instance)
	{
		Instance = new BookManager();
	}
}
void BookManager::Destroy()
{
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
BookManager* BookManager::GetInstance()
{
	return Instance;
}
void BookManager::Initialize()
{
	m_BookList[m_BookCount] = new BOOK("C++완전정복", 5);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("TCP/IP소켓 프로그래밍", 10);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("게임알고리즘", 20);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("게임엔진", 5);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("게임프로그래밍기초", 12);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
}
void BookManager::Search()
{
	char tempBname[20];
	cout << "도서명 : ";
	cin >> tempBname;

	for (int i = 0; i < m_BookCount; i++)
	{
		if (!strcmp(m_BookList[i]->GetName(), tempBname))
		{
			cout << "도서 코드 : " << m_BookList[i]->GetCode() << endl;
			return;
		}
	}
	cout << "찾는 도서가 없습니다." << endl;
	return;
}
void BookManager::RentBook()
{
	char tempCode[20];
	int num = 0;
	cout << "대여할 도서 코드 : ";
	cin >> tempCode;
	cout << "대여권수 : ";
	cin >> num;

	for (int i = 0; i < m_BookCount; i++)
	{
		if (!strcmp(m_BookList[i]->GetCode(), tempCode))
		{
			UserManager::GetInstance()->GetNowUser()->InsertItem(tempCode, num);
			return;
		}
	}
	cout << "찾는 도서가 없습니다." << endl;
}
void BookManager::ReturnBook()
{
	char tempCode[20];
	int num = 0;
	cout << "반납할 도서 코드 : ";
	cin >> tempCode;
	cout << "반납권수 : ";
	cin >> num;

	for (int i = 0; i < m_BookCount; i++)
	{
		if (!strcmp(m_BookList[i]->GetCode(), tempCode))
		{
			UserManager::GetInstance()->GetNowUser()->RemoveItem(tempCode, num);
			return;
		}
	}
	cout << "잘못된 정보를 입력했습니다." << endl;
	
}