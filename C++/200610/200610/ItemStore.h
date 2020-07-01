#pragma once
#include "Global.h"
#include "ItemDataBase.h"
class ItemStore
{
	DECLARE_SINGLETONE(ItemStore)
private:
	Item* NowItem;
	ItemStore();
	~ItemStore();
public:
	void ShowShop(int,int);
	void DisplayShop();
	void Sell(Character**);
	void Buy(Item**);

};

