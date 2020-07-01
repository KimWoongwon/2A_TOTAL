#pragma once
#include <windows.h>
class WindowFrame
{
private:
	static WindowFrame* Instance;

	HINSTANCE g_hInst;
	HWND hWndMain;
	LPCTSTR lpszClass = TEXT("±è¿õ¿ø_16032020");

	WindowFrame() {}
	~WindowFrame() {}
public:
	static void Create();
	static void Destroy();
	static WindowFrame* GetInstance();
	
	void Initalize(HINSTANCE , HINSTANCE , LPSTR , int );
	int Run();


	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};

