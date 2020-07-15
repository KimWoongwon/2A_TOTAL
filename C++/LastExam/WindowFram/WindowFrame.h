#ifndef _CWINDOWFRAME_H
#define _CWINDOWFRAME_H
#include "Global.h"
#include "Controls.h"
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

	CPushButton*			mButton[5];
	

	CWindowFrame()
	{
		mBackBit = nullptr;
		IdEdit = nullptr;
		PwEdit = nullptr;
		Text01 = nullptr;
		Text02 = nullptr;

		CharacterList = nullptr;
		for (int i = 0; i < 5; i++)
			mButton[i] = nullptr;

	}
	~CWindowFrame()	
	{
		if (mBackBit != nullptr)
			delete mBackBit;

		if (IdEdit != nullptr)
			delete IdEdit;

		if (PwEdit != nullptr)
			delete PwEdit;

		if (Text01 != nullptr)
			delete Text01;

		if (Text02 != nullptr)
			delete Text02;

		if (CharacterList != nullptr)
			delete CharacterList;

		for (int i = 0; i < 5; i++)
		{
			if (mButton[i] != nullptr)
				delete mButton[i];
		}
	}

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
	HWND			GethWnd();
	HINSTANCE		GetInstanceHandle();
};
#endif
