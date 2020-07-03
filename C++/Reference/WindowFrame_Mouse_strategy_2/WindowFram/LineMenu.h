#ifndef _CLINEMENU_H
#define _CLINEMENU_H

#include "Global.h"
#include "Menu.h"
#include "DragLineDrawing.h"
#include "PenAttribute.h"

class CLineMenu:public CMenu
{
	HMENU		mhCurrMenu;		
	
public:	

	CLineMenu()
	{
		mhCurrMenu = nullptr;		
	}

	~CLineMenu()
	{
	
	}
	void SetMenuHandle(HMENU _handle)
	{
		CMenu::mMenuHandle = _handle;

		mhCurrMenu = GetSubMenu(GetMenuHandle(), LINE);


		for (int i = 0; i < 3; i++)
		{
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, i), 0, 2, 0, MF_BYPOSITION);
		}

	}
	void ProcessCommandMeg(WPARAM _wparam)
	{
		COLOR color = COLOR::NODATA;
		PENSIZE size = PENSIZE::NODATA;

		CMouse::GetInstance()->SetDrawing(CDragLineDrawing::GetInstance());

		switch(LOWORD(_wparam))
		{			
	
		case ID_LINE_PEN_BLUE:
		case ID_LINE_PEN_RED:
		case ID_LINE_PEN_GREEN:

			color = (COLOR)(LOWORD(_wparam) - ID_LINE_PEN_RED);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);		
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 0),0,2, LOWORD(_wparam)-ID_LINE_PEN_RED, MF_BYPOSITION);
			CMouse::GetInstance()->SetAttribute(color, size);

			break;
		case ID_LINE_PEN_1PT:
		case ID_LINE_PEN_3PT:
		case ID_LINE_PEN_5PT:
			
			size = (PENSIZE)((LOWORD(_wparam) - ID_LINE_PEN_1PT) * 2 + 1);
			//CheckMenuItem(GetMenuHandle(), LOWORD(_wparam), MF_BYCOMMAND | MF_CHECKED);	
			CheckMenuRadioItem(GetSubMenu(mhCurrMenu, 2),0,2, LOWORD(_wparam)-ID_LINE_PEN_1PT, MF_BYPOSITION);
			CMouse::GetInstance()->SetAttribute(color, size);

			break;
		}

		
	}

	HMENU SelectMenuHandle(WPARAM _wparam)
	{
		switch(LOWORD(_wparam))
		{			
	
		case ID_LINE_PEN_BLUE:
		case ID_LINE_PEN_RED:
		case ID_LINE_PEN_GREEN:

		case ID_LINE_PEN_1PT:
		case ID_LINE_PEN_3PT:
		case ID_LINE_PEN_5PT:

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