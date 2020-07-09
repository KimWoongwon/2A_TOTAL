#ifndef  _GLOBAL_H
#define  _GLOBAL_H
#include <windows.h>
#include "resource.h"
enum 
{
	NOTHING=-1, 
	RECTANGLE, 
	CIRCLE,LINE, 
	FREELINE 
};
enum 
{
	NORMAL, 
	REVERSE
};

enum class COLOR
{
	NODATA=-1, 
	RED, 
	BLUE, 
	GREEN
};
enum class PENSIZE
{
	NODATA=-1, 
	NO_PEN, 
	POINT1=1, 
	POINT3=3, 
	POINT4=5
};
#endif