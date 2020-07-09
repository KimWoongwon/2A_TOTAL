#include "WindowFrame.h"

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
{

	CWindowFrame::Create(hInstance);
	CWindowFrame::GetInstance()->Initialize();

	CWindowFrame::GetInstance()->Run();
	CWindowFrame::Destroy();

	return 0;
}