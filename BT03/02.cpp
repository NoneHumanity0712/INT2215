#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.length()/2;
    bool check = false;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == s[s.length() - 1 - i]) check = true;
        else
        {
            check = false;
            break;
        }
    }
    if (check == true) cout << "yes";
    else cout << "no";
    return 0;
}