#include "Global.h"
#include "Hum_Orc_Elf.h"

int main(void)
{
	Character* temp;

	cout << "-----HUMAN-----" << endl;
	temp = new Hum();
	temp->Attack();
	temp->Defence();

	delete temp;
	temp = nullptr;

	cout << "------ORC------" << endl;
	temp = new Orc();
	temp->Attack();
	temp->Defence();

	delete temp;
	temp = nullptr;

	cout << "------ELF------" << endl;
	temp = new Elf();
	temp->Attack();
	temp->Defence();

	delete temp;
	temp = nullptr;
}