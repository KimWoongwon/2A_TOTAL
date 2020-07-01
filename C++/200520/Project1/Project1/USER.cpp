#include "USER.h"

USER::USER(const char* p_id, const char* p_pw)
{
	HaveCode = new CLinkedList<char*>();
	strcpy_s(m_ID, p_id);
	strcpy_s(m_PW, p_pw);
	m_login = false;
}

USER::~USER()
{
	if (HaveCode != nullptr)
	{
		delete HaveCode;
		HaveCode = nullptr;
	}
	
}

const char* USER::GetID()
{
	return m_ID;
}

const char* USER::GetPW()
{
	return m_PW;
}

bool USER::GetLoginState()
{
	return m_login;
}

void USER::SetID(const char* _id)
{
	strcpy_s(m_ID, _id);
}

void USER::SetPW(const char* _pw)
{
	strcpy_s(m_PW, _pw);
}

void USER::SetLogin()
{
	m_login = true;
}

void USER::SetLogout()
{
	m_login = false;
}
void USER::InsertItem(const char* p_book, int p_index)
{
	char* temp = new char[strlen(p_book) + 1];
	strcpy_s(temp,strlen(temp), p_book);
	for (int i = 0; i < p_index; i++)
	{
		HaveCode->Insert(temp);
	}
}
void USER::RemoveItem(const char* p_book, int p_index)
{
	char* temp = new char[strlen(p_book) + 1];
	strcpy_s(temp, strlen(temp), p_book);
	for (int i = 0; i < p_index; i++)
	{
		HaveCode->Delete(temp);
	}
}