#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(void)
{

	CLinkedList<sample*>* lst = new CLinkedList<sample*>();

	sample* sam = new sample;
	strcpy(sam->name, "aaa");
	sam->age = 30;

	lst->Insert(sam);

	sam = new sample;
	strcpy(sam->name, "bbb");
	sam->age = 23;

	lst->Insert(sam);

	sam = new sample;
	strcpy(sam->name, "ccc");
	sam->age = 12;

	lst->Insert(sam);


	CNode<sample*>* node;

	node = lst->GetmHead()->GetmNext();
	while (node)
	{
		cout << node->GetmData()->name << endl;
		cout << node->GetmData()->age << endl;
		node = node->GetmNext();
	}

	lst->Delete(sam);

	node = lst->GetmHead()->GetmNext();
	while (node)
	{
		cout << node->GetmData()->name << endl;
		cout << node->GetmData()->age << endl;
		node = node->GetmNext();
	}


	cout << endl << endl;

	CLinkedList <sample>* lst2 = new CLinkedList<sample>();
	sample sam2;
	strcpy(sam2.name, "kja");
	sam2.age = 33;

	lst2->Insert(sam2);

	CNode<sample>* node2;

	node2 = lst2->GetmHead()->GetmNext();

	while (node2)
	{
		cout << node2->GetmData().name << endl;
		cout << node2->GetmData().age << endl;
		node2 = node2->GetmNext();
	}
	
	lst2->Delete(sam2);

	node2 = lst2->GetmHead()->GetmNext();

	while (node2)
	{
		cout << node2->GetmData().name << endl;
		cout << node2->GetmData().age << endl;
		node2 = node2->GetmNext();		
	}

	delete lst;
	delete lst2;


	/*CLinkedList*  Intlst = new CLinkedList();

	Intlst->Insert(10);
	Intlst->Insert(20);
	Intlst->Insert(30);
	Intlst->Insert(40);

	CNode* node;

	node = Intlst->GetmHead()->GetmNext();

	while (node)
	{
		cout << node->GetmData() << endl;	
		node = node->GetmNext();
	}

	cout << endl;

	Intlst->Delete(20);

	node = Intlst->GetmHead()->GetmNext();

	while (node)
	{
		cout << node->GetmData() << endl;
		node = node->GetmNext();
	}

	delete Intlst;*/

	return 0;

}