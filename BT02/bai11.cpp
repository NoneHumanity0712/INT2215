#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double min, max, step;
    cin >> min >> max >> step;
    double temp = min;
    while (temp <= max)
    {
        double temp_c = ((temp - 32)*5)/9;
        double temp_f = temp_c + 273.15;
        cout << fixed << setprecision(2) << temp << " " << temp_c << " " << temp_f << " " << endl;
        temp = temp + step;
    }
    return 0;
}