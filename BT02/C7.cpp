#include <iostream>

using namespace std;

int main()
{
    int a, temp;
    cin >> a;
    temp = a;
    cout << a << " ";
    while (temp > 0)
    {
        int b;
        cin >> b;
        if (b != temp) 
        {
            cout << b << " ";
            temp = b;
        }
    }
    return 0;
}