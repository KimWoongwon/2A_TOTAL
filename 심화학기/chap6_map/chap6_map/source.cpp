#include <iostream>
#include <map>
using namespace std;
void main()
{
	map<int, int, less<int>> m;

	m.insert(pair<int, int>(5, 100));	// 임시객체를 활용해 저장하는 방법
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pair<int, int> pr(9, 50);			// 객체를 생성후 저장하는 방법
	m.insert(pr);
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << "," << iter->second << ")" << " ";
	cout << endl;
}