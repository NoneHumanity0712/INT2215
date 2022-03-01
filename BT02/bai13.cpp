#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool check_prime (int n)
{
    for (int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
            break;
        } 
    }
    return true;
}

bool check_perfect (int n)
{
    int sum = 0;
    for (int i=1; i<n; i++)
    {
        if (n%i==0)
        {
            sum = sum+i;
        }
    }
    if (sum==n) return true;
    else return false;
}

bool check_square (int n)
{
    double a = sqrt(n);
    if (a == int(a)) return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prime;
    vector<int> perfect;
    vector<int> square;
    for (int i = 2; i <= n; i++)
    {
        if (check_prime(i)) prime.push_back(i);
        if (check_perfect(i)) perfect.push_back(i);
        if (check_square(i)) square.push_back(i);
    }
    for (int i=0; i<prime.size(); i++) cout << prime[i] << " ";
    cout << endl;
    for (int i=0; i<perfect.size(); i++) cout << perfect[i] << " ";
    cout << endl;
    for (int i=0; i<square.size(); i++) cout << square[i] << " ";
    cout << endl;
    return 0;
}