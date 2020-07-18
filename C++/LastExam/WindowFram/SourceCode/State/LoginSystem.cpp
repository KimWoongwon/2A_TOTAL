#include "LoginSystem.h"
#include "../Windows/WindowFrame.h"


CLoginSystem* CLoginSystem::mPthis = nullptr;
CLoginSystem::CLoginSystem()
{
	ItemDataBase::Create();
	GetInst(ItemDataBase)->Initialize();

	mTitleState = new CTitleState(this);
	mSignupState = new CSignupState(this);
	mUserMenuState = new CUserMenuState(this);
	mStoreState = new CStoreState(this);
	mCreateState = new CCreateState(this);
	mDeleteState = new CDeleteState(this);
	mBuyState = new CBuyState(this);
	mSellState = new CSellState(this);
	mShowState = new CShowState(this);

	mNowState = nullptr;
	mNowUser = nullptr;
	mNowCharacter = nullptr;
}

CLoginSystem::~CLoginSystem()
{	
	ItemDataBase::Destroy();
	delete mTitleState;
	delete mSignupState;
	delete mUserMenuState;
	delete mStoreState;
	delete mCreateState;
	delete mDeleteState;
	delete mBuyState;
	delete mSellState;
	delete mShowState;

}

CLoginSystem* CLoginSystem::Create()
{
	if (!mPthis)
	{
		mPthis = new CLoginSystem();
	}
	CUserManager::Create();
	GetInst(CUserManager)->Initialize();
	return mPthis;
}

CLoginSystem* CLoginSystem::GetInstance()
{
	return mPthis;
}

void CLoginSystem::Destroy()
{	
	CUserManager::Destroy();
	if (mPthis)
	{
		delete mPthis;
		mPthis = NULL;
	}
}

void CLoginSystem::InitializeProcess()
{
	SetNowState(mTitleState);
}
void CLoginSystem::ButtonProcess(WPARAM _wParam)
{
	mNowState->ButtonProcess(_wParam);
}

CGameState* CLoginSystem::GetState(STATE state)
{
	switch (state)
	{
	case STATE::TITLE_STATE:
		return mTitleState;
	case STATE::SIGNUP_STATE:
		return mSignupState;
	case STATE::MENU_STATE:
		return mUserMenuState;
	case STATE::STORE_STATE:
		return mStoreState;
	case STATE::CREATE_STATE:
		return mCreateState;
	case STATE::DELETE_STATE:
		return mDeleteState;
	case STATE::BUY_STATE:
		return mBuyState;
	case STATE::SELL_STATE:
		return mSellState;
	case STATE::SHOW_STATE:
		return mShowState;
	}

}


void CLoginSystem::SetNowState(CGameState* _state)
{
	
	mNowState = _state;
	mNowState->InitializeProcess();
}

int CLoginSystem::Login(const char* p_ID, const char* p_PW)
{
	char m_id[20];
	char m_pw[20];

	strcpy_s(m_id, sizeof(m_id), p_ID);
	strcpy_s(m_pw, sizeof(m_pw), p_PW);

	CUser* temp = nullptr;
	int count = GetInst(CUserManager)->GetCount();
	for (int i = 0; i < count; i++)
	{
		if (GetInst(CUserManager)->GetData(&temp))
		{
			if (!strcmp(temp->GetId(), m_id))
			{
				break;
			}
		}
	}
	GetInst(CUserManager)->GetDataEnd();
	if (temp == nullptr)
		return -1;

	if (strcmp(temp->GetPw(), m_pw))
		return 0;
	else
	{
		mNowUser = temp;
		mNowUser->SetLogin();
		GetInst(CWindowFrame)->RemoveAllData(ID_LIST1);
		Character* temp = nullptr;
		for (int i = 0; i < mNowUser->GetCount(); i++)
		{
			if (mNowUser->GetCharList()->GetData(&temp))
			{
				if (temp == nullptr)
					break;

				GetInst(CWindowFrame)->InsertCharData(temp);
			}
		}
		mNowUser->GetCharList()->GetDataEnd();
		return 1;
	}
	
}

bool CLoginSystem::Logout()
{
	mNowUser->SetLogout();
	return true;
}

bool CLoginSystem::CharacterSetting(char* _str)
{
	mNowCharacter = mNowUser->GetChar(_str);
	if (mNowCharacter == nullptr)
		return false;
	return true;
}
Character* CLoginSystem::GetNowCharacter()
{
	return mNowCharacter;
}

int CLoginSystem::GetUserMoney()
{
	return mNowUser->GetMoney();
}

void CLoginSystem::SetUserMoney(int _money)
{
	int tempMoney = mNowUser->GetMoney() + _money;
	mNowUser->SetMoney(tempMoney);
}

bool CLoginSystem::Signup(const char* p_ID, const char* p_PW)
{
	char m_id[20];
	char m_pw[20];

	strcpy_s(m_id, sizeof(m_id), p_ID);

	bool flag = false;
	CUser* temp = nullptr;
	int count = GetInst(CUserManager)->GetCount();
	for (int i = 0; i < count; i++)
	{
		if (GetInst(CUserManager)->GetData(&temp))
		{
			if (!strcmp(temp->GetId(), m_id))
			{
				flag = true;
				break;
			}
		}
	}
	GetInst(CUserManager)->GetDataEnd();

	if (flag)
	{
		cout << "이미 존재하는 아이디입니다" << endl;
		return false;
	}

	strcpy_s(m_pw, sizeof(m_pw), p_PW);
	GetInst(CUserManager)->Input(new CUser(m_id, m_pw));
	
	return true;
}

bool CLoginSystem::CreateCharacter(const char* pName, CharacterFactory* factory, CLASS cls)
{
	int count = mNowUser->GetCharList()->GetCount();
	Character* ptr = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (mNowUser->GetCharList()->GetData(&ptr))
		{
			if (!strcmp(ptr->GetName(), pName))
			{
				return false;
			}
		}
	}
	mNowUser->GetCharList()->GetDataEnd();
	Character* temp = factory->SettingCharacter(pName, cls);
	mNowUser->InsertCharacter(temp);
	GetInst(CWindowFrame)->InsertCharData(temp);
	GetInst(CWindowFrame)->InsertCharItemData(temp);
	return true;
}
bool CLoginSystem::RemoveCharacter(char* _str)
{
	bool result = false;
	result = mNowUser->RemoveCharacter(_str);

	return result;
}

void CLoginSystem::ShowAllCharacter()
{
	int count = mNowUser->GetCharList()->GetCount();
	Character* ptr = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (mNowUser->GetCharList()->GetData(&ptr))
		{
			GetInst(CWindowFrame)->InsertCharData(ptr);
		}
	}
	mNowUser->GetCharList()->GetDataEnd();
}

bool CLoginSystem::SellItemToStore(char* _str)
{
	if (mNowCharacter == nullptr)
		return false;

	if (!strcmp(mNowCharacter->GetWeapon()->GetName(), _str))
		return false;
	if (!strcmp(mNowCharacter->GetArmor()->GetName(), _str))
		return false;

	
	Item* temp = mNowCharacter->SellItem(_str);
	SetUserMoney(temp->GetPrice());
	GetInst(ItemDataBase)->Input(temp);
	return true;
	
}

bool CLoginSystem::BuyItemFromStore(char* _str)
{
	int count = GetInst(ItemDataBase)->GetCount();
	Item* temp = nullptr;
	Item* ptr = nullptr;
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (GetInst(ItemDataBase)->GetData(&temp))
		{
			if (!strcmp(temp->GetName(), _str))
			{
				if (temp->GetTypeCode() == ITEMTYPE::WEAPONE)
					ptr = new Weapon(temp->GetName(), temp->GetStatus(), temp->GetPrice(), temp->GetClassCode());
				else if(temp->GetTypeCode() == ITEMTYPE::ARMOR)
					ptr = new Armor(temp->GetName(), temp->GetStatus(), temp->GetPrice(), temp->GetClassCode());
				flag = true;
				break;
			}
		}
	}
	GetInst(ItemDataBase)->GetDataEnd();
	if (!flag)
		return false;

	//delete temp;
	SetUserMoney(-ptr->GetPrice());
	mNowCharacter->BuyItem(ptr);
	return true;
}

int CLoginSystem::ChangeItem(char* _str)
{
	if (!strcmp(mNowCharacter->GetWeapon()->GetName(), _str))
		return -1;
	else if (!strcmp(mNowCharacter->GetArmor()->GetName(), _str))
		return -2;

	int count = mNowCharacter->GetInventory()->GetCount();
	Item* temp = nullptr;

	bool flag = false;

	for (int i = 0; i < count; i++)
	{
		if (mNowCharacter->GetInventory()->GetData(&temp))
		{
			if (!strcmp(temp->GetName(), _str))
			{
				flag = true;
				break;
			}
		}
	}
	mNowCharacter->GetInventory()->GetDataEnd();

	Item* item = nullptr;
	if (flag)
	{
		if (temp->GetTypeCode() == ITEMTYPE::WEAPONE)
		{
			mNowCharacter->GetInventory()->Input(mNowCharacter->GetWeapon());
			mNowCharacter->OffItem(mNowCharacter->GetWeapon());
			item = new Weapon(*dynamic_cast<Weapon*>(temp));
		}
		else if (temp->GetTypeCode() == ITEMTYPE::ARMOR)
		{
			mNowCharacter->GetInventory()->Input(mNowCharacter->GetArmor());
			mNowCharacter->OffItem(mNowCharacter->GetArmor());
			item = new Armor(*dynamic_cast<Armor*>(temp));
		}
		mNowCharacter->GetInventory()->Delete(temp);
		mNowCharacter->OnItem(item);
		return 1;
	}


}
bool CLoginSystem::OnItem(char* _str)
{
	int count = mNowCharacter->GetInventory()->GetCount();
	Item* temp = nullptr;
	Item* Insert = nullptr;
	bool result = false;

	for (int i = 0; i < count; i++)
	{
		if (mNowCharacter->GetInventory()->GetData(&temp))
		{
			if (!strcmp(temp->GetName(), _str))
			{
				if (temp->GetTypeCode() == ITEMTYPE::WEAPONE)
					Insert = new Weapon(*dynamic_cast<Weapon*>(temp));
				if (temp->GetTypeCode() == ITEMTYPE::ARMOR)
					Insert = new Armor(*dynamic_cast<Armor*>(temp));
				result = mNowCharacter->OnItem(Insert);
				break;
			}
		}
	}
	mNowCharacter->GetInventory()->Delete(temp);
	mNowCharacter->GetInventory()->GetDataEnd();
	return result;
}
int CLoginSystem::OffItem(char* _str)
{
	if (mNowCharacter->GetWeapon() == nullptr)
		return -1;
	if (mNowCharacter->GetArmor() == nullptr)
		return -2;


	if (!strcmp(mNowCharacter->GetWeapon()->GetName(), _str))
	{
		mNowCharacter->GetInventory()->Input(mNowCharacter->GetWeapon());
		mNowCharacter->OffItem(mNowCharacter->GetWeapon());
		return (int)ITEMTYPE::WEAPONE;
	}

	if (!strcmp(mNowCharacter->GetArmor()->GetName(), _str))
	{
		mNowCharacter->GetInventory()->Input(mNowCharacter->GetArmor());
		mNowCharacter->OffItem(mNowCharacter->GetArmor());
		return (int)ITEMTYPE::ARMOR;
	}

	return 0;
}