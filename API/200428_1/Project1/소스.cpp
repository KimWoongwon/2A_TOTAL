#include <windows.h>

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

enum {ID_START = 100, ID_STOP, ID_END, ID_UP, ID_DOWN, ID_DRAW};
HWND w1,w2,w3,w4,w5,w6;
#define SIZE 30
#define Sx 20
#define Sy 40

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    static POINT pos;
    static BOOL FLAGY = FALSE;
    static RECT rt;
    static int speed = 100;
   
    
    switch (iMessage) {
    case WM_CREATE:
        w1 = CreateWindow(TEXT("button"), TEXT("Draw Ellipse?"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 10, 10, 200, 25, hWnd, (HMENU)ID_DRAW, g_hInst, NULL);
        w2 = CreateWindow(TEXT("button"), TEXT("START"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 40, 80, 20, hWnd, (HMENU)ID_START, g_hInst, NULL);
        w3 = CreateWindow(TEXT("button"), TEXT("STOP"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 110, 40, 80, 20, hWnd, (HMENU)ID_STOP, g_hInst, NULL);
        w4 = CreateWindow(TEXT("button"), TEXT("END"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 210, 40, 80, 20, hWnd, (HMENU)ID_END, g_hInst, NULL);
        w5 = CreateWindow(TEXT("button"), TEXT("UP"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 70, 80, 20, hWnd, (HMENU)ID_UP, g_hInst, NULL);
        w6 = CreateWindow(TEXT("button"), TEXT("DOWN"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 110, 70, 80, 20, hWnd, (HMENU)ID_DOWN, g_hInst, NULL);
        GetClientRect(hWnd, &rt);
        pos.x = 300; 
        pos.y = 300;
        return 0;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_DRAW:
            InvalidateRgn(hWnd, NULL, TRUE);
            break;
        case ID_START:
            SetTimer(hWnd, 1, speed, NULL);
            break;
        case ID_STOP:
            KillTimer(hWnd, 1);
            break;
        case ID_END:
            SendMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        case ID_UP:
            if (HIWORD(wParam) == BN_CLICKED)
            {
                if (speed > 20)
                {
                    speed -= 20;
                    SetTimer(hWnd, 1, speed, NULL);
                }
            }
            break;
        case ID_DOWN:
            if (HIWORD(wParam) == BN_CLICKED)
            {
                if (speed <= 300)
                {
                    speed += 20;
                    SetTimer(hWnd, 1, speed, NULL);
                }
            }
            break;
        }
        SetFocus(hWnd);
        return 0;
    case WM_TIMER:
        
        if (pos.x + SIZE >= rt.right)
            pos.x = rt.left + SIZE;
        if (pos.y + SIZE >= rt.bottom)
            FLAGY = TRUE;
        else if (pos.y - SIZE <= rt.top + 100)
            FLAGY = FALSE;
       
        pos.x += Sx;
        if (!FLAGY)
            pos.y += Sy;
        else
            pos.y -= Sy;

        InvalidateRect(hWnd, NULL, TRUE);
        return 0;
    
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        if (SendMessage(w1, BM_GETCHECK, 0, 0))
            Ellipse(hdc, pos.x - SIZE, pos.y - SIZE, pos.x + SIZE, pos.y + SIZE);
        else
            Rectangle(hdc, pos.x - SIZE, pos.y - SIZE, pos.x + SIZE, pos.y + SIZE);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
