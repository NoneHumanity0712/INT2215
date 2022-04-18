#include <iostream>

using namespace std;

struct String
{
    unsigned int n = 0;
    char* str;
    String(const char* text)
    {
        for (char *p = text; (*p) != '\0'; p++) n++;
        str = new char[n];
        for (int i = 0; i < n; i++)
        {
            str[i] = text[i];
        }
    }
    void print()
    {
        for (int i = 0; i<n; i++) cout << *(str+i);
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