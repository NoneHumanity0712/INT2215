#include <iostream>

using namespace std;

const int n = 4;
const int k = 3;
char a[k];
int M[k];

void check(char a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;    
}

void duyet(int index, char a[], int M[])
{
    if (index == k) check (a);
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (M[i] != 1)
            {
                a[index] = i + 'A';
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