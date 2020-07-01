#ifndef _CMENU_H
#define _CMENU_H
#include "Global.h"
#include "DragCircleDrawing.h"
#include "DragFreeLineDrawing.h"
#include "DragRectangleDrawing.h"
#include "DragLineDrawing.h"

class CMenu
{
	HWND		mHmainWnd;
	HMENU		mHmenu;	
	int			mMenuId;

	int			mSelectFigureMenu;

	int			mLineColor;
	int			mLineWidth;

	int			mAreaColor;
	

public:
	CMenu(){}
	~CMenu(){}

	void	MenuInitialize(int _id, HWND _hwnd);

	void	ProcessCommandMeg(WPARAM _wparam);
	HMENU	GetMenuHandle() const{return mHmenu;}
	int		GetSelectFigureMenu() const{return mSelectFigureMenu;}
	int		GetMenuId()const {return mMenuId;}

	void	SetMenuHandle(HMENU _hmenu);
	void	SetSelectMenu(int _menu);
	void	SetMenuId(int _id){mMenuId=_id;}
	CDragDrawing* SelectedDragDrawing();
	

};

#endif