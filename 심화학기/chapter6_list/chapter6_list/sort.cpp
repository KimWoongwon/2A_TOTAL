#include <iostream>
#include <list>
using namespace std;

struct Greater
{
	bool operator()(int left, int right) const
	{
		return left > right;
	}
};

void main()
{
	list<int> lt;
	lt.push_back(20);
	lt.push_back(50);
	lt.push_back(40);
	lt.push_back(10);
	lt.push_back(30);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	/*lt.sort();
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;*/

	lt.sort(greater<int>());	// 조건자 greater를 사용해서 내림차순으로 정렬
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(less<int>());		// 오름차순으로 정렬
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(Greater());
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}