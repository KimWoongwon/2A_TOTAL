#include <iostream>
#include <algorithm>	// for_each와 같은 서버의 역할을 하게 해주는 헤더
using namespace std;

//// 클라이언트 ////

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
		cout << "정수 : " << n << endl;
	}
};

void main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	/*Functor1 a;
	Functor2 b;
	Functor3 c;*/

	for_each(arr, arr + 5, Functor1());		// 클래스 이름에다 대고 함수를 호출하면 객체처리 된다.
	cout << endl;							// 이것을 클래스의 이름으로 객체의 역할을 하게 한다고 해서 임시 객체라고 한다.
	for_each(arr, arr + 5, Functor3());
	cout << endl;
	for_each(arr, arr + 5, Functor3());
	cout << endl;
}
