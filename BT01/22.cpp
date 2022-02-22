#include <iostream>

using namespace std;

int main()
{
    double mass, height;
    cin >> mass >> height;
    double bmi = mass/(height*height);
    cout << bmi << endl;
    return 0;
}