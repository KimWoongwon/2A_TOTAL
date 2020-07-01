#ifndef BOOK_H
#define BOOK_H
class BOOK
{
private:
	char* m_name;
	char m_code[20];
	int m_MaxCount; // 책 대여가능 갯수
	int m_NowCount; // 현재 책의 갯수
public:
	BOOK();
	BOOK(const char*, int);

	void SetCode(int);
	const char* GetCode();

	//void SetName(const char*);
	const char* GetName();

	void MinusCount();
	void PlusCount();
	int GetInit();

};
#endif // !BOOK_H




