#include "HumanFactory.h"
#include "../../Items/Factorys/WarriorItemFactory.h"
#include "../../Items/Factorys/ArchorItemFactory.h"
#include "../../Items/Factorys/SorcererItemFactory.h"
HumanFactory::HumanFactory()
{
	count = 0;
}
HumanFactory::~HumanFactory()
{

}

Character* HumanFactory::CreateCharacter(const char* p_name, CLASS Choice)
{
	ItemFactory* factory = nullptr;
	CLASS select = Choice;
	// �����ɶ� ���� Ŭ���� ������ ���� ������ ���丮�� ����
	switch (select)
	{
	case CLASS::WARRIOR:
		factory = new WarriorItemFactory(REGION::HUM);
		break;
	case CLASS::ARCHER:
		factory = new ArchorItemFactory(REGION::HUM);
		break;
	case CLASS::SORCERER:
		factory = new SorcererItemFactory(REGION::HUM);
		break;
	}

	Character* tempchar = new Human(p_name,select, factory);
	return tempchar;
}
