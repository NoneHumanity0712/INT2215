#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n];
    double sum = 0;
    double min = 10000;
    double max = -10000;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    cout << "Mean: " << sum/n << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    return 0;
}