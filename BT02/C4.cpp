#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = -n + 1; j < n; j++)
        {
            if (abs(j) <= i) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}