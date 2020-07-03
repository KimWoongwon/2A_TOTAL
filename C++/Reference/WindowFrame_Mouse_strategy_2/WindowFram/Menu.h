#ifndef _CMENUCLASS_H
#define _CMENUCLASS_H

#include "Global.h"
#include "DragDrawing.h"
#include "PenAttribute.h"
#include "BrushAttribute.h"
#include "Mouse.h"

class CMenu
{
protected:

	HMENU					mMenuHandle;	

public:

	CMenu()
	{	
		mMenuHandle = nullptr;
	}

	virtual ~CMenu()
	{
	
	}	
	
	HMENU		GetMenuHandle() const 
	{
		return mMenuHandle;
	}


	virtual void SetMenuHandle(HMENU _handle) = 0;
	virtual void ProcessCommandMeg(WPARAM)=0;		
	virtual HMENU SelectMenuHandle(WPARAM)=0;
	virtual HMENU GetCurrentHandle() const=0;
	
};

#endif