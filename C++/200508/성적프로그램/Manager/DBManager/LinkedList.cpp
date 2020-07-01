#include "../../Main/Global.h"
#include "LinkedList.h"

template<typename T>
CNode<T>::CNode()
{
	memset(&mData, 0, sizeof(mData));
	mNext = nullptr;
}
template<typename T>
CNode<T>::CNode(T _data) : mData(_data), mNext(nullptr)
{

}
template<typename T>
CNode<T>::~CNode()
{

}

template<typename T>
T CNode<T>::GetmData()
{
	return mData;
}
template<typename T>
CNode<T>* CNode<T>::GetmNext()
{
	return mNext;
}
template<typename T>
void CNode<T>::SetmData(T _data)
{
	mData = _data;
}
template<typename T>
void CNode<T>::SetmNext(CNode<T>* _next)
{
	mNext = _next;
}

//----------------------------------------------------------

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

template <typename T>
T CLinkedList<T>::GetItem(int p_index)
{
	CNode<T>* temp = mHead;
	for (int i = 0; i < p_index; i++)
		temp = temp->GetmNext();
	return temp->GetmData();
}