#include "ItemStore.h"
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



void ItemStore::ShowShop()
{
	cout << "<직업 선택>" << endl;
	cout << "1. 전사" << endl;
	cout << "2. 사제" << endl;
	cout << "3. 궁수" << endl;
	cout << "4. 마법사" << endl;
	int select;
	cin >> select;

	int code = 0;
	if (select == 1)
		code = CODE_WARRIOR;
	else if(select == 2)
		code = CODE_HEALER;
	else if (select == 3)
		code = CODE_ARCHOR;
	else if (select == 4)
		code = CODE_SORCERER;

	int count = ItemDataBase::GetInstance()->GetCount();
	for (int i = 0; i < count; i++)
	{
		if (ItemDataBase::GetInstance()->GetData(&NowItem))
		{
			if (NowItem->GetJobCode() == code)
			{
				cout << "<" << i + 1 << ". " << NowItem->GetName() << ">";
				cout << "\t분류 : " << NowItem->GetJobCode() << '/' << NowItem->GetTypeCode() << endl;
				cout << "\t가격 : " << NowItem->GetPrice() << endl;
				cout << "\tHP : " << NowItem->GetStatus()->Hp << endl;
				cout << "\tMP : " << NowItem->GetStatus()->Mp << endl;
				cout << "\tATK : " << NowItem->GetStatus()->ATK << endl;
				cout << "\tDEF : " << NowItem->GetStatus()->DEF << endl;
			}
		}
	}
}
void ItemStore::Init(Character* pChar)
{
	NowChar = pChar;
}
Item* ItemStore::Sell()
{
	Item* temp = nullptr;
	int count = ItemDataBase::GetInstance()->GetCount();

	
	int tempint;
	cout << "구매할 아이템 번호 : ";
	cin >> tempint;

	for (int i = 0; i < tempint; i++)
	{
		if (ItemDataBase::GetInstance()->GetData(&NowItem))
		{

		}
	}
	if (NowItem->GetTypeCode() == CODE_WEAPON)
	{
		temp = new Weapon(NowItem->GetName(), NowItem->GetStatus(), NowItem->GetPrice(), NowItem->GetTypeCode());
		ItemDataBase::GetInstance()->Delete(NowItem);
	}
	return temp;
}
void ItemStore::Buy(Item* pItem)
{
	ItemDataBase::GetInstance()->Input(pItem);
	return;
}
