#include "ItemStore.h"
#include "Character.h"
ItemStore* ItemStore::mPthis = nullptr;
ItemStore* ItemStore::Create()		
{									
	if (mPthis == NULL)					
	{									
		mPthis = new ItemStore();			
	}
	ItemDataBase::Create();
	ItemDataBase::GetInstance()->Initialize();
	return mPthis;						
}                                   
ItemStore* ItemStore::GetInstance()	
{                                   
	return mPthis;						
}									
void ItemStore::Destroy()			
{						
	ItemDataBase::Destroy();
	if (mPthis) 
		delete mPthis;			
}

ItemStore::ItemStore()
{

}
ItemStore::~ItemStore()
{

}



void ItemStore::ShowShop(int code, int count)
{
	
	for (int i = 0; i < count; i++)
	{
		if (ItemDataBase::GetInstance()->GetData(&NowItem))
		{
			if (NowItem->GetJobCode() == code)
			{
				cout << "<" << i + 1 << ". " << NowItem->GetName() << ">" << endl;
				cout << "\t분류 : " << NowItem->GetJobCode() << '/' << NowItem->GetTypeCode() << endl;
				cout << "\t가격 : " << NowItem->GetPrice() << endl;
				cout << "\tHP : " << NowItem->GetStatus()->Hp << endl;
				cout << "\tMP : " << NowItem->GetStatus()->Mp << endl;
				cout << "\tATK : " << NowItem->GetStatus()->ATK << endl;
				cout << "\tDEF : " << NowItem->GetStatus()->DEF << endl;
			}
		}
	}
	ItemDataBase::GetInstance()->GetDataEnd();
}
void ItemStore::DisplayShop()
{
	
	int count = ItemDataBase::GetInstance()->GetCount();
	for (int i = 0; i < count; i++)
	{
		if (ItemDataBase::GetInstance()->GetData(&NowItem))
		{
			cout << "<" << i + 1 << ". " << NowItem->GetName() << ">" << endl;
			cout << "\t분류 : " << NowItem->GetJobCode() << '/' << NowItem->GetTypeCode() << endl;
			cout << "\t가격 : " << NowItem->GetPrice() << endl;
			cout << "\tHP : " << NowItem->GetStatus()->Hp << endl;
			cout << "\tMP : " << NowItem->GetStatus()->Mp << endl;
			cout << "\tATK : " << NowItem->GetStatus()->ATK << endl;
			cout << "\tDEF : " << NowItem->GetStatus()->DEF << endl;
		}
	}
	ItemDataBase::GetInstance()->GetDataEnd();
}
void ItemStore::Sell(Character** pChar)
{
	
	Item* temp = nullptr;
	int count = ItemDataBase::GetInstance()->GetCount();
	
	int idx = 0;
	if (!strcmp((*pChar)->GetJOB(), "전사"))
		idx = CODE_WARRIOR;
	else if (!strcmp((*pChar)->GetJOB(), "사제"))
		idx = CODE_HEALER;
	else if (!strcmp((*pChar)->GetJOB(), "궁수"))
		idx = CODE_ARCHOR;
	else if (!strcmp((*pChar)->GetJOB(), "마법사"))
		idx = CODE_SORCERER;
	ShowShop(idx, count);
	
	int tempint;
	cout << "구매할 아이템 번호 : ";
	cin >> tempint;

	for (int i = 0; i < count; i++)
	{
		if (tempint == i)
			break;
		ItemDataBase::GetInstance()->GetData(&NowItem);
	}
	if (NowItem->GetTypeCode() == CODE_WEAPON)
		temp = new Weapon(NowItem->GetName(), NowItem->GetStatus(), NowItem->GetPrice(), NowItem->GetJobCode());
	else if (NowItem->GetTypeCode() == CODE_ARMOR)
		temp = new Armor(NowItem->GetName(), NowItem->GetStatus(), NowItem->GetPrice(), NowItem->GetJobCode());
	
	ItemDataBase::GetInstance()->Delete(NowItem);

	(*pChar)->BuyItem(temp);
	ItemDataBase::GetInstance()->GetDataEnd();
}
void ItemStore::Buy(Item** pItem)
{
	if (*pItem == nullptr)
	{
		cout << "Error!" << endl;
		return;
	}
	ItemDataBase::GetInstance()->Input(*pItem);
	return;
}
