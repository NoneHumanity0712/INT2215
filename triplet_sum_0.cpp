#include <bits/stdc++.h>
using namespace std;

void findTriplets(int arr[], int n)
{

    bool found = false;
 

    for (int i=0; i<n-1; i++)

    {

        // Find all pairs with sum equals to

        // "-arr[i]"

        unordered_set<int> s;

        for (int j=i+1; j<n; j++)

        {

            int x = -(arr[i] + arr[j]);

            if (s.find(x) != s.end())

            {

                printf("%d %d %d\n", x, arr[i], arr[j]);

                found = true;

            }

            else

                s.insert(arr[j]);

        }

    }
 

    if (found == false)

        cout << " No Triplet Found" << endl;
}

int main()
{
    int n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s;
    for (int i = 0; )
}