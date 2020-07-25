#include <iostream>
using namespace std;

void Print(int x, int y)
{
	cout << "전역함수: " << x << ", " << y << endl;
}

struct Functor
{
	void operator()(int x, int y)
	{
		cout << "함수 객체: " << x << ", " << y << endl;
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