#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include "BOOK.h"

class BookManager
{
private:
	BOOK* m_BookList[10];
	int m_BookCount; // ����Ʈ ���� å ����

	static BookManager* Instance;

	BookManager();
	~BookManager();
public:

	static void Create();
	static void Destroy();

	static BookManager* GetInstance();
	void Initialize();

	void Search();
	void RentBook();
	void ReturnBook();



};

#endif // !BOOKMANAGER_H


