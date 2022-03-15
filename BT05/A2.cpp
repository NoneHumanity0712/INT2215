#include <iostream>

using namespace std;

int factorial(int n)
{
    cout << "n = " << n << " at " << &n << endl;
    if (n <= 1) return 1;
    else return n*factorial(n-1);
}

int main()
{
    int n = 6;
    int f = factorial(n);
    cout << "n! = " << f;

    /*
    n = 6 at 0x61fdf0 = 6422000
    n = 5 at 0x61fdc0 = 6421952
    n = 4 at 0x61fd90 = 6421904
    n = 3 at 0x61fd60
    n = 2 at 0x61fd30
    n = 1 at 0x61fd00
    n! = 720
    size = 48 byte;
    */
}