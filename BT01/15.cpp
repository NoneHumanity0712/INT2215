#include <iostream>
#include <string>
using namespace std;

string Fibonacci(int n)
{
    if (n == 0) return "a";
    else if (n == 1) return "b";
    else return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
    string s = Fibonacci(10);
    cout << s;
    return 0;
}