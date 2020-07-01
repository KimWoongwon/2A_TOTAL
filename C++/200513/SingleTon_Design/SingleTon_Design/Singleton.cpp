#include "Singleton.h"

Singleton* Singleton::Instance = nullptr;
bool Singleton::InsFlag = false;


Singleton* Singleton::GetInstance()
{
	if (Instance == nullptr)
	{
		cout << "Create Singleton" << endl;
		Instance = new Singleton();
		InsFlag = true;
	}
	return Instance;
}
void Singleton::Addvalue(int p_val)
{
	cout << "Add Value : " << p_val << endl;
	m_val += p_val;
}
int Singleton::GetValue()
{
	return m_val;
}
