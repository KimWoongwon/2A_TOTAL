#ifndef _CFREELINEMENU_H
#define _CFREELINEMENU_H

#include "Global.h"
#include "Menu.h"
#include "DragFreeLineDrawing.h"
#include "PenAttribute.h"

class CFreeLineMenu:public CMenu
{
	HMENU		mhCurrMenu;		

public:	

	CFreeLineMenu()
	{
		mhCurrMenu = nullptr;
		
	}
	~CFreeLineMenu()
	{
		
	}

	void SetMenuHandle(HMENU _handle)
	{
		CMenu::mMenuHandle = _handle;

		mhCurrMenu = GetSubMenu(GetMenuHandle(), FREELINE);


		for (int i = 0; i < 3; i++)
		{
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, i), 0, 2, 0, MF_BYPOSITION);
		}

	}
	void ProcessCommandMeg(WPARAM _wparam)
	{
		COLOR color = COLOR::NODATA;
		PENSIZE size = PENSIZE::NODATA;

		CMouse::GetInstance()->SetDrawing(CDragFreeLineDrawing::GetInstance());

		switch(LOWORD(_wparam))
		{			
	
		case ID_FLINE_PEN_BLUE:
		case ID_FLINE_PEN_RED:
		case ID_FLINE_PEN_GREEN:

			color = (COLOR)(LOWORD(_wparam) - ID_FLINE_PEN_RED);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);		
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 0),0,2, LOWORD(_wparam)-ID_FLINE_PEN_RED, MF_BYPOSITION);

			CMouse::GetInstance()->SetAttribute(color, size);

			break;
		case ID_FLINE_PEN_1PT:
		case ID_FLINE_PEN_3PT:
		case ID_FLINE_PEN_5PT:
			
			size=(PENSIZE)((LOWORD(_wparam) - ID_FLINE_PEN_1PT) * 2 + 1);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);	
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 2),0,2, LOWORD(_wparam)-ID_FLINE_PEN_1PT, MF_BYPOSITION);
			CMouse::GetInstance()->SetAttribute(color, size);
			break;
		}	
			
	}
	
	HMENU SelectMenuHandle(WPARAM _wparam)
	{
		switch(LOWORD(_wparam))
		{			
	
		case ID_FLINE_PEN_BLUE:
		case ID_FLINE_PEN_RED:
		case ID_FLINE_PEN_GREEN:

		case ID_FLINE_PEN_1PT:
		case ID_FLINE_PEN_3PT:
		case ID_FLINE_PEN_5PT:

			return mhCurrMenu;
		}

		return NULL;
	}

	HMENU GetCurrentHandle() const 
	{
		return mhCurrMenu;
	}

};

#endif