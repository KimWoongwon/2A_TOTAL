#include <iostream>
#include <functional> // less()���
using namespace std;

//struct Less
//{
//	bool operator()(int a, int b)
//	{
//		return a < b;
//	}
//};
//
//struct Greater
//{
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//
//};


int main()
{
	cout << less<int>()(10, 20) << endl;				// �Լ� ��ü
	cout << less<int>()(20, 10) << endl;
	cout << greater<int>()(10, 20) << endl;
	cout << greater<int>()(20, 10) << endl;
	
}