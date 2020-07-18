#ifndef _CWINDOWFRAME_H
#define _CWINDOWFRAME_H
#include "../Global.h"
#include "../Controls.h"
#include "../Character/Character.h"

// 윈도우 프레임 객체 
class CWindowFrame
{
	static CWindowFrame*	mPthis;	

	HWND					mhWnd;					// 메인 윈도우의 핸들값
	HINSTANCE				mhInstance;				// 메인 윈도우의 인스턴스 값

	CStaticText*			Text01;					// 윈도우컨트롤 객체들
	CStaticText*			Text02;					// 정보 표시를 위한 StaticText

	CEditControl*			IdEdit;					// ID나 PW 혹은 캐릭터 닉네임, 아이템 이름 등을 받기 위한
	CEditControl*			PwEdit;					// 에디트 컨트롤

	CListBox*				CharacterList;			// 유저의 캐릭터 목록을 보여주는 리스트뷰
	CListBox*				ShowInvantory;			// 캐릭터의 아이템 목록을 보여주는 리스트뷰

	CGroupBox*				Region;					// 라디오 박스 보기 편하게 묶어주는 그룹박스
	CGroupBox*				Class;

	CRadioButton*			RegionSelect[3];		// 종족, 직업 선택을 위한 라디오 버튼
	CRadioButton*			ClassSelect[3];

	CPushButton*			mButton[5];				// 각종 사용자의 선택을 위한 푸쉬버튼

	CWindowFrame();
	~CWindowFrame();

public:
	static CWindowFrame* Create(HINSTANCE _hinstance);
	static CWindowFrame* GetInstance();
	static void Destroy();

	// 윈도우 콜백 함수
	static LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam);

	void Run(MSG);
	void Initialize();
	void BuildWindow();

	// 에디트 컨트롤, 스테틱 텍스트를 계속 돌려가며 사용하기 위해선 안의 텍스트를 삭제해줄 필요가 있다.
	void ResetText();						
	// 모든 컨트롤 보이기 비활성화 함수
	void ResetVisable();

	// 각종 윈도우 컨트롤 읽기 접근자 매개변수로 해당 ID를 받아서 반환해준다.
	CPushButton*	GetButton(int);
	CEditControl*	GetEditControl(int);
	CStaticText*	GetStaticText(int);
	CListBox*		GetListBox(int);
	CRadioButton*	GetRadioButton(int);
	CGroupBox*		GetGroupBox(int);

	// 윈도우 핸들 읽기 접근자
	HWND			GethWnd();
	// 윈도우 인스턴스 읽기 접근자
	HINSTANCE		GetInstanceHandle();

	// 리스트뷰에 캐릭터의 정보 출력해주는 함수
	void InsertCharData(Character*);
	// 리스트뷰에 캐릭터의 아이템 정보 모두 출력해주는 함수
	void InsertCharItemData(Character*);
	// 리스트뷰에 아이템상점의 아이템 정보 모두 출력해주는 함수
	void InsertStoreData(CLASS, ITEMTYPE);

	// 리스트뷰에 출력된 내용 초기화 함수
	void RemoveAllData(int);
	void MakeColumn(int); // 컬럼 생성 함수
	
};
#endif
