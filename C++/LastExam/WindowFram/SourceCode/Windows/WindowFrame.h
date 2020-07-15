#ifndef _CWINDOWFRAME_H
#define _CWINDOWFRAME_H
#include "../Global.h"
#include "../Controls.h"
#include "BackBit.h"

class CWindowFrame
{
	static CWindowFrame*	mPthis;

	HWND					mhWnd;	
	HINSTANCE				mhInstance;	
	
	CBackBit*				mBackBit;

	CStaticText*			Text01;
	CStaticText*			Text02;

	CEditControl*			IdEdit;
	CEditControl*			PwEdit;

	CListBox*				CharacterList;
	CGroupBox*				Region;
	CGroupBox*				Class;

	CRadioButton*			RegionSelect[3];
	CRadioButton*			ClassSelect[3];
	CPushButton*			mButton[5];
	

	CWindowFrame();
	~CWindowFrame();

public:
	static CWindowFrame* Create(HINSTANCE _hinstance);
	static CWindowFrame* GetInstance();
	static void Destroy();

	static LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam);

	void Run(MSG);
	void Initialize();
	void BuildWindow();

	void ResetText();
	CBackBit*		GetBackbit();
	CPushButton*	GetButton(int);
	CEditControl*	GetEditControl(int);
	CStaticText*	GetStaticText(int);
	CListBox*		GetListBox(int);
	CRadioButton*	GetRadioButton(int);
	CGroupBox*		GetGroupBox(int);

	HWND			GethWnd();
	HINSTANCE		GetInstanceHandle();
};
#endif
