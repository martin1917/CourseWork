#pragma once

#include "Figure.h"

class Triangle : public Figure
{
public:
    Triangle(HWND hwnd, double x, double y, double a, bool view = 1, COLORREF color = RGB(0, 255, 0));
    virtual ~Triangle() {}

    virtual void hide();
    virtual void show();
    virtual void move(POINT point);

    virtual string getAttr() const;
    virtual double getA() const;

protected:
    double a;
    bool view;
};