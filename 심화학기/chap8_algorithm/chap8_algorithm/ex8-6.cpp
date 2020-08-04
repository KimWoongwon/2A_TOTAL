#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

void main()
{
	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(20);
	vec1.push_back(40);
	vec1.push_back(50);
	vec1.push_back(30);

	vector<int>::iterator iterPos;
	cout << "vec1에 있는 모든 데이터 출력" << endl;
	for (iterPos = vec1.begin(); iterPos != vec1.end(); iterPos++)
		cout << *iterPos << "  ";
	cout << endl << endl; 

	cout << "vec1 에서 20 remove" << endl;
	vector<int>::iterator RemovePos = remove(vec1.begin(), vec1.end(), 20);
	for (iterPos = vec1.begin(); iterPos != vec1.end(); iterPos++)
		cout << *iterPos << "  ";
	cout << endl << endl;

	cout << "vec1에서 20 remove 이후 사용하지 않는 영역 완전 제거" << endl;
	while (RemovePos != vec1.end())
		RemovePos = vec1.erase(RemovePos);
	for (iterPos = vec1.begin(); iterPos != vec1.end(); iterPos++)
		cout << *iterPos << "  ";
	cout << endl << endl;
}