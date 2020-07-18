#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <CommCtrl.h>
using namespace std;

// 싱글톤 패턴의 인스턴스반환하는 함수를 메크로로 정의했습니다.
#define GetInst(CLASSNAME)	CLASSNAME::GetInstance()


#pragma region Controls_ID
#define ID_BUTTON1		1
#define ID_BUTTON2		2
#define ID_BUTTON3		3
#define ID_BUTTON4		4
#define ID_BUTTON5		5

#define ID_EDIT1		11
#define ID_EDIT2		12

#define ID_STATIC1		21
#define ID_STATIC2		22

#define ID_LIST1		31
#define ID_LIST2		32

#define ID_RADIO1		41
#define ID_RADIO2		42
#define ID_RADIO3		43
#define ID_RADIO4		44
#define ID_RADIO5		45
#define ID_RADIO6		46

#define ID_GROUP1		51
#define ID_GROUP2		52
#pragma endregion	윈도우 컨트롤의 ID값입니다.

#pragma region EnumClasses
// staticText 윈도우의 텍스트 정렬값
enum class Alignment	
{
	Left = -1,
	Center,
	Right
};
// 직업의 고유값
enum class CLASS
{
	NONE = -1,
	WARRIOR = 1,
	ARCHER,
	SORCERER
};
// 종족의 고유값
enum class REGION
{
	HUM = 1,
	ORC,
	ELF
};
// 아이템 타입의 고유값
enum class ITEMTYPE
{
	NONE = 0,
	WEAPONE,
	ARMOR,
	ACCESSORY
};
// 로그인 시스템의 state 고유값
enum class STATE
{
	TITLE_STATE = 0,
	SIGNUP_STATE,
	MENU_STATE,
	STORE_STATE,
	CREATE_STATE,
	DELETE_STATE,
	BUY_STATE,
	SELL_STATE,
	SHOW_STATE
};
#pragma endregion	각종 고유값을 enum class 형태로 구현했습니다.

// 스텟 구조체입니다.
struct STATUS	
{
	int Hp;
	int Mp;
	int ATK;
	int DEF;
	STATUS(int pHp, int pMp, int pATK, int pDEF)
	{
		Hp = pHp;
		Mp = pMp;
		ATK = pATK;
		DEF = pDEF;
	}
	STATUS(STATUS& _status)
	{
		Hp = _status.Hp;
		Mp = _status.Mp;
		ATK = _status.ATK;
		DEF = _status.DEF;
	}
};

#define MAKE_NO_COPY(CLASSNAME)                                             \
        private:                                                            \
               CLASSNAME(const CLASSNAME&){}                                \
               CLASSNAME& operator=(const CLASSNAME&);

// 싱클톤 패턴 생성 매크로
#define DECLARE_SINGLETONE(CLASSNAME)                                       \
        MAKE_NO_COPY(CLASSNAME)                                             \
        private:                                                            \
			   static CLASSNAME* mPthis;									\
        public:                                                             \
               static CLASSNAME* Create();									\
			   static CLASSNAME* GetInstance();								\
               static void Destroy();										 

// 싱글톤 패턴 구현 매크로

#define IMPLEMENT_SINGLETON(CLASSNAME)                              \
               CLASSNAME* CLASSNAME::mPthis= NULL;					\
                                                                    \
               CLASSNAME* CLASSNAME::Create()						\
			   {													\
                       if(mPthis == NULL)							\
						{											\
                              mPthis=new CLASSNAME();				\
						}											\
                        return mPthis;								\
               }                                                    \
               CLASSNAME* CLASSNAME::GetInstance()					\
               {                                                    \
                    return mPthis;									\
               }													\
			   void CLASSNAME::Destroy()							\
               {													\
					if(mPthis) delete mPthis;						\
				}		

