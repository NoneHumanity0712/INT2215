//Nhập vào giá trị của 2 phân số, viết chương trình tính tổng 2 phân số ở dạng tối giản.
#include <iostream>
#include <cmath>
using namespace std;

struct fraction
{
    int numerator, denominator;
    fraction() {};
    fraction (int _numerator, int _denominator)
    {
        numerator = _numerator;
        denominator = _denominator;
    }
};

fraction add(fraction a, fraction b)
{
    fraction c(0, 0);
    c.numerator = a.numerator*b.denominator+b.numerator*a.denominator;
    c.denominator = a.denominator*b.denominator;
    return c;
}

int GreatestCommonDivisor(int m, int n)
{
    int gcm, min;
    m = abs(m);
    n = abs(n);
    if (m<n) min = m;
    else min = n;
    for (int i = 1 ; i <= min; i++)
        if (m%i==0&&n%i==0) gcm = i;
    return gcm;
}

void IrreducibleFraction (fraction x)
{
    if (x.numerator==0) cout << "0";
    else
    {
        int gcm;
        do
        {
            gcm = GreatestCommonDivisor(x.numerator, x.denominator);
            x.denominator = x.denominator/gcm;
            x.numerator = x.numerator/gcm;
            // cout << x.numerator << "/" << x.denominator;
        } while (gcm!=1);
        if (x.denominator<0 && x.numerator<0) 
            cout << abs(x.numerator) << "/" << abs(x.denominator);
        else 
        {
            if (x.denominator < 0 && x.numerator > 0) cout << "-";
            if (abs(x.denominator) == 1) cout << abs(x.numerator);
            else cout << abs(x.numerator) << "/" << abs(x.denominator);
        }
    }
}

int main() 
{
    int n;
    cin >> n;
    fraction sum(0, 1);
    for (int i = 0; i < n; i++)
    {
        fraction f;
        cin >> f.numerator >> f.denominator;
        sum = add(sum, f);
    }
    IrreducibleFraction(sum);
    return 0;
}