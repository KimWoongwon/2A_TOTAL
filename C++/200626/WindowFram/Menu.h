#pragma once
#include "Global.h"
class Menu
{
private:
	static Menu* Instance;

	HWND hWnd;
	/*int MyID;*/

	int SelectID;

	Menu();
	~Menu();
public:
	static void Create();
	static void Initialize(HWND);
	static void Destory();
	static Menu* GetInstance();

	/*void SetMyID();*/
	void SetSelectID(WPARAM);
	void SetHWND(HWND);

	/*int GetMyID();*/
	int GetSelectID();
	HWND GetHWND();
	
};

