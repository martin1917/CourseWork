#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

class Figure
{
public:
    Figure(HWND hwnd);
    virtual ~Figure();

    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void move(POINT point) = 0;

    double getX() const;
    double getY() const;
    COLORREF getColor() const;
    virtual double getA() const = 0;
    virtual string getAttr() const = 0;

    void (Figure::*F_show)();

protected:
    double x;
    double y;
    HWND hwnd;
    HDC dc;
    COLORREF color;
};