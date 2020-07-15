#ifndef  _GLOBAL_H
#define  _GLOBAL_H
#include <windows.h>
#include <CommCtrl.h>
#include "resource.h"

#define GETWINDOWINST	CWindowFrame::GetInstance()

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

enum class Alignment
{
	Left = -1,
	Center,
	Right
};


#endif