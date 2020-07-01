#include "Menu.h"

void CMenu::MenuInitialize(int _id, HWND _hwnd)
{
	mHmainWnd = _hwnd;
	mHmenu = GetMenu(mHmainWnd);
	mMenuId=_id;	
}
void CMenu::ProcessCommandMeg(WPARAM _wparam)
{
	int select = LOWORD(_wparam);
	if(40000 <= select && 40100 > select)
		mSelectFigureMenu = RECTANGLE;
	else if(40100 <= select && 40200 > select)
		mSelectFigureMenu = CIRCLE;
	else if(40200 <= select && 40300 > select)
		mSelectFigureMenu = LINE;
	else if(40300 <= select )
		mSelectFigureMenu = FREELINE;
	/*switch(LOWORD(_wparam))
	{
	case ID_FREELINE:
		mSelectFigureMenu=FREELINE;		
		break;
	case ID_LINE:
		mSelectFigureMenu =LINE;
		break;
	case ID_CIRCLE:
		mSelectFigureMenu =CIRCLE;
		break;
	case ID_RECTANGLE:
		mSelectFigureMenu =RECTANGLE;
		break;
	case ID_EXIT:
		PostQuitMessage(0);
		break;
	}*/

	CMouse::GetInstance()->SetDrawing(SelectedDragDrawing());
}

CDragDrawing* CMenu::SelectedDragDrawing()
{
	CDragDrawing* draw = nullptr;

	switch (mSelectFigureMenu)
	{
	case FREELINE:
		draw = CDragFreeLineDrawing::GetInstance();
		break;
	case LINE:
		draw = CDragLineDrawing::GetInstance();
		break;
	case CIRCLE:
		draw = CDragCircleDrawing::GetInstance();
		break;
	case RECTANGLE:
		draw = CDragRectangleDrawing::GetInstance();
		break;
	}

	return draw;
}

void CMenu::SetMenuHandle(HMENU _hmenu)
{
	mHmenu=_hmenu;
}

void CMenu::SetSelectMenu(int _menu)
{
	mSelectFigureMenu=_menu;
}

