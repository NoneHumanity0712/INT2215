#include <iostream>

using namespace std;

void f(int xval)
{
   int x;
   x = xval;
   // in địa chỉ của x tại đây
   cout << &x << endl;
}

void g(int yval)
{
   int y;
   // in địa chỉ của y tại đây
   cout << &y << endl;
}

int main()
{
   f(7);
   g(11);
   return 0;
}

//dia chi 2 bien giong nhau: he dieu hanh da thu hoi
//o nho sau khi ham f ket thuc va cap phat luon cho
//ham g