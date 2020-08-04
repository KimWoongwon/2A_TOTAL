// 캐릭터 아이템 검색
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void main()
{
	vector<int> CharItems;
	CharItems.push_back(12);
	CharItems.push_back(100);
	CharItems.push_back(77);

	vector<int>::iterator FindIter;
	FindIter = find(CharItems.begin(), CharItems.end(), 12);
	if (FindIter != CharItems.end())
		cout << "아이템 12를 찾았습니다." << endl;
	else
		cout << "아이템 12가 없습니다. " << endl;

	FindIter = find(CharItems.begin()+1, CharItems.end(), 12);
	if (FindIter != CharItems.end())
		cout << "아이템 12를 찾았습니다." << endl;
	else
		cout << "아이템 12가 없습니다. " << endl;
}