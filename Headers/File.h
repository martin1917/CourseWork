#pragma once

#include <string>
#include <fstream>
#include "Triangle.h"
#include "ComplexFigure.h"

const string PATH = "store_figure";

class File
{
public:
    File(){};
    void save(Figure *figure);
    void save(Figure *figure, string path);
    Figure *create(HWND hwnd, string path);

private:
    static int n;
};