#ifndef _CCIRCLEMENU_H
#define _CCIRCLEMENU_H

#include "Global.h"
#include "Menu.h"
#include "DragCircleDrawing.h"
#include "BrushAttribute.h"
#include "PenAttribute.h"

class CCircleMenu:public CMenu
{
	HMENU		mhCurrMenu;	

public:	

	CCircleMenu() 
	{
		mhCurrMenu = nullptr;
	}

	~CCircleMenu()
	{		
	}

	void SetMenuHandle(HMENU _handle)
	{
		CMenu::mMenuHandle = _handle;

		mhCurrMenu = GetSubMenu(GetMenuHandle(), CIRCLE);


		for (int i = 0; i < 3; i++)
		{
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, i), 0, 2, 0, MF_BYPOSITION);
		}

	}

	void ProcessCommandMeg(WPARAM _wparam)
	{
		COLOR color = COLOR::NODATA;
		PENSIZE size = PENSIZE::NODATA;

		CMouse::GetInstance()->SetDrawing(CDragCircleDrawing::GetInstance());

		switch(LOWORD(_wparam))
		{			
		case ID_CIR_BRUSH_BLUE:						
		case ID_CIR_BRUSH_GREEN:
		case ID_CIR_BRUSH_RED:
			
			color = (COLOR)(LOWORD(_wparam) - ID_CIR_BRUSH_RED);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);	
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 1),0,2, LOWORD(_wparam)-ID_CIR_BRUSH_RED, MF_BYPOSITION);			
			CMouse::GetInstance()->SetAttribute(color, PENSIZE::NO_PEN);

			break;

		case ID_CIR_PEN_BLUE:
		case ID_CIR_PEN_RED:
		case ID_CIR_PEN_GREEN:

			color = (COLOR)(LOWORD(_wparam) - ID_CIR_PEN_RED);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);		
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 0),0,2, LOWORD(_wparam)-ID_CIR_PEN_RED, MF_BYPOSITION);
			CMouse::GetInstance()->SetAttribute(color, size);

			break;
		case ID_CIR_PEN_1PT:
		case ID_CIR_PEN_3PT:
		case ID_CIR_PEN_5PT:
			
			size = (PENSIZE)((LOWORD(_wparam) - ID_CIR_PEN_1PT) * 2 + 1);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);	
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 2),0,2, LOWORD(_wparam)-ID_CIR_PEN_1PT, MF_BYPOSITION);
			CMouse::GetInstance()->SetAttribute(color, size);
			break;
		}	

		
	}	

	HMENU SelectMenuHandle(WPARAM _wparam)
	{
		switch(LOWORD(_wparam))
		{			
		case ID_CIR_BRUSH_BLUE:						
		case ID_CIR_BRUSH_GREEN:
		case ID_CIR_BRUSH_RED:			
		
		case ID_CIR_PEN_BLUE:
		case ID_CIR_PEN_RED:
		case ID_CIR_PEN_GREEN:
			
		case ID_CIR_PEN_1PT:
		case ID_CIR_PEN_3PT:
		case ID_CIR_PEN_5PT:
			
			return mhCurrMenu;
			
		}

		return NULL;
	}

	HMENU GetCurrentHandle() const {return mhCurrMenu;}
};

#endif