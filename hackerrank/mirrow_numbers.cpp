#include <iostream>
#include <string>

using namespace std;

bool check(int a)
{
    string s = to_string(a);
    int n = s.length();
    for (int i = 0; i <= n/2; i++)
    {
        if (s[i] != s[n-i-1]) return false;
    }
    return true;
}

int mirrow(int min, int max)
{
    int total = 0;
    for (int i = min; i <= max; i++)
    {
        if (check(i)) total++;
    }
    return total;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int mirrow_numbers = 0;
        int min, max;
        cin >> min >> max;
        mirrow_numbers += mirrow(min, max);
        cout << mirrow_numbers << endl;
    }
    return 0;
}