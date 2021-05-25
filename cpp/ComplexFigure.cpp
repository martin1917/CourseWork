#include "ComplexFigure.h"

ComplexFigure::ComplexFigure(HWND hwnd, double x, double y, const Triangle &t, COLORREF color)
    : Figure(hwnd)
{
    this->x = x;
    this->y = y;
    this->a = t.getA() * 2;
    this->color = color;
    this->insideTriangle = new Triangle(
        hwnd,
        x,
        y + 0.5 * sqrt(3) * a,
        a * 0.5,
        false,
        t.getColor());

    F_show = &Figure::show;
}

void ComplexFigure::hide()
{
    POINT points[3];
    points[0].x = x;
    points[0].y = y;

    points[1].x = (LONG)(x + 0.5 * a);
    points[1].y = (LONG)(y + 0.5 * sqrt(3) * a);

    points[2].x = (LONG)(x - 0.5 * a);
    points[2].y = (LONG)(y + 0.5 * sqrt(3) * a);

    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(this->dc, pen);
    SelectObject(this->dc, brush);
    Polygon(dc, points, 3);
    DeleteObject(pen);
    DeleteObject(brush);

    insideTriangle->hide();

    F_show = &Figure::hide;
}

void ComplexFigure::show()
{
    POINT points[3];
    RECT rt;
    GetClientRect(this->hwnd, &rt);

    try
    {
        points[0].x = (LONG)x;
        points[0].y = (LONG)y;
        if (!((LONG)(0.5 * a) <= points[0].x && points[0].x <= (LONG)(rt.right - rt.left - 0.5 * a) &&
              (LONG)0 <= points[0].y && points[0].y <= (LONG)(rt.bottom - rt.top - 0.5 * sqrt(3) * a)))
        {
            throw points[0];
        } 

        points[1].x = (LONG)(x + 0.5 * a);
        points[1].y = (LONG)(y + 0.5 * sqrt(3) * a);

        points[2].x = (LONG)(x - 0.5 * a);
        points[2].y = (LONG)(y + 0.5 * sqrt(3) * a);

        HPEN pen = CreatePen(PS_SOLID, 2, RGB(100, 128, 256));
        HBRUSH brush = CreateSolidBrush(color);
        SelectObject(this->dc, pen);
        SelectObject(this->dc, brush);
        Polygon(dc, points, 3);
        DeleteObject(pen);
        DeleteObject(brush);

        insideTriangle->show();

        F_show = &Figure::show;
    }
    catch (POINT p)
    {
        cout << "[ComplexFigure] - (" + to_string(p.x) + "," + to_string(p.y) + ")"<< endl;
    }
}

void ComplexFigure::move(POINT point)
{
    hide();
    this->x = point.x;
    this->y = point.y;

    POINT p;
    p.x = point.x;
    p.y = point.y + 0.5 * sqrt(3) * a;
    insideTriangle->move(p);

    show();
}

string ComplexFigure::getAttr() const
{
    return to_string(this->x) + "\n" +
           to_string(this->y) + "\n" +
           to_string(this->a) + "\n" +
           "ComplexFigure";
}

double ComplexFigure::getA() const
{
    return this->a;
}

ComplexFigure::~ComplexFigure()
{
    delete this->insideTriangle;
}