// ĳ���� ������ �˻�
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
		cout << "������ 12�� ã�ҽ��ϴ�." << endl;
	else
		cout << "������ 12�� �����ϴ�. " << endl;

	FindIter = find(CharItems.begin()+1, CharItems.end(), 12);
	if (FindIter != CharItems.end())
		cout << "������ 12�� ã�ҽ��ϴ�." << endl;
	else
		cout << "������ 12�� �����ϴ�. " << endl;
}