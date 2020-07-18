#include "ElfFactory.h"
#include "../../Items/Factorys/WarriorItemFactory.h"
#include "../../Items/Factorys/ArchorItemFactory.h"
#include "../../Items/Factorys/SorcererItemFactory.h"

ElfFactory::ElfFactory()
{
	count = 0;
}
ElfFactory::~ElfFactory()
{
}

Character* ElfFactory::CreateCharacter(const char* p_name, CLASS Choice)
{
	ItemFactory* factory = nullptr;
	CLASS select = Choice;
	// 생성될때 받은 클래스 정보를 토대로 아이템 팩토리를 설정
	switch (select)
	{
	case CLASS::WARRIOR:
		factory = new WarriorItemFactory(REGION::ELF);
		break;
	case CLASS::ARCHER:
		factory = new ArchorItemFactory(REGION::ELF);
		break;
	case CLASS::SORCERER:
		factory = new SorcererItemFactory(REGION::ELF);
		break;
	}
	Character* tempchar = new Elf(p_name, select, factory);
	return tempchar;
}
