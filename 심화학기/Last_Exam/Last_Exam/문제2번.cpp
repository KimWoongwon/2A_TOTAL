// 문제 2번
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UpperGenerate
{
	int count = 0;
	int operator()()
	{
		return (++count) * 10;
	}
};

void main()
{
	int selectPos;
	vector<int> vec1(10);
	UpperGenerate tUpperGenerate;
	generate(vec1.begin(), vec1.end(), tUpperGenerate);

	vector<int>::iterator iter;
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	cout << "어디까지 정렬할까요 ? : ";
	cin >> selectPos;

	cout << "일부분 정렬 후" << endl;
	sort(vec1.begin(), vec1.begin() + selectPos, greater<int>());
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

}