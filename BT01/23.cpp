#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int max = (x + y + abs(x-y) )/2;
    cout << max;
    return 0;
}