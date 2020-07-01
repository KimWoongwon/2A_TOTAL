#pragma once
#include <Windows.h>
class Mouse
{
private:
	static Mouse* Instance;

	POINT NowPos;
	POINT PrePos;
	HWND handle;
	bool isClicked;
	bool resetFlag;

	Mouse() {}
	~Mouse() {}
public:
	static void Create();
	static void Destory();
	static Mouse* GetInstance();

	void Initalize();
	void SetMousePos(LPARAM, HWND);
	void PosReset();
	void SetClicked(bool);

	POINT GetNowPos();
	POINT GetPrePos();
	bool GetClicked();
	

};

