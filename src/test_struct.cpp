#include <iostream>

using namespace std;

struct Vector
{
    double x;
    double y;

    Vector(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    Vector() {}

    void print()
    {
        cout << "vector(" << x << ", " << y << ")";
    }
};

Vector add(Vector v1, Vector v2)
{
    Vector sum;
    sum.x = v1.x + v2.x;
    sum.y = v1.y + v2.y;
    return sum;
}

int main()
{
    Vector a(1.0, 2.0);
    Vector b(1.5, 2.4);

    Vector sum = add (a, b);
    a.print();
    cout << " + ";
    b.print();
    cout << " = ";
    sum.print();

    // string s = "jksfd";
    // cout << s.length();

    return 0;
}