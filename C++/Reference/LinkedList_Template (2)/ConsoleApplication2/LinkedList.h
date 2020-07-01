#ifndef _CLINKEDLIST_H
#define _CLINKEDLIST_H

struct sample
{
	char name[10];
	int age;

	bool operator==(sample& _sam)
	{
		if (!strcmp(name, _sam.name) && age == _sam.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

template <typename T>
class CNode
{
	T	mData;
	CNode<T>*	mNext;

public:

	CNode()
	{
		memset(&mData, 0, sizeof(mData));
		mNext = nullptr;
	}

	CNode(T _data) : mData(_data), mNext(nullptr){}
	~CNode(){}

	T GetmData()
	{
		return mData;
	}

	CNode<T>*  GetmNext()
	{
		return mNext;
	}

	void SetmData(T _data)
	{
		mData=_data;
	}

	void SetmNext(CNode<T>* _next)
	{
		mNext=_next;
	}
	
};



template<typename T>
class CLinkedList
{
	CNode<T>*	mHead;
	CNode<T>*	mTail;

public:
	CLinkedList();
	~CLinkedList();

	CNode<T>*  GetmHead(){ return mHead; }
	CNode<T>*  GetmTail(){ return mTail; }

	bool	Insert(T  _data);
	bool	Delete(T  _data);
};

template <typename T>
CLinkedList<T>::CLinkedList()
{
	mHead = new CNode<T>();
	mTail = mHead;
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

// <<기본 int data를 가지는 링크드 리스트>>

//class CNode
//{
//	int	mData;
//	CNode*	mNext;
//
//public:
//
//	CNode()
//	{
//		mData = 0;
//		mNext = nullptr;
//	}
//
//	CNode(int _data) : mData(_data), mNext(nullptr){}
//	~CNode(){}
//
//	int GetmData()
//	{
//		return mData;
//	}
//
//	CNode*  GetmNext()
//	{
//		return mNext;
//	}
//
//	void SetmData(int _data)
//	{
//		mData = _data;
//	}
//
//	void SetmNext(CNode* _next)
//	{
//		mNext = _next;
//	}
//
//};
//
//class CLinkedList
//{
//	CNode*	mHead;
//	CNode*	mTail;
//
//public:
//	CLinkedList();
//	~CLinkedList();
//
//	CNode*  GetmHead(){ return mHead; }
//	CNode*  GetmTail(){ return mTail; }
//
//	bool	Insert(int  _data);
//	bool	Delete(int  _data);
//};
//
//CLinkedList::CLinkedList()
//{
//	mHead = new CNode();
//	mTail = mHead;
//}
//
//
//
//CLinkedList::~CLinkedList()
//{
//	CNode* ptr = mHead->GetmNext();
//	delete mHead;
//
//	while (ptr != NULL)
//	{
//		mHead = ptr;
//		ptr = ptr->GetmNext();
//		delete mHead;
//	}
//}
//
//bool CLinkedList::Insert(int _data)
//{
//	CNode* ptr = new CNode(_data);
//	mTail->SetmNext(ptr);
//	mTail = ptr;
//	return true;
//}
//
//bool CLinkedList::Delete(int _data)
//{
//	CNode* pre = mHead;
//	CNode* ptr = pre->GetmNext();
//	bool flag = false;
//
//	while (ptr != NULL)
//	{
//		if (ptr->GetmData() == _data)
//		{
//			flag = true;
//			pre->SetmNext(ptr->GetmNext());
//			if (ptr->GetmNext() == NULL)
//			{
//				mTail = pre;
//			}
//			delete ptr;
//			break;
//		}
//
//		pre = ptr;
//		ptr = ptr->GetmNext();
//
//	}
//
//	if (flag)
//	{
//		return true;
//	}
//
//	return false;
//
//}




#endif