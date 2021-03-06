#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class CNode
{
	T	mData;
	CNode<T>* mNext;

public:

	CNode<T>()
	{
		//cout << "���̽�" << endl;
		memset(&mData, 0, sizeof(mData));
		mNext = nullptr;
	}
	CNode<T>(T _data) : mData(_data), mNext(nullptr) {}
	~CNode<T>() {/* free(&mData);*/}

	T GetmData() { return mData; }
	CNode<T>* GetmNext() { return mNext; }

	void SetmData(T _data) { mData = _data; }
	void SetmNext(CNode<T>* _next) { mNext = _next; }

};


template <typename T>
class CNode<T*>
{
	T* mData;
	CNode<T*>* mNext;

public:

	CNode<T*>()
	{
		memset(&mData, 0, sizeof(mData));
		mNext = nullptr;
	}
	CNode<T*>(T* _data) : mData(_data), mNext(nullptr) {}
	~CNode<T*>() 
	{
		delete mData;  
		if (mNext != nullptr)
			mNext = nullptr;
	}

	T* GetmData() { return mData; }
	CNode<T*>* GetmNext() { return mNext; }

	void SetmData(T* _data) { mData = _data; }
	void SetmNext(CNode<T*>* _next) { mNext = _next; }

};


template<typename T>
class CLinkedList
{
	CNode<T>* mHead;
	CNode<T>* mTail;

public:
	CLinkedList<T>();
	~CLinkedList<T>();

	CNode<T>* GetmHead() { return mHead; }
	CNode<T>* GetmTail() { return mTail; }

	bool	Insert(T  _data);
	bool	Delete(T  _data);
};

template <typename T>
CLinkedList<T>::CLinkedList<T>()
{
	mHead = new CNode<T>();
	mTail = mHead;
}


template <typename T>
CLinkedList<T>::~CLinkedList<T>()
{
	CNode<T>* ptr = mHead->GetmNext();
	delete mHead;

	while (ptr != NULL)
	{
		mHead = ptr;
		ptr = ptr->GetmNext();
		delete mHead;
	}
}

template <typename T>
bool CLinkedList<T>::Insert(T _data)
{
	CNode<T>* ptr = new CNode<T>(_data);
	mTail->SetmNext(ptr);
	mTail = ptr;
	return true;
}

template <typename T>
bool CLinkedList<T>::Delete(T _data)
{
	CNode<T>* pre = mHead;
	CNode<T>* ptr = pre->GetmNext();
	bool flag = false;

	while (ptr != NULL)
	{
		if (ptr->GetmData() == _data)
		{
			flag = true;
			pre->SetmNext(ptr->GetmNext());
			if (ptr->GetmNext() == NULL)
			{
				mTail = pre;
			}
			//free(ptr);
			//delete _data;
			//delete ptr;
			ptr->~CNode();
			
			break;
		}

		pre = ptr;
		ptr = ptr->GetmNext();

	}

	if (flag)
	{
		return true;
	}

	return false;

}



#endif