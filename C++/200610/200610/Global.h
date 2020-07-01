#ifndef  GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAX_CHARACTER 5
#define CODE_WARRIOR 10
#define CODE_HEALER 20
#define CODE_ARCHOR 30
#define CODE_SORCERER 40

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
};


enum JOB
{
	NONE = -1,
	WARRIOR = 1,
	HEALER,
	ARCHER,
	SORCERER
};

enum CHAR_MENU
{
	HUM =1,
	ORC,
	ELF
};

enum MAIN_MENU 
{ 
	JOIN=1, 
	LOGIN, 
	EXIT
};

enum LOGIN_MENU
{
	DROP = 0,
	CREATE = 1,
	DESTROY,
	DISPLAY,
	ITEMBUY,
	ITEMSELL,
	ITEMCHANGE,
	STOREINFO,
	LOGOUT,
	
};
static void CinClear()
{
	if (cin.fail())
	{
		cin.clear();
		while (getchar() != '\n');
	}
}

#define MAKE_NO_COPY(CLASSNAME)                                             \
        private:                                                            \
               CLASSNAME(const CLASSNAME&){}                                \
               CLASSNAME& operator=(const CLASSNAME&);

// ½ÌÅ¬Åæ ÆÐÅÏ »ý¼º ¸ÅÅ©·Î
#define DECLARE_SINGLETONE(CLASSNAME)                                       \
        MAKE_NO_COPY(CLASSNAME)                                             \
        private:                                                            \
			   static CLASSNAME* mPthis;									\
        public:                                                             \
               static CLASSNAME* Create();									\
			   static CLASSNAME* GetInstance();								\
               static void Destroy();										 

// ½Ì±ÛÅæ ÆÐÅÏ ±¸Çö ¸ÅÅ©·Î

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

istream& operator>>(istream& i, MAIN_MENU& input);

istream& operator>>(istream& i, LOGIN_MENU& input);

istream& operator>>(istream& i, CHAR_MENU& input);
istream& operator>>(istream& i, JOB& input);


#endif // ! _GLOBAL_H
