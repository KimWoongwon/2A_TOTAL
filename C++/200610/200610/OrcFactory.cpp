#include "OrcFactory.h"
#include "WarriorItemFactory.h"
#include "ArchorItemFactory.h"
#include "HealerItemFactory.h"
#include "SorcererItemFactory.h"


OrcFactory::OrcFactory()
{
	memset(PossiblePetList, 0, sizeof(PossiblePetList));
	count = 0;

	PossiblePetList[count++] = new CharacterFactory::Pet("거미");
	PossiblePetList[count++] = new CharacterFactory::Pet("사마귀");
}
OrcFactory::~OrcFactory()
{
	for (int i = 0; i < count; i++)
	{
		if (PossiblePetList[i] != nullptr)
			delete PossiblePetList[i];
	}
}

Character* OrcFactory::CreateCharacter(const char* p_name, const char* p_petname)
{
	cout << "< 직업 >" << endl;
	cout << "1. 전사" << endl;
	cout << "2. 사제" << endl;
	cout << "3. 궁수" << endl;
	cout << "4. 마법사" << endl;
	JOB select;
	do
	{
		cout << "선택 : ";
		cin >> select;
		if (select < WARRIOR || select > SORCERER)
		{
			cout << "잘못입력했습니다" << endl;
			cout << "------------------------" << endl;
		}
	} while (select < WARRIOR || select > SORCERER);

	ItemFactory* factory = nullptr;

	switch (select)
	{
	case WARRIOR:
		factory = new WarriorItemFactory(ORC);
		break;
	case HEALER:
		factory = new HealerItemFactory(ORC);
		break;
	case ARCHER:
		factory = new ArchorItemFactory(ORC);
		break;
	case SORCERER:
		factory = new SorcererItemFactory(ORC);
		break;
	}
	Character* tempchar = new Orc(p_name, p_petname, select, factory);
	return tempchar;
}
CharacterFactory::Pet* OrcFactory::PetSelect()
{
	cout << "< 펫 목록! >" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << "." << PossiblePetList[i]->pet_Name << endl;
	}
	int select;

	do
	{
		cout << "선택 : ";
		cin >> select;
		if (select < 1 || select > count)
		{
			cout << "잘못입력했습니다" << endl;
			cout << "------------------------" << endl;
		}
	} while (select < 1 || select > count);
	cout << "------------------------" << endl;
	return PossiblePetList[select - 1];
}
