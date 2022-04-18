#include <iostream>

using namespace std;

struct String
{
    unsigned int n;
    char* str;
    String(const char* text)
    {
        unsigned int _n = 0;
        for (*str = *text; (*str) != '\0'; str++) _n++;
        n = _n;
        str = new char[n];
    }
    void print()
    {
        for (int i = 0; i<n; i++) cout << str[i];
    }

    ~String()
    {
        delete [] str;
    }
};


int main()
{
    String s("Hello");
}