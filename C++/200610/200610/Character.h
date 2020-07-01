#pragma once
#include "Global.h"
#include "ItemFactory.h"
class Character
{
protected:
	char name[20];
	char pet[20];
	int Level;
	STATUS* status;

	ItemFactory* blacksmith;
	CHAR_MENU kind;
	JOB job;
	char Weapon[50];
	char Armor[50];
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
	const char* GetWeapon();
	const char* GetArmor();

	virtual void SetHp() = 0;
	virtual void SetMp() = 0;
	virtual void SetATK() = 0;
	virtual void SetDEF() = 0;
	

};

