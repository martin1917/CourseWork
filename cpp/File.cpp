#include "File.h"

int File::n = 0;

void File::save(Figure *figure)
{
    string path = "test" + to_string(++n);
    save(figure, path);
}

void File::save(Figure *figure, string path)
{
    ofstream fout;
    fout.open(PATH + "\\" + path + ".txt");
    if (fout.is_open())
    {
        fout << figure->getAttr();
    }
    else
    {
        cout << "Can not open file" << endl;
    }
    fout.close();
}

Figure *File::create(HWND hwnd, string path)
{
    string attr[4];
    int i = 0;

    string line;
    ifstream in(PATH + "\\" + path + ".txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            attr[i++] = line;
        }
    }
    in.close();

    double x = stod(attr[0]);
    double y = stod(attr[1]);
    double a = stod(attr[2]);
    string className = attr[3];

    if (className == "Triangle")
        return new Triangle(hwnd, x, y, a);

    if (className == "ComplexFigure")
        return new ComplexFigure(hwnd, x, y, Triangle(hwnd, x, y, a * 0.5));
}