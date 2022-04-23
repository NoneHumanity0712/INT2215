#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

set<int> AllDivisors(vector<int> arr)
{
    int N = arr.size();
    // Variable to find the gcd
    // of N numbers
    int g = arr[0];
 
    // Set to store all the
    // common divisors
    set<int> divisors;
 
    // Finding GCD of the given
    // N numbers
    for (int i = 1; i < N; i++) {
        g = gcd(arr[i], g);
    }
 
    // Finding divisors of the
    // HCF of n numbers
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            divisors.insert(i);
            if (g / i != i)
                divisors.insert(g / i);
        }
    }
    
    // Print all the divisors
    // for (auto& it : divisors)
    //     cout << it << " ";
    
    return divisors;
}

int getTotalX(vector<int> a, vector<int> b) 
{
    int count = 0;
    set<int> factors = AllDivisors(b);
    for (set<int>::iterator itr = factors.begin(); itr != factors.end(); itr++)
    {
        bool check = true;
        for (int j = 0; j < a.size(); j++)
        {
            if (*itr % a[j] != 0)
            {
                check = false;
                break;
            }
        }
        if (check) 
        {
            count++;
            //cout << *itr << " " << count << endl;
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    cout << getTotalX(a, b) << endl;
    return 0;
}