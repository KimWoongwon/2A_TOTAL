#include <iostream>
using namespace std;

class A
{

};

class B
{
public:
	operator A()
	{
		cout << "operator A() 호출" << endl;
		return A();
	}

	operator int()
	{
		cout << "operator int() 호출" << endl;
		return 10;
	}
	operator double()
	{
		cout << "operator double() 호출" << endl;
		return 7.2;
	}
};

int main()
{
	B b;
	A a;
	int n;
	double d;

	a = b;
	n = b;
	d = b;
	cout << endl;

	a = b.operator A();
	n = b.operator int();
	d = b.operator double();
	cout << endl;

}