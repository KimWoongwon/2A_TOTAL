#include "Global.h"
#include "Character.h"

void Create()
{
	Idle::Create();
	Walking::Create();
	Run::Create();
	Rolling::Create();
}

void Destory()
{
	Idle::Destory();
	Walking::Destory();
	Run::Destory();
	Rolling::Destory();
}

int main(void)
{
	Create();

	Character* character = new Character();


	for (int i = 0; i < 5; i++)
	{
		cout << "-------------------------" << endl << endl;
		character->Move();
		
		cout << "Press any Key";
		getchar();
		//system("cls");
	}
	
	delete character;
	Destory();
	return 0;
}

