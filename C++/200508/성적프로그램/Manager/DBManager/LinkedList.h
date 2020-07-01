#pragma once

template <typename T>
class CNode
{
	T	mData;
	CNode<T>* mNext;

public:

	CNode();
	CNode(T _data);
	~CNode();

	T GetmData();
	CNode<T>* GetmNext();
	void SetmData(T _data);
	void SetmNext(CNode<T>* _next);
};
template<typename T>
class CLinkedList
{
	CNode<T>* mHead;
	CNode<T>* mTail;

public:
	CLinkedList();
	~CLinkedList();

	CNode<T>* GetmHead() { return mHead; }
	CNode<T>* GetmTail() { return mTail; }

	bool	Insert(T  _data);
	bool	Delete(T  _data);
	T GetItem(int p_index);
};

