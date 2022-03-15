#include <iostream>

using namespace std;

const int n = 3;
int a[n];
int M[n];

void check(int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;    
}

void duyet(int index, int a[], int M[])
{
    if (index >= n) check (a);
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (M[i] != 1)
            {
                a[index] = i + 1;
                M[i] = 1;
                duyet(index + 1, a, M);
                M[i] = 0;
            }
        }
        
    }
}

int main()
{
    duyet(0, a, M);
}