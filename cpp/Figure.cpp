#include "Figure.h"

Figure::Figure(HWND hwnd)
{
    this->hwnd = hwnd;
    this->dc = GetDC(this->hwnd);
}

Figure::~Figure()
{
    ReleaseDC(this->hwnd, this->dc);
}

double Figure::getX() const
{
    return this->x;
}

double Figure::getY() const
{
    return this->y;
}

COLORREF Figure::getColor() const
{
    return this->color;
}