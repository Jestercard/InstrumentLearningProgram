#include <windows.h>
#include <stdlib.h>

#define FREEPLAY_BUTTON 1
#define CHALLENGE_BUTTON 2
#define OPTION_BUTTON 3
#define FREEPLAY_MAINMENU 4
#define CHALLENGE_MAINMENU 5
#define OPTION_MAINMENU 6


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void MainMenu_creation(HWND);
void MainMenu_deletion(HWND);
void FreePlay_creation(HWND);
void FreePlay_deletion(HWND);
void Challenge_creation(HWND);
void Challenge_deletion(HWND);
void Option_creation(HWND);
void Option_deletion(HWND);

HWND hFree, hChallenge, hOption, hMainMenu;
HMENU hMenu;

//variables to get center of window

int windowlength_x = 720;
int windowlength_y = 480;

int buttonlength_x = 100;
int buttonlength_y = 50;

int center_x = (windowlength_x / 2) - (buttonlength_x / 2);
int center_y = (windowlength_y / 2) - (buttonlength_y / 2);

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

    while( GetMessage(&msg, NULL, NULL, NULL ))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch ( msg)
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
        }
        break;
    case WM_CREATE:
        MainMenu_creation(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SIZE:
        MainMenu_creation(hWnd);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void MainMenu_creation(HWND hWnd)
{
    hFree = CreateWindowW(L"Button", L"Free Play", WS_VISIBLE | WS_CHILD, center_x, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)FREEPLAY_BUTTON, NULL, NULL);

    hChallenge = CreateWindowW(L"Button", L"Challenges", WS_VISIBLE | WS_CHILD, center_x, 200, buttonlength_x, buttonlength_y, hWnd, (HMENU)CHALLENGE_BUTTON, NULL, NULL);

    hOption = CreateWindowW(L"Button", L"Options", WS_VISIBLE | WS_CHILD, center_x, 260, buttonlength_x, buttonlength_y, hWnd, (HMENU)OPTION_BUTTON, NULL, NULL);
}

void MainMenu_deletion(HWND hWnd)
{
    DestroyWindow(hFree);
    DestroyWindow(hChallenge);
    DestroyWindow(hOption);
}

void FreePlay_creation(HWND hWnd)
{
    hMainMenu = CreateWindowW(L"Button", L"Main Menu", WS_VISIBLE | WS_CHILD, 100, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)FREEPLAY_MAINMENU, NULL, NULL);
}

void FreePlay_deletion(HWND hWnd)
{
    ;
}

void Option_creation(HWND hWnd)
{
    hMainMenu = CreateWindowW(L"Button", L"Main Menu", WS_VISIBLE | WS_CHILD, 100, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)FREEPLAY_MAINMENU, NULL, NULL);
}

void Option_deletion(HWND hWnd)
{
    ;
}

void Challenge_creation(HWND hWnd)
{
    hMainMenu = CreateWindowW(L"Button", L"Main Menu", WS_VISIBLE | WS_CHILD, 100, 140, buttonlength_x, buttonlength_y, hWnd, (HMENU)FREEPLAY_MAINMENU, NULL, NULL);
}

void Challenge_deletion(HWND hWnd)
{
    ;
}
