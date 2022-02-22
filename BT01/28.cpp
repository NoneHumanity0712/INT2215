#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int i = -12; i < 12; i++)
    {
        if (i == -12) cout << "12 midnight" << endl;
        else if (i < 0) cout << abs(i) << "am" << endl;
        else if (i == 0) cout << "12 noon" << endl;
        else if (i > 0) cout << i << "pm" << endl;
    }
    return 0;
}