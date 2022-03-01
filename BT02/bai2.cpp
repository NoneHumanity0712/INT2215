#include <iostream>

using namespace std;

int main()
{
    double x;
    int y;
    cin >> x >> y;
    double power = 1;
    for (int i = 1; i <= y; i++)
    {
        power *= x;
    }
    cout << power;
    return 0;
}