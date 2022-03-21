#include <iostream>

using namespace std;

struct Vector
{
    int x, y;
    Vector(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};


int main()
{
    Vector v (1, 2);
    cout << &v << endl;
    cout << &v.x << " " << &v.y << endl;
    //dia chi cua Vector v = dia chi cua v.x
    //6422040 - 6422044
    //dia chi cua v.y cach v.x 4 bytes
    return 0;
}