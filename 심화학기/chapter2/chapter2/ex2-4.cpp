#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "�����Լ� Print() : " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A �ȿ��ִ� �����Լ� Print() : " << n << endl;
	}
}

class Point
{
public:
	static void Print(int n)
	{
		cout << "����Ʈ Ŭ������ ��������Լ� Print() : " << n << endl;
	}
};

void main()
{
	Print(10);			// �����Լ�ȣ��
	A::Print(10);		// A�� �����Լ� ȣ��
	Point::Print(10);	// Ŭ������ �����Լ� ȣ��

	// �����Լ������� ����
	void(*pf)(int);
	pf = Print;
	pf(10);				// �Լ������͸� �̿��� �����Լ� ȣ��

	pf = A::Print;
	pf(10);				// �Լ������͸� �̿��� A�� �����Լ� ȣ��

	pf = Point::Print;
	pf(10);				// �Լ� �����͸� �̿��� ����Ʈ Ŭ������ ��������Լ� ȣ��
}
