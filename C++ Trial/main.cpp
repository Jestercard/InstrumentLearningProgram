#include <windows.h>
#include <stdlib.h>
#include <commctrl.h>

#define FREEPLAY_BUTTON 1
#define CHALLENGE_BUTTON 2
#define OPTION_BUTTON 3
#define FREEPLAY_MAINMENU 4
#define CHALLENGE_MAINMENU 5
#define OPTION_MAINMENU 6
#define APPLY_CHANGE 7

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void MainMenu_creation(HWND);
void MainMenu_deletion(HWND);
void FreePlay_creation(HWND);
void FreePlay_deletion(HWND);
void Challenge_creation(HWND);
void Challenge_deletion(HWND);
void Option_creation(HWND);
void Option_deletion(HWND);
void ApplyChanges(HWND);

HWND hFree, hChallenge, hOption, hMainMenu,
hTitle, hChal_One, hChal_Two, hChal_Three,
hWindowSize, hWindowChange, WindowResolution, hTester;
HMENU hMenu;

//variables to get center of window
int windowlength_x = 720;
int windowlength_y = 480;

int buttonlength_x = 100;
int buttonlength_y = 50;
int buttoncenter_x = (windowlength_x / 2) - (buttonlength_x / 2);
int buttonleftside_x = (windowlength_x / 5);

int headerlength_x = 300;
int headerlength_y = 50;
int headercenter_x = (windowlength_x / 2) - (headerlength_x / 2);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR args, int nCmdShow)
{
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH) COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass", L"Flute Learning Program", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, windowlength_x, windowlength_y,
                  NULL, NULL, NULL, NULL);
    MSG msg = {0};

    while( GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_COMMAND:

        switch(wp)
        {
        case FREEPLAY_BUTTON:
            MainMenu_deletion(hWnd);
            FreePlay_creation(hWnd);
            break;
        case CHALLENGE_BUTTON:
            MainMenu_deletion(hWnd);
            Challenge_creation(hWnd);
            break;
        case OPTION_BUTTON:
            MainMenu_deletion(hWnd);
            Option_creation(hWnd);
            break;
        case FREEPLAY_MAINMENU:
            FreePlay_deletion(hWnd);
            MainMenu_creation(hWnd);
            break;
        case CHALLENGE_MAINMENU:
            Challenge_deletion(hWnd);
            MainMenu_creation(hWnd);
            break;
        case OPTION_MAINMENU:
            Option_deletion(hWnd);
            MainMenu_creation(hWnd);
            break;
        case APPLY_CHANGE:
            ApplyChanges(hWnd);
            break;
        }
        break;
    case WM_CREATE:
        MainMenu_creation(hWnd);
        hTitle = CreateWindowW(L"static", L"Flute Learning Program", WS_VISIBLE | WS_CHILD | DT_CENTER, headercenter_x, 50, headerlength_x, headerlength_y, hWnd, NULL, NULL, NULL);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void MainMenu_creation(HWND hWnd)
{
    SetWindowText(hTitle, "Flute Learning Program");
    hFree = CreateWindowW(L"Button", L"Free Play", WS_VISIBLE | WS_CHILD, buttoncenter_x, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)FREEPLAY_BUTTON, NULL, NULL);
    hChallenge = CreateWindowW(L"Button", L"Challenges", WS_VISIBLE | WS_CHILD, buttoncenter_x, 200, buttonlength_x, buttonlength_y, hWnd, (HMENU)CHALLENGE_BUTTON, NULL, NULL);
    hOption = CreateWindowW(L"Button", L"Options", WS_VISIBLE | WS_CHILD, buttoncenter_x, 260, buttonlength_x, buttonlength_y, hWnd, (HMENU)OPTION_BUTTON, NULL, NULL);
}

void MainMenu_deletion(HWND hWnd)
{
    DestroyWindow(hFree);
    DestroyWindow(hChallenge);
    DestroyWindow(hOption);
}

void FreePlay_creation(HWND hWnd)
{
    SetWindowText(hTitle, "Free Play Mode");
    hMainMenu = CreateWindowW(L"Button", L"Main Menu", WS_VISIBLE | WS_CHILD, 100, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)FREEPLAY_MAINMENU, NULL, NULL);
}

void FreePlay_deletion(HWND hWnd)
{
    DestroyWindow(hMainMenu);
}

void Challenge_creation(HWND hWnd)
{
    SetWindowText(hTitle, "Select Your Challenge");
    hMainMenu = CreateWindowW(L"Button", L"Main Menu", WS_VISIBLE | WS_CHILD, 100, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)CHALLENGE_MAINMENU, NULL, NULL);
    hChal_One = CreateWindowW(L"Button", L"Rhythm", WS_VISIBLE | WS_CHILD, buttoncenter_x, 140, buttonlength_x, buttonlength_y, hWnd, NULL, NULL, NULL);
    hChal_Two = CreateWindowW(L"Button", L"Play Along", WS_VISIBLE | WS_CHILD, buttoncenter_x, 200, buttonlength_x, buttonlength_y, hWnd, NULL, NULL, NULL);
    hChal_Three = CreateWindowW(L"Button", L"Pattern Match", WS_VISIBLE | WS_CHILD, buttoncenter_x, 260, buttonlength_x, buttonlength_y, hWnd, NULL, NULL, NULL);
}

void Challenge_deletion(HWND hWnd)
{
    DestroyWindow(hMainMenu);
    DestroyWindow(hChal_One);
    DestroyWindow(hChal_Two);
    DestroyWindow(hChal_Three);
}

void Option_creation(HWND hWnd)
{
    SetWindowText(hTitle, "Options");
    hMainMenu = CreateWindowW(L"Button", L"Main Menu", WS_VISIBLE | WS_CHILD, 100, buttonleftside_x, buttonlength_x, buttonlength_y, hWnd, (HMENU)OPTION_MAINMENU, NULL, NULL);
    hWindowChange = CreateWindowW(L"Button", L"Apply", WS_VISIBLE | WS_CHILD, 100, 260, buttonlength_x, buttonlength_y, hWnd, (HMENU)APPLY_CHANGE, NULL, NULL);

    hWindowSize = CreateWindow(WC_COMBOBOX, TEXT("Window Size"), CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
                                250, 140, buttonlength_x, buttonlength_y+100, hWnd, NULL, NULL, NULL);
    char WindowSizeOptions[4][20] = {"480x360","720x480","1280x720","1920x1080"};
    for (int i=0; i<4; i++)
    {
        SendMessage(hWindowSize,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) WindowSizeOptions[i]);
    }
    SendMessage(hWindowSize, CB_SETCURSEL, (WPARAM)1, (LPARAM)0);
}

void ApplyChanges(HWND hWnd)
{
    int WindowResolution;
    WindowResolution = SendMessage(hWindowSize, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
    switch (WindowResolution)
    {
    case 0:
        windowlength_x = 480;
        windowlength_y = 360;
        break;
    case 1:
        windowlength_x = 720;
        windowlength_y = 480;
        break;
    case 2:
        windowlength_x = 1280;
        windowlength_y = 720;
        break;
    case 3:
        windowlength_x = 1980;
        windowlength_y = 1080;
        break;
    }
    SetWindowPos(hWnd, NULL, 0, 0, windowlength_x, windowlength_y, SWP_NOMOVE);
}

void Option_deletion(HWND hWnd)
{
    DestroyWindow(hMainMenu);
    DestroyWindow(hWindowSize);
    DestroyWindow(hWindowChange);
}

