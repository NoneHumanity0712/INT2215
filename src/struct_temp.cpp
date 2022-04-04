#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;

    Point() {};

    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
        cout << "Point (" << x << "; " << y << ")" << endl;
    }
};

struct Triangle
{
    Point a;
    Point b;
    Point c;

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        :a(x1, y1), b(x2, y2), c(x3, y3)
    {
        cout << "Triangle 6 params ()" << endl;
    }
    Triangle()
    {
        cout << "Triangle() " << endl;
    }
};

int main()
{
    Triangle t;
    Point p;
    return 0;
}
