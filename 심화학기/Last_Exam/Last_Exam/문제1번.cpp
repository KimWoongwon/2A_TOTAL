// ¹®Á¦ 1¹ø
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(50);

	vector<int>::iterator iter;
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	vector<int>::iterator FindIter;
	FindIter = find(vec1.begin(), vec1.end(), 30);

	vec1.erase(FindIter);

	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;
}