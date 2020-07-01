#include "ClothManager.h"
#include "DataBaseManager.h"
#include "Global.h"
#include "Product.h"
ClothManager* ClothManager::Instance = nullptr;
ClothManager::ClothManager() {}
ClothManager::~ClothManager() {}
void ClothManager::Initialaze() {}

void ClothManager::Create()
{
	// 메인매니저가 생성될시 같이 생성되도록 메인메니저에서 호출됩니다.
	// 다른 매니저와 동일하게 인스턴스가 생성되지 않았을경우 할당을 통해 생성합니다.
	if (!Instance)
		Instance = new ClothManager();
}
void ClothManager::Destroy()
{
	// 메인매니저가 삭제될시 같이 삭제되도록 메인매니저에서 호출됩니다.
	// 다른 매니저와 동일하게 인스턴스가 생성된적이 있을경우 삭제합니다.
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
ClothManager* ClothManager::GetInstance()
{
	// 메인매니저에서 선택될때 다형성을 통해 다른 함수를 접근할수 있도록 인스턴스값을 넘겨줍니다.
	return Instance;
}

// 재고를 생성해 입고하는 함수입니다.
void ClothManager::InseartItem()
{
	char name[20];
	char date[20];
	int count = 0;
	
	// 메뉴 출력
	do
	{
		cout << "< 의류 물품 입고 >" << endl;
		cout << "물품명 : ";
		cin >> name;
		cout << "유통기한 (YYMMDD) : ";
		cin >> date;
		// 입력한 유통기한이 해당형식을 지키고있는지 검사합니다.
		// 만약 유통기한의 입력 서식이 맞지 않는다면 다시 입력합니다.
		if (strlen(date) != strlen("000000"))
		{
			cout << "유통기한 입력 오류!" << endl;
			cout << "----------------------" << endl;
		}
		else
		{
			cout << "입고 갯수 : ";
			cin >> count;
		}
		
	} while (strlen(date) != strlen("000000"));
	

	// 새로운 재고를 생성해서 
	Product* temp = new Product(name, date, count);
	// 데이터베이스에 cloth 리스트에 저장합니다.
	DataBaseManager::GetInstance()->Input(temp, CLOTH);
	cout << "입고중..." << endl;
	Sleep(500);
	system("cls");
	
}
void ClothManager::DeleteItem()
{
	int select = 0;
	// 삭제메뉴 출력
	// 모든재고를 한번에 출력할지
	// 갯수를 정해 출력할지 정합니다.
	do
	{
		cout << "< 의류 물품 출고 >" << endl;
		cout << "1. 재고 모두 출고" << endl;
		cout << "2. 갯수 지정 출고" << endl;
		cout << "선택 : ";
		cin >> select;
		// 예외처리
		if (select < 1 || select > 2)
			cout << "잘못된 입력입니다." << endl;
		cout << "-------------------------------" << endl;
	} while (select < 1 || select > 2);

	// 삭제하기 메뉴에 들어갔을때 어떤 품목을 삭제할지 쉽게 정할수 있도록
	// 전체 품목을 출력해서 삭제하고 싶은 품목의 상세정보를 알 수 있도록 설계했습니다.
	Display();

	// 삭제할 물품의 이름과 유통기한을 입력합니다.
	char tempname[20];
	cout << "삭제할 물품명 : ";
	cin >> tempname;

	// 유통기한을 입력받는 이유는 상품명이 같지만 다른시기에 들어온 재고라면
	// 유통기한이 다르기 때문에 원하는 물품의 삭제를 위해 입력 받습니다.
	char tempdate[20];
	do
	{
		cout << "물품의 유통기한 (YYMMDD) : ";
		cin >> tempdate;
		if (strlen(tempdate) != strlen("000000"))
			cout << "유통기한 입력 오류!" << endl;
	} while (strlen(tempdate) != strlen("000000"));
	

	// 입력한 이름과 유통기한을 통해 데이터베이스에서 한개씩 넘겨받아 비교합니다.
	// 데이터베이스에서 넘어오는 데이터를 저장하는 임시 변수입니다.
	Product* data = nullptr;

	// 만약 재고의 수량을 설정하지 않고 모두 출고한다면 
	if (select == 1)
	{
		while (1)
		{
			
			data = DataBaseManager::GetInstance()->GetData(CLOTH);
			if (data != nullptr)
			{
				// 데이터를 찾아서 이름과 유통기한을 비교한 후 삭제합니다
				// 갯수는 신경쓰지않고 모두 출고하기 때문에 체크하지 않습니다.
				if (!strcmp(data->GetName(), tempname) && !strcmp(data->GetDate(), tempdate))
				{
					
					DataBaseManager::GetInstance()->Remove(data, CLOTH);
					break;
				}
			}
			
		}
	}
	else if (select == 2)
	{
		// 모두 출고 하는것이 아닌 갯수를 정해 출고하기 때문에 몇개를 출고할것인지 입력받습니다.
		int rmcount = 0;
		cout << "삭제할 갯수 : ";
		cin >> rmcount;
		while (1)
		{
			// 데이터베이스에서 어떤 리스트에서 데이터를 꺼내올지 결정합니다.
			data = DataBaseManager::GetInstance()->GetData(CLOTH);
			if (data != nullptr)
			{
				// 똑같이 데이터를 찾아서 이름과 유통기한을 비교한후 changeCount함수를 이용해 갯수를 수정합니다.
				if (!strcmp(data->GetName(), tempname) && !strcmp(data->GetDate(), tempdate))
				{
					data->changeCount(rmcount);
					// 만약 갯수가 0이라면 물품이 모두 출고됬으므로 해당 재고에 대한 정보를 삭제합니다.
					if (data->GetCount() == 0)
						DataBaseManager::GetInstance()->Remove(data, CLOTH);
					break;
				}
			}
		}
	}
	// 데이터의 검색을 위해 한개씩 넘겨받았기 때문에 mData의 위치가 중간에 위치할수 있습니다.
	// 때문에 mData의 위치를 초기값으로 설정합니다.
	DataBaseManager::GetInstance()->GetDataEnd();
	cout << "출고중..." << endl;
	Sleep(500);
	system("cls");
}
// 재고를 물품명 또는 유통기한으로 찾는 함수입니다.
void ClothManager::Search()
{
	// 만약 해당 리스트의 카운트가 0이라면 재고가 없기때문에 검색의 의미가 없습니다.
	// 따라서 해당함수를 종료합니다.
	if (DataBaseManager::GetInstance()->isEmpty(CLOTH))
	{
		cout << "의류 재고가 비었습니다." << endl;
		return;
	}
		

	// 물품명으로 검색할것인지 유통기한으로 검색할 것인지 검사합니다.
	int select = 0;
	do
	{
		cout << "<의류 재고 검색 메뉴>" << endl;
		cout << "1. 물품명" << endl;
		cout << "2. 유통기한" << endl;
		cout << "선택 : ";
		cin >> select;
		if (select < 1 || select > 2)
			cout << "잘못된 입력입니다." << endl;
		cout << "-------------------------------" << endl;
	} while (select < 1 || select > 2);


	// 물품명 또는 유통기한을 입력받습니다.
	char temp[20];
	if (select == 1)
	{
		cout << "물품명 : ";
		cin >> temp;
		cout << "-------------------------------" << endl;
	}
	else if (select == 2)
	{
		do
		{
			cout << "물품의 유통기한 (YY-MM-DD) : ";
			cin >> temp;
			if (strlen(temp) != strlen("000000"))
				cout << "유통기한 입력 오류!" << endl;
			cout << "-------------------------------" << endl;
		} while (strlen(temp) != strlen("000000"));
	}
		

	Product* tempproduct = nullptr;
	// 리스트의 데이터를 모두 검사했지만 없을경우를 위한 변수입니다.
	int count = 0;
	while (1)
	{
		// 데이터를 넘겨받아 검사합니다.
		tempproduct = DataBaseManager::GetInstance()->GetData(CLOTH);
		
		// 같은 이름의 상품, 또는 같은 유통기한을 가진 재고를 모두 출력할 수 있게끔 구현했습니다.
		if (tempproduct == nullptr) // 데이터가 nullptr이 될때까지 즉 리스트의 끝에 도달할때까지 계속 검사합니다.
			break;
		// 물품명으로 검색했고 입력한 이름과 넘겨받은 데이터의 이름이 같다면 출력합니다.
		if (select == 1 && !strcmp(tempproduct->GetName(), temp)) 
		{
			count++;
			cout << "물품명	  : " << tempproduct->GetName() << endl;
			cout << "유통기한 : " << tempproduct->GetDate() << endl;
			cout << "갯수     : " << tempproduct->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
		// 유통기한으로 검색했고 입력한 유통기한과 넘겨받은 데이터의 유통기한이 같다면 출력합니다.
		else if (select == 2 && !strcmp(tempproduct->GetDate(), temp)) 
		{
			count++;
			cout << "물품명	  : " << tempproduct->GetName() << endl;
			cout << "유통기한 : " << tempproduct->GetDate() << endl;
			cout << "갯수     : " << tempproduct->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
		
	}
	// 만약 리스트를 모두 돌고나서도 한개도 출력하지 않았다면 리스트에 찾는 재고가 없으므로 예외처리를 합니다.

	if (count <= 0)
	{
		cout << "찾으시는 의류 재고가 없습니다." << endl;
		cout << "-------------------------------" << endl;
	}

	// 데이터의 검색을 위해 한개씩 넘겨받았기 때문에 mData의 위치가 중간에 위치할수 있습니다.
	// 때문에 mData의 위치를 초기값으로 설정합니다.
	DataBaseManager::GetInstance()->GetDataEnd();
	
}
// 삭제를 편하게 돕거나 재고 리스트를 보고싶을떄 호출하는 함수입니다.
void ClothManager::Display()
{

	cout << "< 물품 목록 >" << endl;
	cout << "-------------------------------" << endl;
	// 만약 리스트가 비어있다면 출력할 재고가 없기때문에 메세지를 출력합니다.
	if (DataBaseManager::GetInstance()->isEmpty(CLOTH))
	{
		cout << "의류 재고가 없습니다." << endl;
		cout << "-------------------------------" << endl;
		return;
	}

	Product* temp = nullptr;
	while (1)
	{
		// 데이터를 넘겨받아서 모두 출력합니다.
		temp = DataBaseManager::GetInstance()->GetData(CLOTH);
		// nullptr이라면 리스트의 끝에 도달해서 넘겨받은 데이터가 없기때문에 종료합니다.
		if (temp == nullptr)
			break;
		else if (temp != nullptr)
		{
			// 리스트의 데이터를 출력합니다.
			cout << "물품명	  : " << temp->GetName() << endl;
			cout << "유통기한 : " << temp->GetDate() << endl;
			cout << "갯수     : " << temp->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
	}
	// 데이터의 검색을 위해 한개씩 넘겨받았기 때문에 mData의 위치가 중간에 위치할수 있습니다.
	// 때문에 mData의 위치를 초기값으로 설정합니다.
	DataBaseManager::GetInstance()->GetDataEnd();
	
}

// 메인의 재고관리 메뉴를 통해서 호출되는 함수입니다.
void ClothManager::OverDateSearch(const char* p_str)
{
	// 출력된 재고가 있는지 검사하기 위한 변수입니다.
	int count = 0;
	int pDate = atoi(p_str); // 입력받은 유통기한을 비교하기 쉽게 int형으로 변환합니다.

	Product* temp = nullptr;
	int ItemDate = 0; // 리스트에서 가져온 데이터의 유통기한을 int형으로 변환하여 저장할 변수입니다.

	cout << "< " << pDate << " 이전 의류 목록 >" << endl;
	cout << "-------------------------------" << endl;
	while (1)
	{
		// 데이터를 하나씩 가져와서 검사합니다.
		temp = DataBaseManager::GetInstance()->GetData(CLOTH);
		if (temp == nullptr)
			break;

		// 유통기한을 비교하기 쉽도록 int형으로 변환합니다.
		ItemDate = atoi(temp->GetDate());
		// 입력한 유통기한보다 데이터의 유통기한이 작다면 
		// 유통기한이 지난 재고이기 떄문에 해당 재고를 출력합니다.
		if (ItemDate <= pDate)
		{
			// 출력하게 된다면 카운트 변수를 증가시킵니다.
			count++;
			cout << "물품명	  : " << temp->GetName() << endl;
			cout << "유통기한 : " << temp->GetDate() << endl;
			cout << "갯수     : " << temp->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
	}
	// 만약 루프문을 빠져나와서도 카운트가 0이라면 입력한 유통기한 이전의 상품이 없다고 판단하여
	// 메세지를 출력합니다.
	if (count <= 0)
	{
		cout << "유통기한 " << pDate << " 이전의 제품은 없습니다.";
		cout << "-------------------------------" << endl;
	}
	
	// 데이터의 출력을 위해 한개씩 넘겨받았기 때문에 mData의 위치가 끝에 위치하고 있다고 판단합니다..
	// 때문에 mData의 위치를 초기값으로 설정합니다.
	DataBaseManager::GetInstance()->GetDataEnd();
}