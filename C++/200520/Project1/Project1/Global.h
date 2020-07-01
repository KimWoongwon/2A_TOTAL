#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>

using namespace std;

enum MAIN_MENU
{
	JOIN = 1,
	LOGIN,
	EXIT
};

enum LOGIN_MENU
{
	SEARCH = 1,
	RENT,
	RETURN,
	LOGOUT,
	DROP
};

istream& operator>>(istream& i, MAIN_MENU& input);

istream& operator>>(istream& i, LOGIN_MENU& input);
#endif // !GLOBAL_H

