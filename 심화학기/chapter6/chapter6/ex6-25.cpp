#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2(v.begin(), v.end());
	vector<int>::iterator iter;
	
	for (iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	vector<int> v3;
	v3.assign(v.begin(), v.end());
	for (iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}