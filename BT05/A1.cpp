#include <iostream>

using namespace std;

int main()
{
    int a[] = {1, 2, 3};
    char b[] = {'a', 'b', 'c'};

    cout << &a[0] << " " << &a[1] << " " << &a[2] << endl;
    cout << (void *)&b[0] << " " << (void *)&b[1] << " " << (void *)&b[2] << endl;

    // 0x61fe14 0x61fe18 0x61fe1c
    // 0x61fe11 0x61fe12 0x61fe13
}