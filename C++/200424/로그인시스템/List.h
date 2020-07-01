#ifndef LIST_H
#define LIST_H

template <typename T>
class Node
{
private:
	T data;
	Node* Link;
public:
	Node();

	void InputData(T data);
	void InputNode(Node<T>* Node);
	Node<T>* OutputNode();
	T OutputData();
};

template <typename T>
class List
{
private:
	Node<T>* header;
public:
	List();
	~List();
	Node<T>* Find(const T& input);
	void Insert(T input);
	void Insert(int position, T input);
	void Delete(T input);
	T DataOut(int index);
};

#endif // !LIST_H


