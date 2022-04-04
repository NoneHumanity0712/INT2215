#include <iostream>

using namespace std;

char* reverse(char a[])
{
    int n = 0;
    for (char* p = a; (*p) != '\0'; p++) n++;
    cout << n << endl;
    char temp[n];
    char *p;
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[n-i-1]; 
    }
    return temp;
}

int main()
{
    char a[] = "abcde";
    char* a_reverse = reverse(a);
}