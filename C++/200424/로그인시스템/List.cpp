#include "List.h"
template <typename T>
Node<T>::Node()
{
	Link = NULL;
}
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
List<T>::List()
{
	this->header = NULL;
}
template <typename T>
List<T>::~List()
{

}
template <typename T>
Node<T>* List<T>::Find(const T& input)
{
	Node<T>* cur = this->header;
	while (cur != NULL)
	{
		if (cur->OutputData() == input)
			return cur;
		cur = cur->OutputNode();
	}
	return NULL;
}

template <typename T>
void List<T>::Insert(T input)
{
	if (this->header == NULL)
	{
		Node<T>* temp = new Node<T>;
		this->header = temp;
		temp->InputData(input);
		temp->InputNode(NULL);
		return;
	}
	Node<T>* temp = new Node<T>;
	Node<T>* cur = this->header;
	while (cur->OutputNode() != NULL)
		cur = cur->OutputNode();

	temp->InputData(input);
	temp->InputNode(cur->OutputNode());
	cur->InputNode(temp);
}

template <typename T>
void List<T>::Insert(int position, T input)
{
	if (position == 1 || this->header == NULL)
	{
		Node<T>* temp = new Node<T>;
		this->header = temp;
		temp->InputData(input);
		temp->InputNode(NULL);
		return;
	}
	Node<T>* temp = new Node<T>;
	Node<T>* cur = this->header;

	for (int i = 1; i < position - 1; i++)
	{
		if (cur->OutputNode() != NULL)
			cur = cur->OutputNode();
	}

	temp->InputData(input);
	temp->InputNode(cur->OutputNode());
	cur->InputNode(temp);
}
template <typename T>
void List<T>::Delete(T input)
{
	if (this->header == NULL)
	{
		cout << "리스트가 비어있습니다." << endl;
		return;
	}
	Node<T>* temp = this->header;
	Node<T>* dcur = this->Find(input);
	if (dcur == this->header)
	{
		this->header = dcur->OutputNode();
	}
	else
	{
		while (temp->OutputNode() != dcur)
		{
			temp = temp->OutputNode();
		}
		temp->InputNode(dcur->OutputNode());
	}
	delete dcur;
	return;

}
template <typename T>
T List<T>::DataOut(int index)
{
	Node<T>* temp = this->header;
	for (int a = 0; a < index; a++)
	{
		temp = temp->OutputNode();
	}
	return temp->OutputData();
}