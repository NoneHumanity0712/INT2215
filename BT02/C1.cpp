//check prime

#include <iostream>

using namespace std;

bool check_prime(int n)
{
    if (n <= 1) return false;
    else if (n == 2 || n == 3) return true;
    else 
    {
        for (int i = 2; i <= n/2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    if (check_prime(n))
    {
        cout << "yes";
    } else cout << "no";
    return 0;
}