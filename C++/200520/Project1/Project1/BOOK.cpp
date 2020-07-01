#include "BOOK.h"
#include "Global.h"

BOOK::BOOK()
{
	m_name = nullptr;
	memset(m_code, 0, sizeof(m_code) / sizeof(char));
	m_MaxCount = 0;
}
BOOK::BOOK(const char* p_name, int p_count)
{
	m_name = new char[strlen(p_name) + 1];
	strcpy_s(m_name, strlen(m_name), p_name);
	m_MaxCount = p_count;
	m_NowCount = m_MaxCount;
}

void BOOK::SetCode(int p_index)
{
	sprintf_s(m_code, "2017_%03d", p_index);
}
const char* BOOK::GetCode()
{
	return m_code;
}

//void BOOK::SetName(const char* p_name)
//{
//	strcpy_s(m_name, p_name);
//}
const char* BOOK::GetName()
{
	return m_name;
}

void BOOK::MinusCount()
{
	if (m_NowCount == 0)
		return;
	m_NowCount--;
}
void BOOK::PlusCount()
{
	if (m_NowCount == m_MaxCount)
		return;
	m_NowCount++;
}
int BOOK::GetInit()
{
	return m_NowCount;
}