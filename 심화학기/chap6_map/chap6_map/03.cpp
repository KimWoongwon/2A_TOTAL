#include <iostream>
#include <map>
using namespace std;
void main()
{
	map<int, int, less<int>> m;
	m[5] = 100;
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << "," << iter->second << ")" << " ";
	cout << endl << endl;

	m[5] = 200;	// °»½Å
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << "," << iter->second << ")" << " ";
	cout << endl;
}
