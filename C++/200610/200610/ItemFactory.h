#pragma once
class ItemFactory
{
protected:
	CHAR_MENU kind;
public:
	ItemFactory(CHAR_MENU p_kind) { kind = p_kind; }
	~ItemFactory() {}

	virtual const char* CreateWeapon() = 0;
	virtual const char* CreateArmor() = 0;
};

