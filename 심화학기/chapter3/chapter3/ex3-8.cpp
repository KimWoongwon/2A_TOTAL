#include <iostream>
#include <functional>
using namespace std;

class Plus
{
public:
	int operator()(int n, int u)
	{
		return n + u;
	}
};

class Minus
{
public:
	int operator()(int x, int y)

	{
		return x - y;
	}
};

int main()
{
	cout << Plus()(10, 20) << endl;
	cout << Plus()(20, 10) << endl;
	cout << Minus()(10, 20) << endl;
	cout << Minus()(20, 10) << endl;
	cout << endl;

	cout << plus<int>()(10, 20) << endl;
	cout << plus<int>()(20, 10) << endl;
	cout << minus<int>()(10, 20) << endl;
	cout << minus<int>()(10, 20) << endl;
}