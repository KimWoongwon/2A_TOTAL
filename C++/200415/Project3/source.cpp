#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> stack;
	
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);
	stack.Push(60);

	stack.Display_all();
	cout << endl;

	cout << "ã�� ��� : " << stack.Find(60) << endl;
	cout << "ã�� ��� : " << stack.Find(50) << endl;

	cout << "pop �Ǿ����ϴ�. : " << stack.Pop() << endl;
	cout << "pop �Ǿ����ϴ�. : " << stack.Pop() << endl;
	cout << "pop �Ǿ����ϴ�. : " << stack.Pop() << endl;

	cout << "ã�� ��� : " << stack.Find(60) << endl;
	cout << "ã�� ��� : " << stack.Find(50) << endl;

	stack.Display_all();
	return 0;
}

