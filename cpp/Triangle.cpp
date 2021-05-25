#include "Triangle.h"

Triangle::Triangle(HWND hwnd, double x, double y, double a, bool view, COLORREF color)
    : Figure(hwnd)
{
    this->x = x;
    this->y = y;
    this->a = a;
    this->view = view;
    this->color = color;

    F_show = &Figure::show;
}

void Triangle::hide()
{
    POINT points[3];
    int k = view ? 1 : -1;

    points[0].x = x;
    points[0].y = y;

    points[1].x = (LONG)(x + 0.5 * a);
    points[1].y = (LONG)(y + k * 0.5 * sqrt(3) * a);

    points[2].x = (LONG)(x - 0.5 * a);
    points[2].y = (LONG)(y + k * 0.5 * sqrt(3) * a);

    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(this->dc, pen);
    SelectObject(this->dc, brush);
    Polygon(dc, points, 3);
    DeleteObject(pen);
    DeleteObject(brush);

    F_show = &Figure::hide;
}

void Triangle::show()
{
    int k = view ? 1 : -1;
    POINT points[3];
    RECT rt;
    GetClientRect(this->hwnd, &rt);

    try
    {
        points[0].x = x;
        points[0].y = y;
        if(view && 
            !((LONG)(0.5 * a) <= points[0].x &&  points[0].x <= (LONG)(rt.right - rt.left - 0.5 * a) &&
            (LONG)0 <= points[0].y && points[0].y <= (LONG)(rt.bottom - rt.top - 0.5 * sqrt(3) * a)))
        {
            throw points[0];
        }
                
        if(!view && 
            !((LONG)(0.5 * a) <= points[0].x && points[0].x <= (LONG)(rt.right - rt.left - 0.5 * a) &&
            (LONG)(0.5 * sqrt(3) * a) <= points[0].y && points[0].y <= (LONG)(rt.bottom - rt.top)))
        {
            throw points[0];
        }
            
        points[1].x = (LONG)(x + 0.5 * a);
        points[1].y = (LONG)(y + k * 0.5 * sqrt(3) * a);

        points[2].x = (LONG)(x - 0.5 * a);
        points[2].y = (LONG)(y + k * 0.5 * sqrt(3) * a);

        HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 128, 0));
        HBRUSH brush = CreateSolidBrush(color);
        SelectObject(this->dc, pen);
        SelectObject(this->dc, brush);
        Polygon(dc, points, 3);
        DeleteObject(pen);
        DeleteObject(brush);

        F_show = &Figure::show;
    }
    catch (POINT p)
    {
        cout << "[Triangle] - (" + to_string(p.x) + "," + to_string(p.y) + ")"<< endl;
    }
}

void Triangle::move(POINT point)
{
    hide();
    this->x = (double)point.x;
    this->y = (double)point.y;
    show();
}

string Triangle::getAttr() const
{
    return to_string(this->x) + "\n" +
           to_string(this->y) + "\n" +
           to_string(this->a) + "\n" +
           "Triangle";
}

double Triangle::getA() const
{
    return this->a;
}