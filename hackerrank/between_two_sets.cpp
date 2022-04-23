/*
There will be two arrays of integers. Determine all integers that satisfy the following two conditions:
1. The elements of the first array are all factors of the integer being considered
2. The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. 
Determine how many such numbers exist.

Input Format

The first line contains two space-separated integers, m and n, 
the number of elements in arrays a and b.
The second line contains n distinct space-separated integers a[i] where 0 <= i < n.
The third line contains  distinct space-separated integers m where 0 <= j < m.

Sample Input:
2 3
2 4
16 32 96

Sample Output:
3

Explanation
2 and 4 divide evenly into 4, 8, 12 and 16.
4, 8 and 16 divide evenly into 16, 32, 96.
4, 8 and 16 are the only three numbers for which each element of a is a factor 
and each is a factor of all elements of b.
*/
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