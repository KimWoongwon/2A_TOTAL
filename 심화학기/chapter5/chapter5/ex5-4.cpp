#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> v;
	v.push_back(40);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);
	
	// 오름차순 정렬
	sort(v.begin(), v.end(), less<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;

	// 내림차순 정렬
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;
	return 0;
}