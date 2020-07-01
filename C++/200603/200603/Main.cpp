#include <iostream>
#include "Base.h"
#include "Warrior.h"
#include "SecondWarrior.h"
using namespace std;

#define EXCONSTCAST 1
#define EXSTATICCAST 2
#define EXDYNAMICCAST 3
//#define REINTERPRETCAST 4

int main(void)
{
#ifndef EXCONSTCAST
	/*const_cast ����
		������� �ο��ϰų� �����ϴ� �۾��� �����ϴ�.int���� double������ �ٲٴ� �Ͻ���, ����� ����ȯ ���� ������ �ʴ´�.*/

	// ����� �ο�
	int age = 24;
	int& Rage = age;

	// const int& testage = age; �� ���� �Ͻ����� ����ȯ�� �����ϱ⶧���� �� ������� �ʴ´�.
	const int& testage = const_cast<int&>(age);

	// testage = 20; --> Error
	// const_cast�� ���� int���� age�� const int& �� ����ȯ �Ǿ� constŰ���尡 �߰��Ǿ���.
	cout << "testage - " << testage << endl;

	// ����� ����
	int a = 20;
	const int& b = a;
	// ������� ���� ������ ���� b�� const_cast�� ����ȯ �ؼ� ������ r������ �Ҵ��Ҽ� �ִ�.

	cout << "before : " << "a = " << a << " b = " << b << endl;

	int& r = const_cast<int&>(b);
	r = 24; // const���� �ƴϱ� ������ ���� ������ �ȴ�. ������� ���� r�� �����ϴ� a, b�� ��� �������.
	cout << "After : " << "a = " << a << " b = " << b << " r = " << r << endl;
#endif // !EXCONSTCAST

#ifndef EXSTATICCAST
	/* static_cast ����
		�������� ������ ������ ��쿡�� ����ȯ�� �����մϴ�.*/

	double a = 20.0f;
	int ia_1 = static_cast<int>(a);
	int ia_2 = static_cast<int>(20.0f);
	// ���� ���� �Ǽ��� ������ ��ȯ�ϴ� ���� �������� �����ϱ⶧���� ������ ���� �ʽ��ϴ�.
	// ���� ������ �Ǽ��� ��ȯ�ϴ� �͵� ���� �����մϴ�.
	
	double b = 20.0f;
	double* dpb = &b;
	//int* ipb = static_cast<int*>(dpb); // �̰�쿡�� Error�� ���.
	// �̰�� ó�� ������ ����ȯ�� ��� �����Ͽ����� ���� �˷��ݴϴ�.

	Warrior* CWarr_1 = new Warrior();
	Base* Cbase_1 = static_cast<Base*>(CWarr_1);
	// ��ĳ���õ� �����ϴ�.
	Cbase_1->Move();
	// Cbase->Attck(); ������ �ڽ�Ŭ������ �Լ��� ������ �� ����.

	//Warrior* CWarr = Cbase_1;  //�ڽ�Ŭ������ �θ�Ŭ������ ��°��� Error
	Warrior* CWarr_2 = static_cast<Warrior*>(Cbase_1);
	// ������ static_cast����ȯ�� ����ϸ� Error�� ���� �ʴ´�. �ٿ�ĳ������ �����ϴٴ� ���̴�.
	CWarr_2->Move();
	CWarr_2->Attck();
	// ���� Warrior�� �Լ��� ��� ȣ��ȴ�.

	// ��ü������ C����� ���������ȯ�� �ſ� ����ϴ�.
	// ��� C����� ����ȯ ���� �ξ��� ������̰� �������� ������ ����ȯ�� �����ϱ� ������ �ξ� �� �����ϴ�.

#endif // !EXSTATICCAST

#ifndef EXDYNAMICCAST
	/* dynamic_cast ����
		��Ӱ��� �ȿ��� �����ͳ� ������ Ÿ���� �⺻Ŭ�������� �Ļ�Ŭ�������� �ٿ�ĳ���ð� ���� ��ӿ��� �⺻ Ŭ�������� ������ Ÿ��ĳ���ÿ� ���ȴ�.*/
	// ��ĳ����, �ٿ�ĳ���� ��� �����ϴ�.


	Base* Cbase_1 = new Base();
	Warrior* CWarr_1 = dynamic_cast<Warrior*>(Cbase_1);
	if (CWarr_1 == NULL) // �����Ұ�� NULL�� �������ش�.
		cout << "Failed" << endl;
	// CWarr_3->Move(); ���α׷� ����
	// dynamic_cast �� ĳ�������ִ� ���� �����ͳ� �������� Ÿ���� �ٿ� ĳ�����ϴ� ������ ��ü�� Ÿ���� ĳ���������� ���Ѵ�.

	// SecondWarrior << BaseTwo�� Base�� ���߻�� ���� Ŭ����
	Base* one = NULL;
	BaseTwo* SWarr = new SecondWarrior(); // ��ĳ����

	//one = SWarr; �̰�쿡 �����Ͽ����� ǥ���Ѵ�.

	one = dynamic_cast<Base*>(SWarr);
	one->Move();
	// �̷��� dynamic_cast�� �̿��ϸ� �����ϴ�.

	// dynamic_cast�� ����ϱ� ���ؼ� �����Լ��� �ʼ��� �ʿ��ϴ�
	// �� ������ dynamic_cast�� ����ȯ�� �Ҷ� RTTI(Runtime Type Information)�� ����ؼ�
	// ��Ÿ���߿� �����ϴٰ� �����Ǵ°�쿡 ����ȯ�� �����ϱ� �����̴�.
	// c++������ Ŭ������ �����Լ��� �����ؾ߸� RTTI���� Ÿ�� ���� ��ü�� �����ϵ��� �����Ǿ��ְ�
	// ������ RTTI�� ����ϱ� ���ؼ� �����Լ��� �����ϴ� Ŭ�������� �Ѵٴ� ���̴�.

#endif // !EXSTATICCAST

#ifndef REINTERPRETCAST
	/* reinterpret_cast ����
		�� ����ȯ�� ��� ������� CŸ���� ����ȯ�� ����� ����� �Ѵ�.*/

	int a = 20;
	int* pa = &a;

	double* d = reinterpret_cast<double*>(pa);
	// �̷��͵� �����ϴ�.
	
	void* pv;
	pv = reinterpret_cast<void*>(pa);
	// ���� ���� ���� ����Ƿ� ����ȯ�� �����ϴ�
	// ����ϴ°��� �������� å���� ���α׷��ӿ��� �ִ�.
	cout << *pa << '\t' << *d << endl;


#endif // !EXSTATICCAST



	

	



}