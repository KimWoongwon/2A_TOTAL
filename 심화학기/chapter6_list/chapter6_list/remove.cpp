#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n)	// 단항 조건자
{
	return n >= 30 && n <= 50;
}

void main()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(10);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);
	lt.push_back(10);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.reverse();
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.remove(10);	// 10을 찾아서 제거
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.remove_if(Predicate);	// 조건자가 참인 원소를 제거
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}