#include "WindowFrame.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	WindowFrame::Create();
	WindowFrame::GetInstance()->Initalize(hInstance, hPrevInstance, lpszCmdParam, nCmdShow);
	WindowFrame::GetInstance()->Run();
	WindowFrame::Destroy();
}
