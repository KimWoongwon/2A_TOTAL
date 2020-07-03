#ifndef _CATTRIBUTE_SELECT_H
#define _CATTRIBUTE_SELECT_H
#include "Global.h"

class CAttribute
{	

public:
	CAttribute(){}
	virtual ~CAttribute(){}

	

	virtual void SelectAttribute(HDC _hdc)=0;
	virtual void ReleaseAttribute(HDC _hdc)=0;
};

#endif