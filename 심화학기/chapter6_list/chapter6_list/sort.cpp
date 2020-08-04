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

	lt.sort(greater<int>());	// ������ greater�� ����ؼ� ������������ ����
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(less<int>());		// ������������ ����
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(Greater());
	for (iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}