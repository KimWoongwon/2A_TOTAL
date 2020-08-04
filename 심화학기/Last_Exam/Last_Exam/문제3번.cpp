// 문제 3번
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
	int selectPos;
	vector<int> vec1;
	vec1.push_back(70);
	vec1.push_back(20);
	vec1.push_back(32);
	vec1.push_back(40);
	vec1.push_back(33);
	vec1.push_back(60);
	vec1.push_back(32);
	vec1.push_back(33);
	vec1.push_back(90);
	vec1.push_back(50);

	vector<int>::iterator iter;
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	vector<int>::iterator sortIter = vec1.begin();
	vector<int>::iterator compareIter;

	while (sortIter != vec1.end())
	{
		for (compareIter = sortIter + 1; compareIter != vec1.end(); compareIter++)
		{
			if (*sortIter == *compareIter)
			{
				vec1.erase(compareIter);
				break;
			}
		}
		++sortIter;
	}

	cout << "중복 제거 처리" << endl;
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	cout << "오름차순으로 정렬" << endl;
	sort(vec1.begin(), vec1.end(), less<int>());
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

}