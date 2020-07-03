#include "MoveStateInterface.h"
#include "Character.h"

// Idle
Idle* Idle::instance = nullptr;
void Idle::Create()
{
	if (instance == nullptr)
		instance = new Idle();
}
void Idle::Destory()
{
	if (instance != nullptr)
		delete instance;
}
Idle* Idle::GetInstace()
{
	return instance;
}
void Idle::CharacterMove(Character* character)
{
	
	cout << "Idle!" << endl;
	character->SetState(Walking::GetInstace());
}

// Walking
Walking* Walking::instance = nullptr;
void Walking::Create()
{
	if (instance == nullptr)
		instance = new Walking();
}
void Walking::Destory()
{
	if (instance != nullptr)
		delete instance;
}
Walking* Walking::GetInstace()
{
	return instance;
}
void Walking::CharacterMove(Character* character)
{
	character->SetState(Run::GetInstace());
	cout << "Walking!" << endl;
}

// Run
Run* Run::instance = nullptr;
void Run::Create()
{
	if (instance == nullptr)
		instance = new Run();
}
void Run::Destory()
{
	if (instance != nullptr)
		delete instance;
}
Run* Run::GetInstace()
{
	return instance;
}
void Run::CharacterMove(Character* character)
{
	character->SetState(Rolling::GetInstace());
	cout << "Run!" << endl;
}

// Rolling
Rolling* Rolling::instance = nullptr;
void Rolling::Create()
{
	if (instance == nullptr)
		instance = new Rolling();
}
void Rolling::Destory()
{
	if (instance != nullptr)
		delete instance;
}
Rolling* Rolling::GetInstace()
{
	return instance;
}
void Rolling::CharacterMove(Character* character)
{
	character->SetState(Idle::GetInstace());
	cout << "Rolling!" << endl;
}
