//#include <iostream>
#include "Singleton.h"

using namespace std;

int main(void)
{
	Singleton::GetInstance(); // singleton 이 생성되는 부분

	Singleton::GetInstance()->Addvalue(20); //GetInstance가 여러번 호출되지만 메세지는 한번만 출력
	Singleton::GetInstance()->Addvalue(20); //AddValue가 여러번 찍힌다.
	Singleton::GetInstance()->Addvalue(20);
	Singleton::GetInstance()->Addvalue(20);

	cout << "result : " << Singleton::GetInstance()->GetValue() << endl << endl;

	Singleton* ins1;
	Singleton* ins2;
	Singleton* ins3;
	ins1 = Singleton::GetInstance();	// GetInstance를 여러번 할당했지만 할당 할때마다 새로 만들어지는것이 아니기 떄문에
	ins2 = Singleton::GetInstance();	// ins변수들은 모두 같은 주소값을 저장하고 있다.
	ins3 = Singleton::GetInstance();

	cout << "ins1 : " << ins1 << endl;
	cout << "ins2 : " << ins2 << endl;
	cout << "ins3 : " << ins3 << endl;


	return 0;
}