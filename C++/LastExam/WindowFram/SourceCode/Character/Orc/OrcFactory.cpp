#include "OrcFactory.h"
#include "../../Items/Factorys/WarriorItemFactory.h"
#include "../../Items/Factorys/ArchorItemFactory.h"
#include "../../Items/Factorys/SorcererItemFactory.h"


OrcFactory::OrcFactory()
{
	count = 0;
}
OrcFactory::~OrcFactory()
{

}

Character* OrcFactory::CreateCharacter(const char* p_name, CLASS Choice)
{
	ItemFactory* factory = nullptr;
	CLASS select = Choice;
	// 생성될때 받은 클래스 정보를 토대로 아이템 팩토리를 설정
	switch (select)
	{
	case CLASS::WARRIOR:
		factory = new WarriorItemFactory(REGION::ORC);
		break;
	case CLASS::ARCHER:
		factory = new ArchorItemFactory(REGION::ORC);
		break;
	case CLASS::SORCERER:
		factory = new SorcererItemFactory(REGION::ORC);
		break;
	}
	Character* tempchar = new Orc(p_name, select, factory);
	return tempchar;
}
