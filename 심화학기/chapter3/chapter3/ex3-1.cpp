#include <iostream>
using namespace std;

void Print(int x, int y)
{
	cout << "�����Լ�: " << x << ", " << y << endl;
}

struct Functor
{
	void operator()(int x, int y)
	{
		cout << "�Լ� ��ü: " << x << ", " << y << endl;
	}
};

int main()
{
	Functor functor;
	Print(10, 20);
	functor(10, 20);
	functor.operator()(10,20);

	return 0;
}