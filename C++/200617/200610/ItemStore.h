#pragma once
#include "Global.h"
#include "ItemDataBase.h"
class ItemStore
{
	DECLARE_SINGLETONE(ItemStore)
private:
	Item* NowItem;
	Character* NowChar;
	ItemStore();
	~ItemStore();
public:
	void ShowShop();
	void Init(Character*);
	Item* Sell();
	void Buy(Item*);

};

