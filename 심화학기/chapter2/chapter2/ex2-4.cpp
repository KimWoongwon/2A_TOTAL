#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "전역함수 Print() : " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A 안에있는 전역함수 Print() : " << n << endl;
	}
}

class Point
{
public:
	static void Print(int n)
	{
		cout << "포인트 클래스의 정적멤버함수 Print() : " << n << endl;
	}
};

void main()
{
	Print(10);			// 전역함수호출
	A::Print(10);		// A의 전역함수 호출
	Point::Print(10);	// 클래스의 정적함수 호출

	// 정적함수포인터 선언
	void(*pf)(int);
	pf = Print;
	pf(10);				// 함수포인터를 이용한 전역함수 호출

	pf = A::Print;
	pf(10);				// 함수포인터를 이용한 A의 전역함수 호출

	pf = Point::Print;
	pf(10);				// 함수 포인터를 이용한 포인트 클래스의 정적멤버함수 호출
}
