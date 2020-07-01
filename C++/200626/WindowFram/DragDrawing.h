 #pragma once
#include "Global.h"

class DragDrawing
{
private:
	static DragDrawing* Instance;

	HWND hWnd;
	POINT OldPos;
	int Id;

	DragDrawing();
	~DragDrawing();
public:
	static void Create();
	static void Initialize(HWND);
	static void Destory();
	static DragDrawing* GetInstance();

	void SetHWND(HWND);
	void SetOldPos(LPARAM);
	void SetID(int);


	HWND GetHWND();
	int GetID();

	void DrawObject(HDC);

	
};

