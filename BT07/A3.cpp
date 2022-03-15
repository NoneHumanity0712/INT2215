#include <iostream>

using namespace std;

int count_even(int* a, int n) 
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) count++;
    }
    return count;
}

int main()
{  
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int b[5], c[5];
    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i];
        c[i] = a[sizeof(a)/sizeof(a[0]) - i];
    }
    int b_even = count_even(b, 5);
    cout << b_even << endl;
    int c_even = count_even(c, 5);
    cout << c_even << endl;
    return 0;
}