#ifndef _CWINDOWFRAME_H
#define _CWINDOWFRAME_H
#include "../Global.h"
#include "../Controls.h"
#include "../Character/Character.h"

// ������ ������ ��ü 
class CWindowFrame
{
	static CWindowFrame*	mPthis;	

	HWND					mhWnd;					// ���� �������� �ڵ鰪
	HINSTANCE				mhInstance;				// ���� �������� �ν��Ͻ� ��

	CStaticText*			Text01;					// ��������Ʈ�� ��ü��
	CStaticText*			Text02;					// ���� ǥ�ø� ���� StaticText

	CEditControl*			IdEdit;					// ID�� PW Ȥ�� ĳ���� �г���, ������ �̸� ���� �ޱ� ����
	CEditControl*			PwEdit;					// ����Ʈ ��Ʈ��

	CListBox*				CharacterList;			// ������ ĳ���� ����� �����ִ� ����Ʈ��
	CListBox*				ShowInvantory;			// ĳ������ ������ ����� �����ִ� ����Ʈ��

	CGroupBox*				Region;					// ���� �ڽ� ���� ���ϰ� �����ִ� �׷�ڽ�
	CGroupBox*				Class;

	CRadioButton*			RegionSelect[3];		// ����, ���� ������ ���� ���� ��ư
	CRadioButton*			ClassSelect[3];

	CPushButton*			mButton[5];				// ���� ������� ������ ���� Ǫ����ư

	CWindowFrame();
	~CWindowFrame();

public:
	static CWindowFrame* Create(HINSTANCE _hinstance);
	static CWindowFrame* GetInstance();
	static void Destroy();

	// ������ �ݹ� �Լ�
	static LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam);

	void Run(MSG);
	void Initialize();
	void BuildWindow();

	// ����Ʈ ��Ʈ��, ����ƽ �ؽ�Ʈ�� ��� �������� ����ϱ� ���ؼ� ���� �ؽ�Ʈ�� �������� �ʿ䰡 �ִ�.
	void ResetText();						
	// ��� ��Ʈ�� ���̱� ��Ȱ��ȭ �Լ�
	void ResetVisable();

	// ���� ������ ��Ʈ�� �б� ������ �Ű������� �ش� ID�� �޾Ƽ� ��ȯ���ش�.
	CPushButton*	GetButton(int);
	CEditControl*	GetEditControl(int);
	CStaticText*	GetStaticText(int);
	CListBox*		GetListBox(int);
	CRadioButton*	GetRadioButton(int);
	CGroupBox*		GetGroupBox(int);

	// ������ �ڵ� �б� ������
	HWND			GethWnd();
	// ������ �ν��Ͻ� �б� ������
	HINSTANCE		GetInstanceHandle();

	// ����Ʈ�信 ĳ������ ���� ������ִ� �Լ�
	void InsertCharData(Character*);
	// ����Ʈ�信 ĳ������ ������ ���� ��� ������ִ� �Լ�
	void InsertCharItemData(Character*);
	// ����Ʈ�信 �����ۻ����� ������ ���� ��� ������ִ� �Լ�
	void InsertStoreData(CLASS, ITEMTYPE);

	// ����Ʈ�信 ��µ� ���� �ʱ�ȭ �Լ�
	void RemoveAllData(int);
	void MakeColumn(int); // �÷� ���� �Լ�
	
};
#endif
