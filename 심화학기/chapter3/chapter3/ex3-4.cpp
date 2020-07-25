#include <iostream>
#include <algorithm>	// for_each�� ���� ������ ������ �ϰ� ���ִ� ���
using namespace std;

//// Ŭ���̾�Ʈ ////

struct Functor1
{
	void operator()(int n)
	{
		cout << n << " ";
	}
};

struct Functor2
{
	void operator()(int n)
	{
		cout << n*n << " ";
	}
};

struct Functor3
{
	void operator()(int n)
	{
		cout << "���� : " << n << endl;
	}
};

void main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	/*Functor1 a;
	Functor2 b;
	Functor3 c;*/

	for_each(arr, arr + 5, Functor1());		// Ŭ���� �̸����� ��� �Լ��� ȣ���ϸ� ��üó�� �ȴ�.
	cout << endl;							// �̰��� Ŭ������ �̸����� ��ü�� ������ �ϰ� �Ѵٰ� �ؼ� �ӽ� ��ü��� �Ѵ�.
	for_each(arr, arr + 5, Functor3());
	cout << endl;
	for_each(arr, arr + 5, Functor3());
	cout << endl;
}
