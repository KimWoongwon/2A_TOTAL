#pragma once
#include "Global.h"
#include "LinkedList.h"
#include "ItemFactory.h"
class Character
{
protected:
	char name[20];
	char pet[20];
	int Level;
	STATUS* status;

	CHAR_MENU kind;
	JOB job;
	Weapon* NowWeapon;
	Armor* NowArmor;

	
	Item* Inventory[20];
	int itemCount;
public:
	Character(const char*, const char*,JOB, ItemFactory*);
	virtual ~Character();

	void SetName(const char*);
	const char* GetName();
	int GetLevel();
	STATUS* GetStatus();
	const char* GetPetkind();
	const char* GetKind();
	const char* GetJOB();
	Weapon* GetWeapon();
	Armor* GetArmor();

	void ShowInventroy();
	void BuyItem(Item*);
	Item* SellItem();

	virtual void SetHp() = 0;
	virtual void SetMp() = 0;
	virtual void SetATK() = 0;
	virtual void SetDEF() = 0;
	

};

