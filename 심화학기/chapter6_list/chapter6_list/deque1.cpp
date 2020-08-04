#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void main()
{
	vector<int> v(4,100);
	deque<int> dq(4,100);

	v.push_back(200);
	dq.push_front(500);

	cout << "deque  : ";
	for (deque<int>::size_type i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl << endl;

	cout << "vector : ";
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl << endl;

	deque<int> dq2;
	dq2.push_back(10);
	dq2.push_back(20);
	dq2.push_back(30);
	dq2.push_back(40);
	dq2.push_back(50);

	cout << "deque2(push_back)  : ";
	for (deque<int>::size_type i = 0; i < dq2.size(); i++)
		cout << dq2[i] << " ";
	cout << endl;

	dq2.push_front(100);
	dq2.push_front(200);

	cout << "deque2(push_front) : ";
	for (deque<int>::size_type i = 0; i < dq2.size(); i++)
		cout << dq2[i] << " ";
	cout << endl << endl;
}