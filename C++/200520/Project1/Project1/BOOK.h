#ifndef BOOK_H
#define BOOK_H
class BOOK
{
private:
	char* m_name;
	char m_code[20];
	int m_MaxCount; // å �뿩���� ����
	int m_NowCount; // ���� å�� ����
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




