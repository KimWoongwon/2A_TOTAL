#include "MainManager.h"
#include "ClothManager.h"
#include "FoodManager.h"
#include "ElectronicManager.h"
#include "BaseManager.h"
#include "DataBaseManager.h"
#include "Global.h"
MainManager* MainManager::Instance = nullptr; // static 멤버 인스턴스의 초기화 
MainManager::MainManager() {} // 껍질뿐인 생성자
MainManager::~MainManager() {} // 껍질뿐인 소멸자

// 인스턴스 할당 함수
void MainManager::Create()
{
	// 메인매니저의 인스턴스가 이미 생성되지 않았다면 할당을 합니다.
	if (!Instance)
		Instance = new MainManager();
	// 그후에 각각의 Create함수를 호출해서 각 매니저들의 인스턴스를 할당하게끔 합니다.
	ClothManager::Create();
	FoodManager::Create();
	ElectronicManager::Create();
	DataBaseManager::Create();
}
void MainManager::Destroy()
{
	// 메인매니저의 인스턴스가 생성되어있다면 삭제를 하고 인스턴스값을 초기화합니다.
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
	// 또한 각 매니저의 Destroy함수를 호출해서 메인매니저가 사라질때 각 매니저들도 함께 사라지게끔 합니다.
	ClothManager::Destroy();
	FoodManager::Destroy();
	ElectronicManager::Destroy();
	DataBaseManager::Destroy();
}
MainManager* MainManager::GetInstance()
{
	// 싱글톤패턴의 인스턴스를 그저 넘겨주는 함수입니다.
	return Instance;
}
void MainManager::Initialaze()
{
	// 생성후에 이니셜라이즈 함수를 호출해서 각 매니저에 필요한 초기값을 셋팅합니다.
	ClothManager::GetInstance()->Initialaze();
	FoodManager::GetInstance()->Initialaze();
	ElectronicManager::GetInstance()->Initialaze();
	DataBaseManager::GetInstance()->Initialaze();
}

int MainManager::SelectMainMenu()
{
	// 메인메뉴를 출력하는 함수입니다.
	int select;

	while (1)
	{
		
		cout << "<물품관리 프로그램>" << endl;
		cout << "1. 입고" << endl;
		cout << "2. 출고" << endl;
		cout << "3. 재고 목록 출력" << endl;
		cout << "4. 재고 검색" << endl;
		cout << "5. 재고 관리" << endl;
		cout << "6. 프로그램 종료" << endl;
		cout << "선택:";
		cin >> select;
		rewind(stdin);
		// 예외처리
		if (select < STORE || select > EXIT)
		{
			cout << "잘못 입력했습니다." << endl;
			continue;
		}
		break;
	}

	return select;

}
BaseManager* MainManager::MajorSelect()
{
	// 각 매니저들은 모두 BaseManager를 상속받기 때문에 
	// 다형성을 통해 프로그램이 진행되도록 합니다.
	int select;

	while (1)
	{
		cout << "< 제품 분류 선택 >" << endl;
		cout << "(1. 의류, 2. 음식, 3. 가전제품)" << endl;
		cout << "선택:";
		cin >> select;

		system("cls");

		// 또한 매니저 모두 싱글톤패턴으로 제작되었기 때문에 인스턴스값을 호출해서 그냥 넘겨줍니다.
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
			cout << "잘못 입력했습니다." << endl;
			continue;
		}
		break;
	}
	
}

void MainManager::Run()
{
	// BaseManager를 모두 상속받았기 때문에 다형성을 구현할수 있습니다.
	// 따라서 manager라는 변수를 통해 모든 매니저를 담을수 있습니다.
	BaseManager* manager = nullptr;


	// 그것을 이용해서 다형성을 구현합니다.
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
			cout << "잘못 입력했습니다 다시 입력하세요 " << endl;
		}
	}
}

void MainManager::DateManagement()
{
	// 입력한 유통기한의 이전의 재고들을 출력하는 함수입니다.
	char Date[20];
	cout << "< 재고 관리 >" << endl;
	cout << "유통 기한 (YYMMDD) : ";
	cin >> Date;
	system("cls");
	// 각 매니저의 OverDateSearch함수는 입력받은 const char* 를 비교를 통해 
	// 재고상황을 출력합니다.
	ClothManager::GetInstance()->OverDateSearch(Date);
	FoodManager::GetInstance()->OverDateSearch(Date);
	ElectronicManager::GetInstance()->OverDateSearch(Date);
}