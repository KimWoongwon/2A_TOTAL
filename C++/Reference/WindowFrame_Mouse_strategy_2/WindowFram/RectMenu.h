#ifndef _CRECTMENU_H
#define _CRECTMENU_H
#include "Global.h"
#include "Menu.h"
#include "DragRectangleDrawing.h"
#include "BrushAttribute.h"
#include "PenAttribute.h"

class CRectMenu:public CMenu
{
	HMENU		mhCurrMenu;	

public:	

	CRectMenu()
	{
		mhCurrMenu = nullptr;
	}

	~CRectMenu()
	{
	
	}

	void SetMenuHandle(HMENU _handle)
	{
		CMenu::mMenuHandle = _handle;

		mhCurrMenu = GetSubMenu(GetMenuHandle(), RECTANGLE);


		for (int i = 0; i < 3; i++)
		{
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, i), 0, 2, 0, MF_BYPOSITION);
		}

	}

	void ProcessCommandMeg(WPARAM _wparam)
	{
		COLOR color= COLOR::NODATA;
		PENSIZE size = PENSIZE::NODATA;

		CMouse::GetInstance()->SetDrawing(CDragRectangleDrawing::GetInstance());

		switch(LOWORD(_wparam))
		{			
		case ID_RECT_BRUSH_BLUE:						
		case ID_RECT_BRUSH_GREEN:
		case ID_RECT_BRUSH_RED:
			
			color=(COLOR)(LOWORD(_wparam)-ID_RECT_BRUSH_RED);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);	
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 1),0,2, LOWORD(_wparam)-ID_RECT_BRUSH_RED, MF_BYPOSITION);

			CMouse::GetInstance()->SetAttribute(color, PENSIZE::NO_PEN);
			break;

		case ID_RECT_PEN_BLUE:
		case ID_RECT_PEN_RED:
		case ID_RECT_PEN_GREEN:

			color =(COLOR)(LOWORD(_wparam)-ID_RECT_PEN_RED);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);		
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 0),0,2, LOWORD(_wparam)-ID_RECT_PEN_RED, MF_BYPOSITION);
			CMouse::GetInstance()->SetAttribute(color, size);
			break;
		case ID_RECT_PEN_1PT:
		case ID_RECT_PEN_3PT:
		case ID_RECT_PEN_5PT:
			
			size=(PENSIZE)((LOWORD(_wparam)-ID_RECT_PEN_1PT)*2+1);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);	
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 2),0,2, LOWORD(_wparam)-ID_RECT_PEN_1PT, MF_BYPOSITION);

			CMouse::GetInstance()->SetAttribute(color, size);
			break;
		}		
	}
	
	HMENU SelectMenuHandle(WPARAM _wparam)
	{
		switch(LOWORD(_wparam))
		{			
		case ID_RECT_BRUSH_BLUE:						
		case ID_RECT_BRUSH_GREEN:
		case ID_RECT_BRUSH_RED:
			
		case ID_RECT_PEN_BLUE:
		case ID_RECT_PEN_RED:
		case ID_RECT_PEN_GREEN:
			
		case ID_RECT_PEN_1PT:
		case ID_RECT_PEN_3PT:
		case ID_RECT_PEN_5PT:
			
			return mhCurrMenu;			
		}

		return NULL;
	}

	HMENU GetCurrentHandle() const {return mhCurrMenu;}

};

#endif