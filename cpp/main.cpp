#include "Triangle.h"
#include "ComplexFigure.h"
#include "File.h"

Triangle *t = nullptr;
ComplexFigure *cf = nullptr;
Figure *figures[2];
POINT clickPoint;
File file;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (message == WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    else if (message == WM_LBUTTONDOWN)
    {
        clickPoint.x = LOWORD(lparam);
        clickPoint.y = HIWORD(lparam);
        figures[1]->move(clickPoint);
    }
    else if (message == WM_RBUTTONDOWN)
    {
        figures[1]->hide();
    }
    else
    {
        return DefWindowProc(hwnd, message, wparam, lparam);
    }

    return (LRESULT)0;
}

int main()
{
    WNDCLASSA wcl;
    memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.lpszClassName = "myWindow";
    wcl.lpfnWndProc = WndProc;
    RegisterClassA(&wcl);

    HWND hwnd = CreateWindow(
        "myWindow",
        "20VP1_15_LevinMaksim",
        WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX,
        10,
        10,
        800,
        600,
        nullptr,
        nullptr,
        nullptr,
        nullptr);

    t = new Triangle(hwnd, 100, 100, 100);
    cf = new ComplexFigure(hwnd, 500, 150, *t, RGB(90, 90, 90));
    figures[0] = t;
    figures[1] = cf;

    // file.save(figures[0]);
    // file.save(figures[1]);

    ShowWindow(hwnd, SW_SHOWNORMAL);
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        (figures[1]->*figures[1]->F_show)();
    }
    system("pause");
}