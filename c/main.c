// Win32 Tutorial (Color Buttons - Owner Drawn)

// Alan Baylis 2004



#include <windows.h>

#include <stdio.h>

#include "resource.h"



const char ClassName[] = "MainWindowClass";

HWND hWndButton;



LRESULT CALLBACK WndProc( HWND    hWnd,

                          UINT    Msg,

                          WPARAM  wParam,          

                          LPARAM  lParam )

{

     switch (Msg)

     {

        case WM_CREATE:

        {

            hWndButton = CreateWindowEx(

            0,

            "BUTTON",

            NULL,

            WS_CHILD | BS_OWNERDRAW,

            10, 10,

            80, 20,

            hWnd,

            (HMENU)IDC_OWNERDRAWN,

            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),

            NULL);



            if(!hWndButton)

            {

                MessageBox(NULL, "Button Creation Failed.", "Error", MB_OK | MB_ICONERROR);

                return 0;

            }



            ShowWindow(hWndButton, SW_SHOW);

        }

        break;



        case WM_DRAWITEM:

        {

            switch ((UINT)wParam)

            {

                case IDC_OWNERDRAWN:

                {

                    LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT*)lParam;

                    SIZE size;

                    char text[256];

                    sprintf(text, "%s", "Test");

                    GetTextExtentPoint32(lpdis->hDC, text, strlen(text), &size);

                    SetTextColor(lpdis->hDC, RGB(0, 0, 0));

                    SetBkColor(lpdis->hDC, RGB(255, 255, 0));



                    ExtTextOut(lpdis->hDC,

                    ((lpdis->rcItem.right - lpdis->rcItem.left) - size.cx) / 2,

                    ((lpdis->rcItem.bottom - lpdis->rcItem.top) - size.cy) / 2,

                    ETO_OPAQUE | ETO_CLIPPED, &lpdis->rcItem, text, strlen(text), NULL);



                    DrawEdge(lpdis->hDC, &lpdis->rcItem,

                    (lpdis->itemState & ODS_SELECTED ?

                    EDGE_SUNKEN : EDGE_RAISED ), BF_RECT);

                

                    return TRUE;

                }

                break;

            }

        }

        break;



        case WM_COMMAND: 

        {

            switch(LOWORD(wParam))

            {

                case IDC_OWNERDRAWN:

                {

                    switch(HIWORD(wParam))

                    {

                        case BN_CLICKED:

                            MessageBox(NULL, "Selected Button", "Success", MB_OK | MB_ICONINFORMATION);

                        break; 

                    }

                }

                break;

            }

            return 0;

        } 

        break; 



        case WM_CLOSE:

            DestroyWindow(hWnd);

        break;



        case WM_DESTROY:

            PostQuitMessage(0);

        break;



        default:

            return (DefWindowProc(hWnd, Msg, wParam, lParam));

    }



    return 0;

}



INT WINAPI WinMain( HINSTANCE  hInstance,

                    HINSTANCE  hPrevInstance,

                    LPSTR      lpCmdLine,

                    INT        nCmdShow )

{

    WNDCLASSEX    wc;



    wc.cbSize           = sizeof(WNDCLASSEX);

    wc.style            = 0;

    wc.lpfnWndProc      = (WNDPROC)WndProc;

    wc.cbClsExtra       = 0;

    wc.cbWndExtra       = 0;

    wc.hInstance        = hInstance;

    wc.hIcon            = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

    wc.hIconSm          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);

    wc.hbrBackground    = (HBRUSH)(COLOR_WINDOW + 1);

    wc.lpszMenuName     = NULL;

    wc.lpszClassName    = ClassName;



    if (!RegisterClassEx(&wc))

    {

        MessageBox(NULL, "Failed To Register The Window Class.", "Error", MB_OK | MB_ICONERROR);

        return 0;

    }



    HWND    hWnd;



    hWnd = CreateWindowEx(

    WS_EX_CLIENTEDGE,

    ClassName,

    "Color Buttons",

    WS_OVERLAPPEDWINDOW,

    CW_USEDEFAULT,

    CW_USEDEFAULT,

    240,

    120,

    NULL,

    NULL,

    hInstance,

    NULL);



    if (!hWnd)

    {

        MessageBox(NULL, "Window Creation Failed.", "Error", MB_OK | MB_ICONERROR);

        return 0;

    }



    ShowWindow(hWnd, SW_SHOW);

    UpdateWindow(hWnd);



    MSG    Msg;



    while (GetMessage(&Msg, NULL, 0, 0))

    {

        TranslateMessage(&Msg);

        DispatchMessage(&Msg);

    }



    return Msg.wParam;

}