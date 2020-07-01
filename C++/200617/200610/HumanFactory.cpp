#include "HumanFactory.h"
#include "WarriorItemFactory.h"
#include "ArchorItemFactory.h"
#include "HealerItemFactory.h"
#include "SorcererItemFactory.h"
HumanFactory::HumanFactory()
{
	memset(PossiblePetList, 0, sizeof(PossiblePetList));
	count = 0;

	PossiblePetList[count++] = new CharacterFactory::Pet("토끼");
	PossiblePetList[count++] = new CharacterFactory::Pet("다람쥐");
}
HumanFactory::~HumanFactory()
{
	for (int i = 0; i < count; i++)
	{
		if (PossiblePetList[i] != nullptr)
			delete PossiblePetList[i];
	}
}

Character* HumanFactory::CreateCharacter(const char* p_name, const char* p_petname)
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
		factory = new WarriorItemFactory(HUM);
		break;
	case HEALER:
		factory = new HealerItemFactory(HUM);
		break;
	case ARCHER:
		factory = new ArchorItemFactory(HUM);
		break;
	case SORCERER:
		factory = new SorcererItemFactory(HUM);
		break;
	}

	Character* tempchar = new Human(p_name, p_petname,select, factory);
	return tempchar;
}
CharacterFactory::Pet* HumanFactory::PetSelect()
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
