#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> list;
	list.Insert(1, 10);
	list.Insert(2, 20);
	list.Insert(3, 30);
	list.Insert(4, 40);
	list.Insert(5, 50);
	list.Insert(60);

	list.Display_all();
	cout << endl;

	list.Delete(40);
	list.Insert(4, 41);
	list.Insert(4, 42);
	list.Display_all();
	return 0;
}

