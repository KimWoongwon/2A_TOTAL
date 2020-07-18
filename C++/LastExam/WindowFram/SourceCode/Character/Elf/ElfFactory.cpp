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
	// �����ɶ� ���� Ŭ���� ������ ���� ������ ���丮�� ����
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
