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

	// 20을 찾아서 200으로 변경합니다.
	replace(vec1.begin() + 2, vec1.end(), 20, 200);
	for (iterPos = vec1.begin(); iterPos != vec1.end(); iterPos++)
		cout << *iterPos << "  ";
	cout << endl << endl;

	
}