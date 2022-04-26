#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> s;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] + a[j] == 0) s.push_back(abs(a[i]));
        }
    }
    sort(s.begin(), s.end());
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << -(s[i]) << " " << (s[i]) << endl;
    }
    return 0;
}