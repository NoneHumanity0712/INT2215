#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) 
    {
        cout << "Thuoc day Fibonacci" << endl;
        cout << "1 1";
    }
    else 
    {
        vector<int> fibonacci;
        fibonacci.push_back(1);
        fibonacci.push_back(1);
        int i = 2;
        int f = fibonacci[i-1] + fibonacci[i-2];
        while (f <= n)
        {
            fibonacci.push_back(f);
            i++;
            f = fibonacci[(i-1)] + fibonacci[(i-2)];
        }
        if (n == fibonacci[(fibonacci.size() - 1)]) cout << "Thuoc day Fibonacci";
        else cout << "Khong thuoc day Fibonacci";
        cout << endl;
        for (int j = 0; j < fibonacci.size(); j++) cout << fibonacci[j] << " ";
    }
    return 0;
}