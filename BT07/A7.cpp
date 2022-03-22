#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[] = "abcabcd";
    char b[] = "abc";
    // getline(cin, a);
    // getline(cin, b);

    int k = 0;
    int count = 0;
    int m = sizeof(a) - 1;
    int n = sizeof(b) - 1;
    cout << m << " " << n << endl;

    while (k <= m - n)
    {
        char temp[m];
        for (int i = k; i < n + k; i++)
        {
            temp[i - k] = a[i];
        }
        cout << temp << endl;
        if (strcmp(temp, b) == 0) count++;
        k++;
    }
    cout << count;
    
    return 0;
}