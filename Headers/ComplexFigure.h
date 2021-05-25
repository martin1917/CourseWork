#pragma once

#include "Triangle.h"

class ComplexFigure : public Figure
{
public:
    ComplexFigure(HWND hwnd, double x, double y, const Triangle &t, COLORREF color = RGB(0, 255, 255));
    virtual ~ComplexFigure();

    virtual void hide();
    virtual void show();
    virtual void move(POINT point);

    virtual string getAttr() const;
    virtual double getA() const;

protected:
    double a;
    Triangle *insideTriangle;
};