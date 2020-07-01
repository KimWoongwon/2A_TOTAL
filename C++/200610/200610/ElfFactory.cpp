#include "ElfFactory.h"
#include "WarriorItemFactory.h"
#include "ArchorItemFactory.h"
#include "HealerItemFactory.h"
#include "SorcererItemFactory.h"
ElfFactory::ElfFactory()
{
	memset(PossiblePetList, 0, sizeof(PossiblePetList));
	count = 0;

	PossiblePetList[count++] = new CharacterFactory::Pet("��������");
	PossiblePetList[count++] = new CharacterFactory::Pet("������");
	PossiblePetList[count++] = new CharacterFactory::Pet("�ٶ�����");
	PossiblePetList[count++] = new CharacterFactory::Pet("������");
}
ElfFactory::~ElfFactory()
{
	for (int i = 0; i < count; i++)
	{
		if (PossiblePetList[i] != nullptr)
			delete PossiblePetList[i];
	}
}

Character* ElfFactory::CreateCharacter(const char* p_name, const char* p_petname)
{
	cout << "< ���� >" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. �ü�" << endl;
	cout << "4. ������" << endl;
	JOB select;
	do
	{
		cout << "���� : ";
		cin >> select;
		if (select < WARRIOR || select > SORCERER)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			cout << "------------------------" << endl;
		}
	} while (select < WARRIOR || select > SORCERER);

	ItemFactory* factory = nullptr;

	switch (select)
	{
	case WARRIOR:
		factory = new WarriorItemFactory(ELF);
		break;
	case HEALER:
		factory = new HealerItemFactory(ELF);
		break;
	case ARCHER:
		factory = new ArchorItemFactory(ELF);
		break;
	case SORCERER:
		factory = new SorcererItemFactory(ELF);
		break;

	}
	Character* tempchar = new Elf(p_name, p_petname, select, factory);
	return tempchar;
}
CharacterFactory::Pet* ElfFactory::PetSelect()
{
	cout << "< �� ���! >" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << "." << PossiblePetList[i]->pet_Name << endl;
	}
	int select;
	do
	{
		cout << "���� : ";
		cin >> select;
		if (select < 1 || select > count)
		{
			cout << "�߸��Է��߽��ϴ�" << endl;
			cout << "------------------------" << endl;
		}
	} while (select < 1 || select > count);
	cout << "------------------------" << endl;
	return PossiblePetList[select - 1];
}
