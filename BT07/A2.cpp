#include <iostream>

using namespace std;

void f (int a[])
{
    cout << sizeof(a)/sizeof(a[0]) << endl; //2
}

int main()
{
    int a[] = {3, 1, 4, 1, 5, 9};
    cout << sizeof(a)/sizeof(a[0]) << endl; //6
    f(a);

    return 0;
}

//ra ket qua khac nhau
//neu de la void f (int *a) thi khong lco warning
/* Warning: 'sizeof' on array function parameter 'a' will return size of 
'int*' [-Wsizeof-array-argument] */