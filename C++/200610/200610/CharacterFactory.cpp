#include "CharacterFactory.h"
CharacterFactory::CharacterFactory()
{

}
CharacterFactory::~CharacterFactory()
{

}
Character* CharacterFactory::SettingCharacter()
{
	char p_name[20];
	Pet* pet = PetSelect();

	cout << "ĳ���� �̸� : ";
	cin >> p_name;
	cout << "------------------------" << endl;
	Character* tempchar = CreateCharacter(p_name,pet->pet_Name);

	tempchar->SetHp();
	tempchar->SetMp();
	tempchar->SetATK();
	tempchar->SetDEF();
	cout << "------------------------" << endl;
	cout << "ĳ���� ���� �Ϸ�" << endl;
	_getch();
	return tempchar;
}