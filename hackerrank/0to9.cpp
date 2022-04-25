#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count[10];
    for (int i = 0; i < 10; i++) count[i] = 0;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        count[a[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << i << " : " << count[i] << endl;
    }

    return 0;
}