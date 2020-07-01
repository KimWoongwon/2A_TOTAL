#include "MainManager.h"
#include "ClothManager.h"
#include "FoodManager.h"
#include "ElectronicManager.h"
#include "BaseManager.h"
#include "DataBaseManager.h"
#include "Global.h"
MainManager* MainManager::Instance = nullptr; // static ��� �ν��Ͻ��� �ʱ�ȭ 
MainManager::MainManager() {} // �������� ������
MainManager::~MainManager() {} // �������� �Ҹ���

// �ν��Ͻ� �Ҵ� �Լ�
void MainManager::Create()
{
	// ���θŴ����� �ν��Ͻ��� �̹� �������� �ʾҴٸ� �Ҵ��� �մϴ�.
	if (!Instance)
		Instance = new MainManager();
	// ���Ŀ� ������ Create�Լ��� ȣ���ؼ� �� �Ŵ������� �ν��Ͻ��� �Ҵ��ϰԲ� �մϴ�.
	ClothManager::Create();
	FoodManager::Create();
	ElectronicManager::Create();
	DataBaseManager::Create();
}
void MainManager::Destroy()
{
	// ���θŴ����� �ν��Ͻ��� �����Ǿ��ִٸ� ������ �ϰ� �ν��Ͻ����� �ʱ�ȭ�մϴ�.
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
	// ���� �� �Ŵ����� Destroy�Լ��� ȣ���ؼ� ���θŴ����� ������� �� �Ŵ����鵵 �Բ� ������Բ� �մϴ�.
	ClothManager::Destroy();
	FoodManager::Destroy();
	ElectronicManager::Destroy();
	DataBaseManager::Destroy();
}
MainManager* MainManager::GetInstance()
{
	// �̱��������� �ν��Ͻ��� ���� �Ѱ��ִ� �Լ��Դϴ�.
	return Instance;
}
void MainManager::Initialaze()
{
	// �����Ŀ� �̴ϼȶ����� �Լ��� ȣ���ؼ� �� �Ŵ����� �ʿ��� �ʱⰪ�� �����մϴ�.
	ClothManager::GetInstance()->Initialaze();
	FoodManager::GetInstance()->Initialaze();
	ElectronicManager::GetInstance()->Initialaze();
	DataBaseManager::GetInstance()->Initialaze();
}

int MainManager::SelectMainMenu()
{
	// ���θ޴��� ����ϴ� �Լ��Դϴ�.
	int select;

	while (1)
	{
		
		cout << "<��ǰ���� ���α׷�>" << endl;
		cout << "1. �԰�" << endl;
		cout << "2. ���" << endl;
		cout << "3. ��� ��� ���" << endl;
		cout << "4. ��� �˻�" << endl;
		cout << "5. ��� ����" << endl;
		cout << "6. ���α׷� ����" << endl;
		cout << "����:";
		cin >> select;
		rewind(stdin);
		// ����ó��
		if (select < STORE || select > EXIT)
		{
			cout << "�߸� �Է��߽��ϴ�." << endl;
			continue;
		}
		break;
	}

	return select;

}
BaseManager* MainManager::MajorSelect()
{
	// �� �Ŵ������� ��� BaseManager�� ��ӹޱ� ������ 
	// �������� ���� ���α׷��� ����ǵ��� �մϴ�.
	int select;

	while (1)
	{
		cout << "< ��ǰ �з� ���� >" << endl;
		cout << "(1. �Ƿ�, 2. ����, 3. ������ǰ)" << endl;
		cout << "����:";
		cin >> select;

		system("cls");

		// ���� �Ŵ��� ��� �̱����������� ���۵Ǿ��� ������ �ν��Ͻ����� ȣ���ؼ� �׳� �Ѱ��ݴϴ�.
		switch (select)
		{
		case CLOTH:
			return  ClothManager::GetInstance();
			break;
		case FOOD:
			return FoodManager::GetInstance();
			break;
		case ELECTRONIC:
			return ElectronicManager::GetInstance();
			break;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			continue;
		}
		break;
	}
	
}

void MainManager::Run()
{
	// BaseManager�� ��� ��ӹ޾ұ� ������ �������� �����Ҽ� �ֽ��ϴ�.
	// ���� manager��� ������ ���� ��� �Ŵ����� ������ �ֽ��ϴ�.
	BaseManager* manager = nullptr;


	// �װ��� �̿��ؼ� �������� �����մϴ�.
	while (1)
	{
		
		int select = SelectMainMenu();
		system("cls");
		
		switch (select)
		{
		case STORE:
			manager = MajorSelect();
			manager->InseartItem();
			break;
		case RELEASE:
			manager = MajorSelect();
			manager->DeleteItem();
			
			break;
		case DISPLAY:
			manager = MajorSelect();
			manager->Display();
			_getch();
			system("cls");
			break;
		case SEARCH:
			manager = MajorSelect();
			manager->Search();
			_getch();
			system("cls");
			break;
		case MANAGEMENT:
			DateManagement();
			_getch();
			system("cls");
			break;
		case EXIT:
			return;
			break;
		default:
			cout << "�߸� �Է��߽��ϴ� �ٽ� �Է��ϼ��� " << endl;
		}
	}
}

void MainManager::DateManagement()
{
	// �Է��� ��������� ������ ������ ����ϴ� �Լ��Դϴ�.
	char Date[20];
	cout << "< ��� ���� >" << endl;
	cout << "���� ���� (YYMMDD) : ";
	cin >> Date;
	system("cls");
	// �� �Ŵ����� OverDateSearch�Լ��� �Է¹��� const char* �� �񱳸� ���� 
	// ����Ȳ�� ����մϴ�.
	ClothManager::GetInstance()->OverDateSearch(Date);
	FoodManager::GetInstance()->OverDateSearch(Date);
	ElectronicManager::GetInstance()->OverDateSearch(Date);
}