//#include <iostream>
#include "Singleton.h"

using namespace std;

int main(void)
{
	Singleton::GetInstance(); // singleton �� �����Ǵ� �κ�

	Singleton::GetInstance()->Addvalue(20); //GetInstance�� ������ ȣ������� �޼����� �ѹ��� ���
	Singleton::GetInstance()->Addvalue(20); //AddValue�� ������ ������.
	Singleton::GetInstance()->Addvalue(20);
	Singleton::GetInstance()->Addvalue(20);

	cout << "result : " << Singleton::GetInstance()->GetValue() << endl << endl;

	Singleton* ins1;
	Singleton* ins2;
	Singleton* ins3;
	ins1 = Singleton::GetInstance();	// GetInstance�� ������ �Ҵ������� �Ҵ� �Ҷ����� ���� ��������°��� �ƴϱ� ������
	ins2 = Singleton::GetInstance();	// ins�������� ��� ���� �ּҰ��� �����ϰ� �ִ�.
	ins3 = Singleton::GetInstance();

	cout << "ins1 : " << ins1 << endl;
	cout << "ins2 : " << ins2 << endl;
	cout << "ins3 : " << ins3 << endl;


	return 0;
}