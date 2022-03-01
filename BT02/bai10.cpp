#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double T;
    cin >> T;
    cout << T << " ";
    double T_c = ((T-32)*5)/9;
    double T_k = T_c + 273.15;
    cout << "Fahrenheit" << " " << "Celsius" << "Absolute Value" << endl;
    cout << fixed << setprecision(2) << T_c << " " << T_k;
    return 0;
}