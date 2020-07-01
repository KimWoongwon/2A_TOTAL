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
	// ���θŴ����� �����ɽ� ���� �����ǵ��� ���θ޴������� ȣ��˴ϴ�.
	// �ٸ� �Ŵ����� �����ϰ� �ν��Ͻ��� �������� �ʾ������ �Ҵ��� ���� �����մϴ�.
	if (!Instance)
		Instance = new ClothManager();
}
void ClothManager::Destroy()
{
	// ���θŴ����� �����ɽ� ���� �����ǵ��� ���θŴ������� ȣ��˴ϴ�.
	// �ٸ� �Ŵ����� �����ϰ� �ν��Ͻ��� ���������� ������� �����մϴ�.
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
ClothManager* ClothManager::GetInstance()
{
	// ���θŴ������� ���õɶ� �������� ���� �ٸ� �Լ��� �����Ҽ� �ֵ��� �ν��Ͻ����� �Ѱ��ݴϴ�.
	return Instance;
}

// ��� ������ �԰��ϴ� �Լ��Դϴ�.
void ClothManager::InseartItem()
{
	char name[20];
	char date[20];
	int count = 0;
	
	// �޴� ���
	do
	{
		cout << "< �Ƿ� ��ǰ �԰� >" << endl;
		cout << "��ǰ�� : ";
		cin >> name;
		cout << "������� (YYMMDD) : ";
		cin >> date;
		// �Է��� ��������� �ش������� ��Ű���ִ��� �˻��մϴ�.
		// ���� ��������� �Է� ������ ���� �ʴ´ٸ� �ٽ� �Է��մϴ�.
		if (strlen(date) != strlen("000000"))
		{
			cout << "������� �Է� ����!" << endl;
			cout << "----------------------" << endl;
		}
		else
		{
			cout << "�԰� ���� : ";
			cin >> count;
		}
		
	} while (strlen(date) != strlen("000000"));
	

	// ���ο� ��� �����ؼ� 
	Product* temp = new Product(name, date, count);
	// �����ͺ��̽��� cloth ����Ʈ�� �����մϴ�.
	DataBaseManager::GetInstance()->Input(temp, CLOTH);
	cout << "�԰���..." << endl;
	Sleep(500);
	system("cls");
	
}
void ClothManager::DeleteItem()
{
	int select = 0;
	// �����޴� ���
	// ������ �ѹ��� �������
	// ������ ���� ������� ���մϴ�.
	do
	{
		cout << "< �Ƿ� ��ǰ ��� >" << endl;
		cout << "1. ��� ��� ���" << endl;
		cout << "2. ���� ���� ���" << endl;
		cout << "���� : ";
		cin >> select;
		// ����ó��
		if (select < 1 || select > 2)
			cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "-------------------------------" << endl;
	} while (select < 1 || select > 2);

	// �����ϱ� �޴��� ������ � ǰ���� �������� ���� ���Ҽ� �ֵ���
	// ��ü ǰ���� ����ؼ� �����ϰ� ���� ǰ���� �������� �� �� �ֵ��� �����߽��ϴ�.
	Display();

	// ������ ��ǰ�� �̸��� ��������� �Է��մϴ�.
	char tempname[20];
	cout << "������ ��ǰ�� : ";
	cin >> tempname;

	// ��������� �Է¹޴� ������ ��ǰ���� ������ �ٸ��ñ⿡ ���� �����
	// ��������� �ٸ��� ������ ���ϴ� ��ǰ�� ������ ���� �Է� �޽��ϴ�.
	char tempdate[20];
	do
	{
		cout << "��ǰ�� ������� (YYMMDD) : ";
		cin >> tempdate;
		if (strlen(tempdate) != strlen("000000"))
			cout << "������� �Է� ����!" << endl;
	} while (strlen(tempdate) != strlen("000000"));
	

	// �Է��� �̸��� ��������� ���� �����ͺ��̽����� �Ѱ��� �Ѱܹ޾� ���մϴ�.
	// �����ͺ��̽����� �Ѿ���� �����͸� �����ϴ� �ӽ� �����Դϴ�.
	Product* data = nullptr;

	// ���� ����� ������ �������� �ʰ� ��� ����Ѵٸ� 
	if (select == 1)
	{
		while (1)
		{
			
			data = DataBaseManager::GetInstance()->GetData(CLOTH);
			if (data != nullptr)
			{
				// �����͸� ã�Ƽ� �̸��� ��������� ���� �� �����մϴ�
				// ������ �Ű澲���ʰ� ��� ����ϱ� ������ üũ���� �ʽ��ϴ�.
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
		// ��� ��� �ϴ°��� �ƴ� ������ ���� ����ϱ� ������ ��� ����Ұ����� �Է¹޽��ϴ�.
		int rmcount = 0;
		cout << "������ ���� : ";
		cin >> rmcount;
		while (1)
		{
			// �����ͺ��̽����� � ����Ʈ���� �����͸� �������� �����մϴ�.
			data = DataBaseManager::GetInstance()->GetData(CLOTH);
			if (data != nullptr)
			{
				// �Ȱ��� �����͸� ã�Ƽ� �̸��� ��������� ������ changeCount�Լ��� �̿��� ������ �����մϴ�.
				if (!strcmp(data->GetName(), tempname) && !strcmp(data->GetDate(), tempdate))
				{
					data->changeCount(rmcount);
					// ���� ������ 0�̶�� ��ǰ�� ��� �������Ƿ� �ش� ��� ���� ������ �����մϴ�.
					if (data->GetCount() == 0)
						DataBaseManager::GetInstance()->Remove(data, CLOTH);
					break;
				}
			}
		}
	}
	// �������� �˻��� ���� �Ѱ��� �Ѱܹ޾ұ� ������ mData�� ��ġ�� �߰��� ��ġ�Ҽ� �ֽ��ϴ�.
	// ������ mData�� ��ġ�� �ʱⰪ���� �����մϴ�.
	DataBaseManager::GetInstance()->GetDataEnd();
	cout << "�����..." << endl;
	Sleep(500);
	system("cls");
}
// ��� ��ǰ�� �Ǵ� ����������� ã�� �Լ��Դϴ�.
void ClothManager::Search()
{
	// ���� �ش� ����Ʈ�� ī��Ʈ�� 0�̶�� ��� ���⶧���� �˻��� �ǹ̰� �����ϴ�.
	// ���� �ش��Լ��� �����մϴ�.
	if (DataBaseManager::GetInstance()->isEmpty(CLOTH))
	{
		cout << "�Ƿ� ��� ������ϴ�." << endl;
		return;
	}
		

	// ��ǰ������ �˻��Ұ����� ����������� �˻��� ������ �˻��մϴ�.
	int select = 0;
	do
	{
		cout << "<�Ƿ� ��� �˻� �޴�>" << endl;
		cout << "1. ��ǰ��" << endl;
		cout << "2. �������" << endl;
		cout << "���� : ";
		cin >> select;
		if (select < 1 || select > 2)
			cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "-------------------------------" << endl;
	} while (select < 1 || select > 2);


	// ��ǰ�� �Ǵ� ��������� �Է¹޽��ϴ�.
	char temp[20];
	if (select == 1)
	{
		cout << "��ǰ�� : ";
		cin >> temp;
		cout << "-------------------------------" << endl;
	}
	else if (select == 2)
	{
		do
		{
			cout << "��ǰ�� ������� (YY-MM-DD) : ";
			cin >> temp;
			if (strlen(temp) != strlen("000000"))
				cout << "������� �Է� ����!" << endl;
			cout << "-------------------------------" << endl;
		} while (strlen(temp) != strlen("000000"));
	}
		

	Product* tempproduct = nullptr;
	// ����Ʈ�� �����͸� ��� �˻������� ������츦 ���� �����Դϴ�.
	int count = 0;
	while (1)
	{
		// �����͸� �Ѱܹ޾� �˻��մϴ�.
		tempproduct = DataBaseManager::GetInstance()->GetData(CLOTH);
		
		// ���� �̸��� ��ǰ, �Ǵ� ���� ��������� ���� ��� ��� ����� �� �ְԲ� �����߽��ϴ�.
		if (tempproduct == nullptr) // �����Ͱ� nullptr�� �ɶ����� �� ����Ʈ�� ���� �����Ҷ����� ��� �˻��մϴ�.
			break;
		// ��ǰ������ �˻��߰� �Է��� �̸��� �Ѱܹ��� �������� �̸��� ���ٸ� ����մϴ�.
		if (select == 1 && !strcmp(tempproduct->GetName(), temp)) 
		{
			count++;
			cout << "��ǰ��	  : " << tempproduct->GetName() << endl;
			cout << "������� : " << tempproduct->GetDate() << endl;
			cout << "����     : " << tempproduct->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
		// ����������� �˻��߰� �Է��� ������Ѱ� �Ѱܹ��� �������� ��������� ���ٸ� ����մϴ�.
		else if (select == 2 && !strcmp(tempproduct->GetDate(), temp)) 
		{
			count++;
			cout << "��ǰ��	  : " << tempproduct->GetName() << endl;
			cout << "������� : " << tempproduct->GetDate() << endl;
			cout << "����     : " << tempproduct->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
		
	}
	// ���� ����Ʈ�� ��� �������� �Ѱ��� ������� �ʾҴٸ� ����Ʈ�� ã�� ��� �����Ƿ� ����ó���� �մϴ�.

	if (count <= 0)
	{
		cout << "ã���ô� �Ƿ� ��� �����ϴ�." << endl;
		cout << "-------------------------------" << endl;
	}

	// �������� �˻��� ���� �Ѱ��� �Ѱܹ޾ұ� ������ mData�� ��ġ�� �߰��� ��ġ�Ҽ� �ֽ��ϴ�.
	// ������ mData�� ��ġ�� �ʱⰪ���� �����մϴ�.
	DataBaseManager::GetInstance()->GetDataEnd();
	
}
// ������ ���ϰ� ���ų� ��� ����Ʈ�� ��������� ȣ���ϴ� �Լ��Դϴ�.
void ClothManager::Display()
{

	cout << "< ��ǰ ��� >" << endl;
	cout << "-------------------------------" << endl;
	// ���� ����Ʈ�� ����ִٸ� ����� ��� ���⶧���� �޼����� ����մϴ�.
	if (DataBaseManager::GetInstance()->isEmpty(CLOTH))
	{
		cout << "�Ƿ� ��� �����ϴ�." << endl;
		cout << "-------------------------------" << endl;
		return;
	}

	Product* temp = nullptr;
	while (1)
	{
		// �����͸� �Ѱܹ޾Ƽ� ��� ����մϴ�.
		temp = DataBaseManager::GetInstance()->GetData(CLOTH);
		// nullptr�̶�� ����Ʈ�� ���� �����ؼ� �Ѱܹ��� �����Ͱ� ���⶧���� �����մϴ�.
		if (temp == nullptr)
			break;
		else if (temp != nullptr)
		{
			// ����Ʈ�� �����͸� ����մϴ�.
			cout << "��ǰ��	  : " << temp->GetName() << endl;
			cout << "������� : " << temp->GetDate() << endl;
			cout << "����     : " << temp->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
	}
	// �������� �˻��� ���� �Ѱ��� �Ѱܹ޾ұ� ������ mData�� ��ġ�� �߰��� ��ġ�Ҽ� �ֽ��ϴ�.
	// ������ mData�� ��ġ�� �ʱⰪ���� �����մϴ�.
	DataBaseManager::GetInstance()->GetDataEnd();
	
}

// ������ ������ �޴��� ���ؼ� ȣ��Ǵ� �Լ��Դϴ�.
void ClothManager::OverDateSearch(const char* p_str)
{
	// ��µ� ��� �ִ��� �˻��ϱ� ���� �����Դϴ�.
	int count = 0;
	int pDate = atoi(p_str); // �Է¹��� ��������� ���ϱ� ���� int������ ��ȯ�մϴ�.

	Product* temp = nullptr;
	int ItemDate = 0; // ����Ʈ���� ������ �������� ��������� int������ ��ȯ�Ͽ� ������ �����Դϴ�.

	cout << "< " << pDate << " ���� �Ƿ� ��� >" << endl;
	cout << "-------------------------------" << endl;
	while (1)
	{
		// �����͸� �ϳ��� �����ͼ� �˻��մϴ�.
		temp = DataBaseManager::GetInstance()->GetData(CLOTH);
		if (temp == nullptr)
			break;

		// ��������� ���ϱ� ������ int������ ��ȯ�մϴ�.
		ItemDate = atoi(temp->GetDate());
		// �Է��� ������Ѻ��� �������� ��������� �۴ٸ� 
		// ��������� ���� ����̱� ������ �ش� ��� ����մϴ�.
		if (ItemDate <= pDate)
		{
			// ����ϰ� �ȴٸ� ī��Ʈ ������ ������ŵ�ϴ�.
			count++;
			cout << "��ǰ��	  : " << temp->GetName() << endl;
			cout << "������� : " << temp->GetDate() << endl;
			cout << "����     : " << temp->GetCount() << endl;
			cout << "-------------------------------" << endl;
		}
	}
	// ���� �������� �������ͼ��� ī��Ʈ�� 0�̶�� �Է��� ������� ������ ��ǰ�� ���ٰ� �Ǵ��Ͽ�
	// �޼����� ����մϴ�.
	if (count <= 0)
	{
		cout << "������� " << pDate << " ������ ��ǰ�� �����ϴ�.";
		cout << "-------------------------------" << endl;
	}
	
	// �������� ����� ���� �Ѱ��� �Ѱܹ޾ұ� ������ mData�� ��ġ�� ���� ��ġ�ϰ� �ִٰ� �Ǵ��մϴ�..
	// ������ mData�� ��ġ�� �ʱⰪ���� �����մϴ�.
	DataBaseManager::GetInstance()->GetDataEnd();
}