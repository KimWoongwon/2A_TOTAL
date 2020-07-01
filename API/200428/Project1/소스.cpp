#include <windows.h>
#include <stdlib.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("MyComboBox");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&Message, NULL, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}

#define ID_EDIT_1 100
#define ID_EDIT_2 101
HWND hEdit_1;
HWND hEdit_2;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    static COLORREF color = RGB(255, 255, 255);
    HBRUSH newBrush;
    HBRUSH oldBrush;
    static TCHAR str_1[128];
    static TCHAR str_2[128];
    switch (iMessage) {
    case WM_CREATE:
        hEdit_1 = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 10, 10, 200, 25, hWnd, (HMENU)ID_EDIT_1, g_hInst, NULL);
        hEdit_2 = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 250, 10, 200, 25, hWnd, (HMENU)ID_EDIT_2, g_hInst, NULL);
        return 0;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_EDIT_1:
            if(HIWORD(wParam) == EN_CHANGE)
                GetWindowText(hEdit_1, str_1, 128);
            break;
        case ID_EDIT_2:
            if (HIWORD(wParam) == EN_CHANGE)
                GetWindowText(hEdit_2, str_2, 128);
            if (!strcmp(str_2, "R"))
                color = RGB(255, 0, 0);
            else if (!strcmp(str_2, "G"))
                color = RGB(0, 255, 0);
            else if (!strcmp(str_2, "B"))
                color = RGB(0, 0, 255);
            break;
        }
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        newBrush = CreateSolidBrush(color);
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        if (!strcmp(str_1, "¿ø"))
        {
            Ellipse(hdc, 100, 100, 250, 250);
        }
        else if(!strcmp(str_1, "³×¸ð"))
        {
            Rectangle(hdc, 100, 100, 250, 250 );
        }
        SelectObject(hdc, oldBrush);
        DeleteObject(newBrush);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_LBUTTONDOWN:
        SetFocus(hWnd);
        InvalidateRect(hWnd, NULL, TRUE);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
