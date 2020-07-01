#ifndef _CLINKEDLIST_H
#define _CLINKEDLIST_H


template <typename T>
class CNode
{
	T	mData;
	CNode<T>* mNext;

public:

	CNode()
	{
		memset(&mData, 0, sizeof(mData));
		mNext = nullptr;
	}

	CNode(T _data) : mData(_data), mNext(nullptr) {}
	~CNode() {}

	T GetmData()
	{
		return mData;
	}

	CNode<T>* GetmNext()
	{
		return mNext;
	}

	void SetmData(T _data)
	{
		mData = _data;
	}
	void SetmNext(CNode<T>* _next)
	{
		mNext = _next;
	}

};


//template <typename T>
//class CNode<T*>
//{
//	T*	mData;
//	CNode<T*>*	mNext;
//
//public:
//
//	CNode()
//	{
//		memset(&mData, 0, sizeof(mData));
//		mNext = nullptr;
//	}
//
//	CNode(T* _data) : mData(_data), mNext(nullptr){}
//
//	~CNode()
//	{
//		delete mData; 
//	}
//
//	T* GetmData()
//	{
//		return mData; 
//	}
//
//	CNode<T*>*  GetmNext()
//	{
//		return mNext; 
//	}
//
//	void SetmData(T* _data)
//	{
//		mData = _data; 
//	}
//
//	void SetmNext(CNode<T*>* _next)
//	{
//		mNext = _next; 
//	}
//
//};

template<typename T>
class CLinkedList
{
	CNode<T>* mHead;
	CNode<T>* mTail;

	int			mNodeCount;

public:
	CLinkedList();
	~CLinkedList();

	CNode<T>* GetmHead() { return mHead; }
	CNode<T>* GetmTail() { return mTail; }
	int			GetNodeCount() { return mNodeCount; }
	bool		Insert(T  _data);
	bool		Delete(T  _data);
	bool		Remove(T  _data);
};

template <typename T>
CLinkedList<T>::CLinkedList()
{
	mHead = new CNode<T>();
	mTail = mHead;
	mNodeCount = 0;
}


template <typename T>
CLinkedList<T>::~CLinkedList()
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
	mNodeCount++;
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
			delete ptr;
			mNodeCount--;
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

template <typename T>
bool CLinkedList<T>::Remove(T _data)
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
			delete ptr->GetmData();
			delete ptr;
			mNodeCount--;
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