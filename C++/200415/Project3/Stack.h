#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Node
{
private:
	T data;
	Node* Link;
public:
	Node()
	{
		Link = NULL;
	}
	void InputData(T data);
	void InputNode(Node<T>* Node);
	Node<T>* OutputNode();
	T OutputData();
};
template <typename T>
void Node<T>::InputData(T data)
{
	this->data = data;
}
template <typename T>
void Node<T>::InputNode(Node<T>* Node)
{
	this->Link = Node;
}
template <typename T>
Node<T>* Node<T>::OutputNode()
{
	return this->Link;
}
template <typename T>
T Node<T>::OutputData()
{
	return this->data;
}

template <typename T>
class Stack
{
private:
	Node<T>* Top;
public:
	Stack();
	~Stack();
	T Find(T input);
	void Push(T input);
	T Pop();
	void Display_all();
};

template <typename T>
Stack<T>::Stack()
{
	this->Top = NULL;
}
template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
T Stack<T>::Find(T input)
{
	Node<T>* cur = this->Top;
	while (cur->OutputNode() != NULL)
	{
		if (cur->OutputData() == input)
			return cur->OutputData();
		cur = cur->OutputNode();
	}
	cout << "일치하는 항목이 없습니다." << endl;
	return NULL;
}
template <typename T>
void Stack<T>::Push(T input)
{
	Node<T>* temp = new Node<T>;
	temp->InputData(input);
	temp->InputNode(this->Top);
	this->Top = temp;
}

template <typename T>
T Stack<T>::Pop()
{
	if (this->Top == NULL)
	{
		cout << "스택이 비어있습니다." << endl;
		return NULL;
	}
	Node<T>* temp = this->Top;
	T object= this->Top->OutputData();
	this->Top = this->Top->OutputNode();
	delete(temp);

	return object;
}
template <typename T>
void Stack<T>::Display_all()
{
	int i = 1;
	Node<T>* temp = this->Top;
	while (temp != NULL)
	{
		cout << i << "번째 : " << temp->OutputData() << endl;
		temp = temp->OutputNode();
		i++;
	}
}