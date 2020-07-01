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
	m_BookList[m_BookCount] = new BOOK("C++��������", 5);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("TCP/IP���� ���α׷���", 10);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("���Ӿ˰���", 20);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("���ӿ���", 5);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
	m_BookList[m_BookCount] = new BOOK("�������α׷��ֱ���", 12);
	m_BookList[m_BookCount++]->SetCode(m_BookCount);
}
void BookManager::Search()
{
	char tempBname[20];
	cout << "������ : ";
	cin >> tempBname;

	for (int i = 0; i < m_BookCount; i++)
	{
		if (!strcmp(m_BookList[i]->GetName(), tempBname))
		{
			cout << "���� �ڵ� : " << m_BookList[i]->GetCode() << endl;
			return;
		}
	}
	cout << "ã�� ������ �����ϴ�." << endl;
	return;
}
void BookManager::RentBook()
{
	char tempCode[20];
	int num = 0;
	cout << "�뿩�� ���� �ڵ� : ";
	cin >> tempCode;
	cout << "�뿩�Ǽ� : ";
	cin >> num;

	for (int i = 0; i < m_BookCount; i++)
	{
		if (!strcmp(m_BookList[i]->GetCode(), tempCode))
		{
			UserManager::GetInstance()->GetNowUser()->InsertItem(tempCode, num);
			return;
		}
	}
	cout << "ã�� ������ �����ϴ�." << endl;
}
void BookManager::ReturnBook()
{
	char tempCode[20];
	int num = 0;
	cout << "�ݳ��� ���� �ڵ� : ";
	cin >> tempCode;
	cout << "�ݳ��Ǽ� : ";
	cin >> num;

	for (int i = 0; i < m_BookCount; i++)
	{
		if (!strcmp(m_BookList[i]->GetCode(), tempCode))
		{
			UserManager::GetInstance()->GetNowUser()->RemoveItem(tempCode, num);
			return;
		}
	}
	cout << "�߸��� ������ �Է��߽��ϴ�." << endl;
	
}