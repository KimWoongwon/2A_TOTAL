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
	if (ID_RL_RED <= select && select <= ID_RW_10)
	{
		mSelectFigureMenu = RECTANGLE;
		if (ID_RL_RED <= select && select <= ID_RL_DEFAULT)
			mLineColor = select;
		if (ID_RW_DEFAULT <= select && select <= ID_RW_10)
			mLineWidth = select;
		if (ID_RA_RED <= select && select <= ID_RA_DEFAULT)
			mAreaColor = select;
	}
	else if (ID_CL_RED <= select && select <= ID_CW_10)
	{
		mSelectFigureMenu = CIRCLE;
		if (ID_CL_RED <= select && select <= ID_CL_DEFAULT)
			mLineColor = select;
		if (ID_CW_DEFAULT <= select && select <= ID_CW_10)
			mLineWidth = select;
		if (ID_CA_RED <= select && select <= ID_CA_DEFAULT)
			mAreaColor = select;
	}
	else if (ID_LL_RED <= select && select <= ID_LW_10)
	{
		mSelectFigureMenu = LINE;
		if (ID_LL_RED <= select && select <= ID_LL_DEFAULT)
			mLineColor = select;
		if (ID_LW_DEFAULT <= select && select <= ID_LW_10)
			mLineWidth = select;
	}
	else if (ID_FL_RED <= select)
	{
		mSelectFigureMenu = FREELINE;
		if (ID_FL_RED <= select && select <= ID_FL_DEFAULT)
			mLineColor = select;
		if (ID_FW_DEFAULT <= select && select <= ID_FW_10)
			mLineWidth = select;
	}
		
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
		draw->SetAreaRGB(mAreaColor);
		break;
	case RECTANGLE:
		draw = CDragRectangleDrawing::GetInstance();
		draw->SetAreaRGB(mAreaColor);
		break;
	}
	draw->SetPenRGB(mLineColor);
	draw->SetPenSize(mLineWidth);
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

