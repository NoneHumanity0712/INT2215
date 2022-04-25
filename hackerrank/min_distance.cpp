#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<int> distance;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int d = abs(a[i] - a[j]);
            distance.insert(d);
        }
    }
    cout << distance.size();
    //cout << *distance.begin();
    return 0;
}