#include "CManager.h"
#include "HumanFactory.h"
#include "OrcFactory.h"
#include "ElfFactory.h"
#include "ItemStore.h"
CManager::CManager()
{
	memset(mUserLst, 0, sizeof(mUserLst));
	mUserCount = 0;
	ItemStore::Create();
}

CManager::~CManager()
{
	for (int i = 0; i < mUserCount; i++)
	{
		if (mUserLst[i] != nullptr)
		{
			delete mUserLst[i];
			mUserLst[i] = nullptr;
		}
	}
	ItemStore::Destroy();
}

void CManager::Run()
{
	while (1)
	{
		bool endflag = false;		

		int select = MainMenu();
		system("cls");
		int select2 = 0;
		switch (select)
		{
		case JOIN:
			Join();
			break;
		case LOGIN:
			if (Login())
			{
				while (mNowUser->GetLoginState())
				{
					select = LoginMenu();
					system("cls");
					char tempname[20] = {};
					int BuyOrSellIdx = 0;
					Item* SelledItem = nullptr;
					Character* temp = nullptr;
					CharacterFactory* FactorySelect = nullptr;
					switch (select)
					{
					case CREATE:
						select2 = CharMenu();
						switch (select2)
						{
						case HUM:
							FactorySelect = new HumanFactory();
							break;
						case ORC:
							FactorySelect = new OrcFactory();
							break;
						case ELF:
							FactorySelect = new ElfFactory();
							break;
						}
						mNowUser->InsertCharacter(FactorySelect->SettingCharacter());
						delete FactorySelect;
						FactorySelect = nullptr;
						system("cls");
						break;
					case DESTROY:
						mNowUser->DisplayCharacterInfo(false);
						cout << "������ ĳ���� �̸� : ";
						cin >> tempname;
						mNowUser->RemoveCharacter(tempname);
						_getch();
						system("cls");
						break;
					case DISPLAY:
						mNowUser->DisplayCharacterInfo(true);
						_getch();
						system("cls");
						break;
					case ITEMBUY:
						mNowUser->DisplayCharacterInfo(false);
						
						cout << "�������� ������ ĳ���� �̸� : ";
						cin >> tempname;

						for (int i = 0; i < mNowUser->GetCount(); i++)
						{
							if (!strcmp(mNowUser->GetChar(i)->GetName(), tempname))
							{
								BuyOrSellIdx = i;
								break;
							}
						}
						temp = mNowUser->GetChar(BuyOrSellIdx);
						ItemStore::GetInstance()->Sell(&temp);
						break;
					case ITEMSELL:
						mNowUser->DisplayCharacterInfo(false);
						cout << "�������� �Ǹ��� ĳ���� �̸� : ";
						cin >> tempname;

						for (int i = 0; i < mNowUser->GetCount(); i++)
						{
							if (!strcmp(mNowUser->GetChar(i)->GetName(), tempname))
							{
								BuyOrSellIdx = i;
								break;
							}
						}
						SelledItem = mNowUser->GetChar(BuyOrSellIdx)->SellItem();
						ItemStore::GetInstance()->Buy(&SelledItem);
						break;
					case ITEMCHANGE:
						mNowUser->DisplayCharacterInfo(false);
						cout << "������ ��ü�� ĳ���� �̸� : " << endl;
						cin >> tempname;
						for (int i = 0; i < mNowUser->GetCount(); i++)
						{
							if (!strcmp(mNowUser->GetChar(i)->GetName(), tempname))
							{
								BuyOrSellIdx = i;
								break;
							}
						}
						mNowUser->GetChar(BuyOrSellIdx)->ChangeItem();
						break;
					case STOREINFO:
						ItemStore::GetInstance()->DisplayShop();
						break;
					case LOGOUT:
						mNowUser->SetLogout();
						break;
					case DROP:
						Drop();
						break;
					}
				}
			}			
			break;
		case EXIT:
			endflag = true;
			break;
		default:
			cout << "�߸��Է��߽��ϴ�" << endl;
			_getch();
			system("cls");
			continue;
		}

		if (endflag)
		{
			break;
		}
	}

	
}

bool CManager::Join()
{
	char id[10];
	char pw[10];

	cout << "ID:";
	cin >> id;

	bool flag = false;
	for (int i = 0; i < mUserCount; i++)
	{
		if (strcmp(mUserLst[i]->GetId(), id) == 0)
		{
			flag = true;
			break;
		}
	}

	if (flag)
	{
		cout << "�̹� �����ϴ� ���̵��Դϴ�" << endl;
		_getch();
		system("cls");
		return false;
	}

	cout << "PW:";
	cin >> pw;

	mUserLst[mUserCount++] = new CUser(id, pw);

	cout << "ȸ������ �Ϸ�" << endl;
	_getch();
	system("cls");
	return true;

}

bool CManager::Login()
{
	char id[10];
	char pw[10];


	cout << "ID:";
	cin >> id;

	CUser* ptr = nullptr;

	for (int i = 0; i < mUserCount; i++)
	{
		if (strcmp(mUserLst[i]->GetId(), id) == 0)
		{
			ptr = mUserLst[i];
			break;
		}
	}

	if (ptr==nullptr)
	{
		cout << "���� ���̵��Դϴ�" << endl;
		_getch();
		system("cls");
		return false;
	}

	cout << "PW:";
	cin >> pw;

	if (strcmp(ptr->GetPw(), pw) == 0)
	{		
		mNowUser = ptr;
		mNowUser->SetLogin();		
	}
	else
	{
		cout << "�н����尡 Ʋ�Ƚ��ϴ�" << endl;
		_getch();
		system("cls");
		return false;
	}
	system("cls");
	return true;

}

MAIN_MENU CManager::MainMenu()
{
	MAIN_MENU select;	

	while (1)
	{
		cout << "<�޴�>" << endl;
		cout << "1.ȸ������" << endl;
		cout << "2.�α���" << endl;
		cout << "3.����" << endl;
		cout << "����:";


		cin >> select;

		if (select < JOIN || select>3)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			continue;
		}
		break;
	}

	return select;
}

LOGIN_MENU CManager::LoginMenu()
{
	LOGIN_MENU select;

	while (1)
	{		
		cout << "<�޴�>" << endl;
		cout << "1.ĳ���ͻ���" << endl;
		cout << "2.ĳ���ͻ���" << endl;
		cout << "3.ĳ�������" << endl;
		cout << "4.�����۱���" << endl;
		cout << "5.�������Ǹ�" << endl;
		cout << "6.ĳ�������ü" << endl;
		cout << "7.�����������" << endl;
		cout << "8.�α׾ƿ�" << endl;
		cout << "0.ȸ��Ż��" << endl;	
		cout << "����:";

		
		cin >> select;

		if (select<0 || select>8)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			continue;
		}
		break;
	}

	return select;
	
}

CHAR_MENU CManager::CharMenu()
{
	CHAR_MENU select;

	while (1)
	{
		cout << "<�޴�>" << endl;
		cout << "1.�ΰ�" << endl;
		cout << "2.��ũ" << endl;
		cout << "3.����" << endl;
		cout << "����:";

		cin >> select;

		if (select < 1 || select>3)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			continue;
		}
		break;
	}
	cout << "------------------------" << endl;
	return select;
}

void CManager::Logout()
{
	mNowUser->SetLogout();
}

void CManager::Drop()
{
	for (int i = 0; i < mUserCount; i++)
	{
		if (mUserLst[i] == mNowUser)
		{
			delete mUserLst[i];
			for (int j = i; j < mUserCount - 1; j++)
			{
				mUserLst[j] = mUserLst[j + 1];
			}
			mUserLst[mUserCount - 1] = nullptr;
			break;
		}
	}

	mUserCount--;

}